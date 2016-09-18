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

	//������Ч
	SimpleAudioEngine::getInstance()->preloadEffect
	(
		"sound/sf_button_press.mp3"
	);
	
	//��������ʼ��Ϸ������
	MenuItemImage *onePlayer = MenuItemImage::create
	(
		"begin/onePlayer.png",		//ƽʱ��ͼƬ
		"begin/onePlayer3.png",	//ѡ��ʱ��ͼƬ
		CC_CALLBACK_1(BeginScene::menustartCallback, this)
	);
	//���þ���˵���ť��λ��
	onePlayer->setPosition(Point(270,240));

	//�������˳�������
	MenuItemImage *twoPlayer = MenuItemImage::create
	(
		"begin/exit.png",		//ƽʱ��ͼƬ
		"begin/exit.png",   	//ѡ��ʱ��ͼƬ
		CC_CALLBACK_1(BeginScene::menuCloseCallback, this)
	);
	//���ò˵���ť��λ��
	twoPlayer->setPosition(Point(660,240));

	//��������߷֡��ľ���
	MenuItemImage *set = MenuItemImage::create
	(
		"begin/seclect.png",	//ƽʱ��ͼƬ
		"begin/seclect3.png",   //ѡ��ʱ��ͼƬ
		CC_CALLBACK_1(BeginScene::menurankCallback, this)
	 );
	//������߷ֲ˵���ť��λ��
	set->setPosition(Point(530,240));

	//����������������
	MenuItemImage *help = MenuItemImage::create
	(
		"begin/help.png",		//ƽʱ��ͼƬ
		"begin/help3.png",		//ѡ��ʱ��ͼ
		CC_CALLBACK_1(BeginScene::menuhelpCallback, this)
	);
	//���ð����˵���ť��λ��
	help->setPosition(Point(400,240));

	//�������˵��е�4���˵�����
	auto pMenu = Menu::create(onePlayer,twoPlayer,set,help,NULL);
	//���ò˵���λ��
	pMenu->setPosition(Point(0,0));
	//���˵���ӵ�������
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