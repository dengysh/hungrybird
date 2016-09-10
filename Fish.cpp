#include "Fish.h"

Fish::Fish(void)
{
	addCount = 0;
	GAME_STATUS = 1;
}
void Fish::onEnter()
{
	Node::onEnter();
	FishList = Array::create();
	FishList->retain();
}


void Fish::update()
{
	if (GAME_STATUS != 1)
		return;
	addCount++;
	if (addCount == 120)
	{
		addOne(0);
		addCount = 0;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	for (int i = FishList->count() - 1; i >= 0; i--)
	{
		auto s = (Sprite*)FishList->getObjectAtIndex(i);
		s->setPositionX(s->getPositionX() + 3);
		if (s->getPositionX() > s->getContentSize().width / 2+visibleSize.width)
		{
			FishList->removeObjectAtIndex(i);
			this->removeChild(s);
			cocos2d::log("a fish removed");
		}
	}
}

void Fish::addOne(int offsetX)
{
	Size size = Director::getInstance()->getWinSize();
	auto sprite = Sprite::create("E1.png");
	Size spriteSize = sprite->getContentSize();
	FishList->addObject(sprite);
	this->addChild(sprite,6);
	auto sprite2 = Sprite::create("E2.png");
	Size spriteSize2 = sprite->getContentSize();
	FishList->addObject(sprite2);
	this->addChild(sprite2,6);
	// set positon
	int maxY = size.height -spriteSize.height;
	int minY = spriteSize.height;
	int y1 = CCRANDOM_0_1()*(maxY - minY) + minY;
	int y2=CCRANDOM_0_1()*(maxY-y1)+y1;
	sprite->setPosition(Vec2(-spriteSize.width / 2 + offsetX, y1));
	sprite2->setPosition(Vec2(-spriteSize2.width / 2 + offsetX, y2));
	cocos2d::log("two fish added");
}