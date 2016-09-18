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
	
	//��ȡ�ɼ�����ߴ�
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	//��ȡ�ɼ�����ԭ������
	Point origin = Director::sharedDirector()->getVisibleOrigin();

	auto label = Label::createWithTTF("Hungry Bear", "fonts/Marker Felt.ttf", 24);
	label->setRotation(-90);
	
	label->setPosition(Point(380,240));
	//��͸��������Ϊ0
	label->setOpacity(0);
	//��������ӵ�������
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
