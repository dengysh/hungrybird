#include "bearStartLayer.h"
#include "gameLayer.h"
#include "HelpLayer.h"
#include"SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
Scene* BeginScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object,call init();
	auto layer = BeginScene::create();

	// add layer as a child to scene
	scene->addChild(layer);
	//scene->getChildByTag();
	// return the scene
	return scene;
}
bool BeginScene::init()
{
	//  super init first
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("Hungry Bear", "fonts/Marker Felt.ttf", 24);
	label->setRotation(-90);
	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + 30,
		240));

	// add the label as a child to this layer
	this->addChild(label, 3);

	///////////////////////////////
	////  add a menu item with "X" image, which is clicked to quit the program
	////    you may modify it.

	//// add a "close" icon to exit the progress. it's an autorelease object
	//auto closeItem = MenuItemImage::create(
	//	"CloseNormal.png",
	//	"CloseSelected.png",
	//	CC_CALLBACK_1(BeginScene::menuCloseCallback, this));

	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
	//	origin.y + closeItem->getContentSize().height/2));

	//// create menu, it's an autorelease object
	//auto menu = Menu::create(closeItem, NULL);
	//menu->setPosition(Vec2::ZERO);
	//this->addChild(menu, 1);

	///////////////////////////////
	//// 3. add a START label 
	//auto startlabel=Label::createWithTTF("START","fonts/Marker Felt.ttf",20);
	//auto startmenuitem=MenuItemLabel::create(startlabel,CC_CALLBACK_1(BeginScene::menustartCallback, this));
	//auto testmenu=Menu::create(startmenuitem,NULL);
	//testmenu->setPosition(Vec2(origin.x + visibleSize.width/2,origin.y+visibleSize.height/2));
	//this->addChild(testmenu,3);

	//加载音效
	SimpleAudioEngine::getInstance()->preloadEffect
	(
		"sound/sf_button_press.mp3"
	);
	
	//创建“开始游戏”精灵
	MenuItemImage *onePlayer = MenuItemImage::create
	(
		"begin/onePlayer.png",		//平时的图片
		"begin/onePlayer3.png",	//选中时的图片
		CC_CALLBACK_1(BeginScene::menustartCallback, this)
	);
	//设置精灵菜单按钮的位置
	onePlayer->setPosition(Point(270,240));

	//创建“退出”精灵
	MenuItemImage *twoPlayer = MenuItemImage::create
	(
		"begin/exit.png",		//平时的图片
		"begin/exit.png",   	//选中时的图片
		CC_CALLBACK_1(BeginScene::menuCloseCallback, this)
	);
	//设置菜单按钮的位置
	twoPlayer->setPosition(Point(660,240));

	//创建“最高分”的精灵
	MenuItemImage *set = MenuItemImage::create
	(
		"begin/seclect.png",	//平时的图片
		"begin/seclect3.png",   //选中时的图片
		CC_CALLBACK_1(BeginScene::menurankCallback, this)
	 );
	//设置最高分菜单按钮的位置
	set->setPosition(Point(530,240));

	//创建”帮助“精灵
	MenuItemImage *help = MenuItemImage::create
	(
		"begin/help.png",		//平时的图片
		"begin/help3.png",		//选中时的图
		CC_CALLBACK_1(BeginScene::menuhelpCallback, this)
	);
	//设置帮助菜单按钮的位置
	help->setPosition(Point(400,240));

	//创建主菜单中的4个菜单对象
	auto pMenu = Menu::create(onePlayer,twoPlayer,set,help,NULL);
	//设置菜单的位置
	pMenu->setPosition(Point(0,0));
	//将菜单添加到布景中
	this->addChild(pMenu,3);
	return true;
}
void BeginScene::menuCloseCallback(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void BeginScene::menustartCallback(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	Director::getInstance()->replaceScene(gameLayer::createScene());

}
void BeginScene::menuhelpCallback(cocos2d::Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");
	auto ccts=TransitionFadeTR::create(1.0f,HelpLayer::createScene());
	Director::getInstance()->replaceScene(ccts);
}
void BeginScene::menurankCallback(cocos2d::Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect("sound/sf_button_press.mp3");

}