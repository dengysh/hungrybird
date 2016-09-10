#include "gameLayer.h"
#include "DialogLayer.h"
USING_NS_CC;
using namespace std;
Scene* gameLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = gameLayer::create();
	scene->addChild(layer);
	return scene;
}
bool gameLayer::init()
{
	if(!Layer::init())
		return false;

	score=0;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bear=Sprite::create("bear.jpg");
	bear->setPosition(Vec2(origin.x +visibleSize.width- bear->getContentSize().width/2,
		origin.y + visibleSize.height/2));
	this->addChild(bear,1);
	bear->setTag(1000);

	//创建“暂停”按钮精灵
	MenuItemImage *zanTingItem = MenuItemImage::create
	(
		"zanting.png",		//平时的图片
		"zanting.png",		//选中时的图
		CC_CALLBACK_1(gameLayer::zanting, this)
	);
	//设置暂停菜单按钮的位置
	zanTingItem->setPosition(Point(40,140));

	//创建暂停菜单对象
	auto pMenu = Menu::create(zanTingItem,NULL);
	//设置菜单的位置
	 pMenu->setPosition(Point(0,0));
	//将菜单添加到布景中
	this->addChild(pMenu,3);

	//创建一个tempScore文本标签（临时分数）
	scoreL = LabelTTF::create("0", "Arial",28);
	//创建一个特效并播放
	ActionInterval *act= RotateBy::create(1,-90);
	scoreL->runAction(act);
	//设置标签字体的颜色
	scoreL->setColor (ccc3(255,255,255));
	//设置文本标签的位置
	scoreL->setPosition(Point(40,240));
	//将文本标签添加到布景中
	this->addChild(scoreL,3);

	// touch
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesEnded = CC_CALLBACK_2(gameLayer::onTouchesEnded, this);
	listener->onTouchesBegan = CC_CALLBACK_2(gameLayer::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(gameLayer::onTouchesMoved, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// fish
	fish = new Fish();
	this->addChild(fish);

	// update 
	scheduleUpdate();
	return true;
}

void gameLayer::onTouchesEnded(const vector<cocos2d::Touch*>& touches,cocos2d:: Event* event)
{

}
void gameLayer::onTouchesBegan(const vector<cocos2d::Touch*>& touches,cocos2d:: Event* event)
{
	Touch* touch = touches[0];
	auto location = touch->getLocation();
	 auto sp=(Sprite*)this->getChildByTag(1000);
	 if(sp->getBoundingBox().containsPoint(location))
	 {
		 cocos2d::log("bear click");
	 }
}
void gameLayer::onTouchesMoved(const vector<cocos2d::Touch*>& touches,cocos2d:: Event* event)
{
	Touch* touch = touches[0];
	auto location = touch->getLocation();
	 auto sp=(Sprite*)this->getChildByTag(1000);
	 sp->setPositionY(location.y);
}

void gameLayer::zanting(Ref* psender)
{
	//获取导演
		Director *director = Director::getInstance();
		//导演执行暂停音乐的工作
		director->pause();
		//创建暂停界面
		DialogLayer* dialogLayer = DialogLayer::create();
		//设置位置
		dialogLayer->setPosition(Point(0,0));
		//添加到布景中
		this->addChild(dialogLayer,6);
}
void gameLayer::update(float time)
{
	auto hero=(Sprite*)this->getChildByTag(1000);
	auto winSize = Director::getInstance()->getVisibleSize();
	Rect rHero = ((Sprite*)hero)->getBoundingBox();
	  
	fish->update();

	
		//check collision
		for (int i = 0; i < fish->FishList->count(); i++)
		{
			Sprite* fishSprite = (Sprite*)fish->FishList->getObjectAtIndex(i);
			bool pia = rHero.intersectsRect(fishSprite->getBoundingBox());
			if (pia == true)
			{
				fish->FishList->removeObjectAtIndex(i);
			    fish->removeChild(fishSprite);
				
			    cocos2d::log("a fish get");

				score++;
				std::string b=Value(score).asString(); 
				
			   //更新显示总分数的文本标签
				scoreL->setString(b);

			}
			
		}
}