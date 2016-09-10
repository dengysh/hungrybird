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
	if (addCount == 60)
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
			cocos2d::log("a obstacle removed");
		}
	}
}

void Fish::addOne(int offsetX)
{
	Size size = Director::getInstance()->getWinSize();
	auto sprite = Sprite::create("E1.png");
	Size spriteSize = sprite->getContentSize();
	FishList->addObject(sprite);
	this->addChild(sprite);
	auto sprite2 = Sprite::create("E2.png");
	Size spriteSize2 = sprite->getContentSize();
	FishList->addObject(sprite2);
	this->addChild(sprite2);
	// set positon
	int maxUpY = size.height + spriteSize.height / 4;
	int minUpY = size.height - spriteSize.height / 4;
	int y1 = CCRANDOM_0_1()*(maxUpY - minUpY) + minUpY;
	int maxDownY = spriteSize.height / 4;
	int minDownY = -spriteSize.height / 4;
	int y2 = CCRANDOM_0_1()*(maxDownY - minDownY) + minDownY;
	if (y1 - y2 - spriteSize.height < 160)
	{
		y2 = y1 - spriteSize.height - 160;
	}
	sprite->setPosition(Vec2(size.width + spriteSize.width / 2 + offsetX, y1));
	sprite2->setPosition(Vec2(size.width + spriteSize2.width / 2 + offsetX, y2));
	cocos2d::log("a fish added");
}