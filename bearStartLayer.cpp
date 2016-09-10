#include "bearStartLayer.h"
#include "gameLayer.h"
USING_NS_CC;

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

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	/////////////////////////////
	//  add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(BeginScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
		origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add a START label 
	auto startlabel=Label::createWithTTF("START","fonts/Marker Felt.ttf",20);
	auto startmenuitem=MenuItemLabel::create(startlabel,CC_CALLBACK_1(BeginScene::menustartCallback, this));
	auto testmenu=Menu::create(startmenuitem,NULL);
	testmenu->setPosition(Vec2(origin.x + visibleSize.width/2,origin.y+visibleSize.height/2));
	this->addChild(testmenu,3);


	return true;
}
void BeginScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void BeginScene::menustartCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(gameLayer::createScene());

}