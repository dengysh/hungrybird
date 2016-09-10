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

	//��������ͣ����ť����
	MenuItemImage *zanTingItem = MenuItemImage::create
	(
		"zanting.png",		//ƽʱ��ͼƬ
		"zanting.png",		//ѡ��ʱ��ͼ
		CC_CALLBACK_1(gameLayer::zanting, this)
	);
	//������ͣ�˵���ť��λ��
	zanTingItem->setPosition(Point(40,140));

	//������ͣ�˵�����
	auto pMenu = Menu::create(zanTingItem,NULL);
	//���ò˵���λ��
	 pMenu->setPosition(Point(0,0));
	//���˵���ӵ�������
	this->addChild(pMenu,3);

	//����һ��tempScore�ı���ǩ����ʱ������
	scoreL = LabelTTF::create("0", "Arial",28);
	//����һ����Ч������
	ActionInterval *act= RotateBy::create(1,-90);
	scoreL->runAction(act);
	//���ñ�ǩ�������ɫ
	scoreL->setColor (ccc3(255,255,255));
	//�����ı���ǩ��λ��
	scoreL->setPosition(Point(40,240));
	//���ı���ǩ��ӵ�������
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
	//��ȡ����
		Director *director = Director::getInstance();
		//����ִ����ͣ���ֵĹ���
		director->pause();
		//������ͣ����
		DialogLayer* dialogLayer = DialogLayer::create();
		//����λ��
		dialogLayer->setPosition(Point(0,0));
		//��ӵ�������
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
				
			   //������ʾ�ܷ������ı���ǩ
				scoreL->setString(b);

			}
			
		}
}