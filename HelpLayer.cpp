#include "HelpLayer.h"
#include "bearStartLayer.h"
#include "cocos2d.h"
#include"SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
using namespace std;

Scene* HelpLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	// 'layer' is an autorelease object,call init();
	auto layer = HelpLayer::create();
	// add layer as a child to scene
	scene->addChild(layer);
	return scene;
}

//ʵ��HelpLayer���е�init��������ʼ������
bool HelpLayer::init()
{
	//���ø���ĳ�ʼ��
	if ( !Layer::init() )
	{
		return false;
	}
	currPicIndex=0;

	//��ȡ�ɼ�����ߴ�
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	//��ȡ�ɼ�����ԭ������
	Point origin = Director::sharedDirector()->getVisibleOrigin();

	//������Ч
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect
	(
		"sound/sf_button_press.mp3"
	);

	

	//��������һ������ͼƬ������
	MenuItemImage *leftItem = MenuItemImage::create
	(
		"help/left_up.png",
		"help/left_down.png",
		CC_CALLBACK_1(HelpLayer::menuCallBack0, this)
	);
	leftItem->setScale(1.5);
	//���þ���˵���ť��λ��
	leftItem->setPosition(Point(330,450));

	//��������һ������ͼƬ������
	MenuItemImage *rightItem = MenuItemImage::create
	(
		"help/right_up.png",
		"help/right_down.png",
		CC_CALLBACK_1(HelpLayer::menuCallBack1, this)
	);
	rightItem->setScale(1.5);
	//���þ���˵���ť��λ��.
	rightItem->setPosition(Point(330,30));

	//���������ء�����
	MenuItemImage *fanhuiItem = MenuItemImage::create
	(
		"help/fanhui.png",
		"help/fanhui.png",
		CC_CALLBACK_1(HelpLayer::menuCallBack2, this)
	);
	//���þ���˵���ť��λ��.
	fanhuiItem->setPosition(Point(40,420));

	auto pMenu = Menu::create(leftItem,rightItem,fanhuiItem,NULL);
	//���ò˵���λ��
	pMenu->setPosition(Point(0,0));
	//���˵���ӵ�������
	this->addChild(pMenu,3);
	initIntroPic();
	return true;
}
void HelpLayer::initIntroPic()
{
	for(int i = 0;i<9;i++)
	{
		//ͨ��createHelp��ȡ��ӦͼƬ��·��
		help[i] = Sprite::create(StringUtils::format("help/help%d.png",i));
		help[i]->setPosition(Point(440,245+i*480));
		this->addChild(help[i],3);
	}
}

//���Ҽ�ͷ
void HelpLayer::menuCallBack0(Object* pSende)
{
	//���ű�������
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
	(
		"sound/sf_button_press.mp3"
	);
	for(int i= 0 ;i<9;i++)
	{
		help[i] ->setPosition(Point(400,-480));
	}
	currPicIndex ++;
	if(currPicIndex == 9)
	{
		currPicIndex = 0;
	}
	help[currPicIndex%9] ->setPosition(Point(440,245));
}

//�����ͷ
void HelpLayer::menuCallBack1(Object* pSende)
{
	//���ű�������
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic
	(
		"sound/sf_button_press.mp3"
	);
	for(int i= 0 ;i<9;i++)
	{
		help[i] ->setPosition(Point(400,-480));
	}
	currPicIndex --;
	if(currPicIndex == -1)
	{
		currPicIndex = 8;
	}
	help[currPicIndex%9] ->setPosition(Point(440,245));
}

//�������˵�
void HelpLayer::menuCallBack2(Ref* pSende)
{
	//������Ч
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	//����������
	auto ccts=TransitionFadeTR::create(1.0f,BeginScene::createScene());
	Director::getInstance()->replaceScene(ccts);
}