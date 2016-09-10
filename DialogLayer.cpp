#include "DialogLayer.h"
#include "bearStartLayer.h"
using namespace cocos2d;
using namespace std;
//初始化方法
bool DialogLayer::init()
{
	//初始化显示暂停界面的标志位为false
	bool bRet = false;
	do {
		//设置屏幕的透明度
		CC_BREAK_IF(!LayerColor::initWithColor(ccc4(0, 0, 0, 160),800,480));
		//调用initDialog方法
		this->initDialog();
		//将标志位设为true
		bRet = true;
	}
	//判断
	while (0);

	return bRet;
}

void DialogLayer::initDialog()
{
	
	//创建一个精灵对象，包含暂停游戏字样，充当背景
	Sprite* plabel = Sprite::create("pause/plabel.png");
	//设置精灵对象的位置
	plabel->setPosition(Point(105, 240));
	//将背景精灵添加到布景中
	this->addChild(plabel, 1);

	

	//创建继续游戏的菜单按钮
	MenuItemImage *resume = MenuItemImage::create
	(
		 "pause/resume.png", 		//平时的图片
		 "pause/resume3.png",  	//选中时的图片
		 //点击菜单按钮时执行的回调方法
		 CC_CALLBACK_1(DialogLayer::menuCallbackContinueGame,this)
	);
	//设置继续游戏菜单按钮的位置
	resume->setPosition(Point(250,240));

	
	//创建回主菜单的精灵
	MenuItemImage *saveExit = MenuItemImage::create
	(
		"pause/exit.png", 		//平时的图片
		"pause/exit3.png",  	//选中时的图片
		//点击时执行的回调方法
		CC_CALLBACK_1(DialogLayer::homeSence,this)
	);
	//设置退出菜单按钮的位置
	saveExit->setPosition(Point(550,240));

	//创建菜单对象
	m_pMenu = Menu::create(resume,saveExit, NULL);
	//设置菜单位置
	m_pMenu->setPosition(Point(0,0));
	//将菜单按钮添加到布景中
	this->addChild(m_pMenu, 3);
}

//去主菜单场景的回调方法
void DialogLayer::homeSence(Object* pSender)
{
	
	//把sprite从屏幕上删除，并把它执行的动作也删除
	this->removeFromParentAndCleanup(true);
	//获取Director（导演）
	Director* pDirector = Director::getInstance();
	//先切换到继续场景
	pDirector->resume();
	//再切换到主菜单布景
	pDirector->replaceScene(BeginScene::createScene());
}


//继续游戏的回调方法
void DialogLayer::menuCallbackContinueGame(Object *pSender)
{
	
	//把sprite从屏幕上删除，并把它执行的动作也删除
	this->removeFromParentAndCleanup(true);
	//获取CCDirector（导演）
	Director* director = Director::getInstance();
	//切换到继续游戏场景
	director->resume();
	
}

