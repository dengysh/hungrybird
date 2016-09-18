#include"openlayer.h"
#include"cocos2d.h"
#include"bearStartLayer.h"

using namespace cocos2d;
using namespace std;

Scene* openlayer::createscene()
{
	auto scene = Scene::create();
	auto layer = openlayer::create();
	scene->addChild(layer);
	return scene;
}

bool openlayer::init()
{
	if(!Layer::init())
	{
		return false;
	}
	
	//获取可见区域尺寸
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	//获取可见区域原点坐标
	Point origin = Director::sharedDirector()->getVisibleOrigin();

	auto label = Label::createWithTTF("Hungry Bear", "fonts/Marker Felt.ttf", 24);
	label->setRotation(-90);
	
	label->setPosition(Point(380,240));
	//把透明度设置为0
	label->setOpacity(0);
	//将精灵添加到布景中
	this->addChild(label,0);
	ActionInterval *act=FadeIn::create(2.6f);
	ActionInterval *act2=act->reverse();
	label->runAction(Sequence::create(
	act,
	act2,
	CallFunc::create(CC_CALLBACK_0(openlayer::playGameCallback,this)),
	NULL
	)
	);
	return true;
}

void openlayer::playGameCallback()
{
	Director::getInstance()->replaceScene(BeginScene::createScene());
}
