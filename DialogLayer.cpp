#include "DialogLayer.h"
#include "bearStartLayer.h"
using namespace cocos2d;
using namespace std;
//��ʼ������
bool DialogLayer::init()
{
	//��ʼ����ʾ��ͣ����ı�־λΪfalse
	bool bRet = false;
	do {
		//������Ļ��͸����
		CC_BREAK_IF(!LayerColor::initWithColor(ccc4(0, 0, 0, 160),800,480));
		//����initDialog����
		this->initDialog();
		//����־λ��Ϊtrue
		bRet = true;
	}
	//�ж�
	while (0);

	return bRet;
}

void DialogLayer::initDialog()
{
	
	//����һ��������󣬰�����ͣ��Ϸ�������䵱����
	Sprite* plabel = Sprite::create("pause/plabel.png");
	//���þ�������λ��
	plabel->setPosition(Point(105, 240));
	//������������ӵ�������
	this->addChild(plabel, 1);

	

	//����������Ϸ�Ĳ˵���ť
	MenuItemImage *resume = MenuItemImage::create
	(
		 "pause/resume.png", 		//ƽʱ��ͼƬ
		 "pause/resume3.png",  	//ѡ��ʱ��ͼƬ
		 //����˵���ťʱִ�еĻص�����
		 CC_CALLBACK_1(DialogLayer::menuCallbackContinueGame,this)
	);
	//���ü�����Ϸ�˵���ť��λ��
	resume->setPosition(Point(250,240));

	
	//���������˵��ľ���
	MenuItemImage *saveExit = MenuItemImage::create
	(
		"pause/exit.png", 		//ƽʱ��ͼƬ
		"pause/exit3.png",  	//ѡ��ʱ��ͼƬ
		//���ʱִ�еĻص�����
		CC_CALLBACK_1(DialogLayer::homeSence,this)
	);
	//�����˳��˵���ť��λ��
	saveExit->setPosition(Point(550,240));

	//�����˵�����
	m_pMenu = Menu::create(resume,saveExit, NULL);
	//���ò˵�λ��
	m_pMenu->setPosition(Point(0,0));
	//���˵���ť��ӵ�������
	this->addChild(m_pMenu, 3);
}

//ȥ���˵������Ļص�����
void DialogLayer::homeSence(Object* pSender)
{
	
	//��sprite����Ļ��ɾ����������ִ�еĶ���Ҳɾ��
	this->removeFromParentAndCleanup(true);
	//��ȡDirector�����ݣ�
	Director* pDirector = Director::getInstance();
	//���л�����������
	pDirector->resume();
	//���л������˵�����
	pDirector->replaceScene(BeginScene::createScene());
}


//������Ϸ�Ļص�����
void DialogLayer::menuCallbackContinueGame(Object *pSender)
{
	
	//��sprite����Ļ��ɾ����������ִ�еĶ���Ҳɾ��
	this->removeFromParentAndCleanup(true);
	//��ȡCCDirector�����ݣ�
	Director* director = Director::getInstance();
	//�л���������Ϸ����
	director->resume();
	
}

