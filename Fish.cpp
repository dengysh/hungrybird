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
	//ȷ��һ��֡�������һ����
	addCount++;
	if (addCount == 120)
	{
		//������㣬�������
		int numFish=CCRANDOM_0_1()*5;
		addOne(numFish);
		addCount = 0;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	for (int i = FishList->count() - 1; i >= 0; i--)
	{
		auto s = (Sprite*)FishList->getObjectAtIndex(i);
		//�������ζ��ٶȣ�ͨ��ÿ֡����x����ʵ�֡�
		s->setPositionX(s->getPositionX() + 3);
		//�߽��⣬�Ƴ��߽��⾫��
		if (s->getPositionX() > s->getContentSize().width / 2+visibleSize.width)
		{
			FishList->removeObjectAtIndex(i);
			this->removeChild(s);
			cocos2d::log("a fish removed");
		}
	}
}

void Fish::addOne(int num)
{
	if(num == 0)
		return;
	Size size = Director::getInstance()->getWinSize();
	//int numGoodFish = CCRANDOM_0_1()*num;
	//int numBadFish = num - numGoodFish;
	int p_height=size.height/num;//���θ߶�
	int fishIndex;//���ͼƬ����
	int base_height;//���λ���λ��

	for(int i=0;i<num;i++)
	{
		fishIndex=CCRANDOM_0_1()*7+1;
		auto fish_path=StringUtils::format("fish/E%d.png",fishIndex);//����ͼƬ·��
		//�������飬����㣬�����б�
		auto sprite = Sprite::create(fish_path);
		this->addChild(sprite,3);
		FishList->addObject(sprite);
		//λ���趨
		base_height=i*p_height;
		Size spriteSize = sprite->getContentSize();
		//����߽�ֵ
		int maxY =base_height+ p_height -spriteSize.height;
	    int minY = base_height+spriteSize.height;
		//����Y���
		int y= CCRANDOM_0_1()*(maxY - minY) + minY;
		int x_offset= CCRANDOM_0_1()*spriteSize.width*2;//x���ƫ�ƾ���

		sprite->setPosition(Vec2(-spriteSize.width / 2+x_offset , y));
		cocos2d::log("a fish added");
	}

}