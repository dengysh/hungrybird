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
	//确定一定帧数后添加一批鱼
	addCount++;
	if (addCount == 120)
	{
		//随机加鱼，最多四条
		int numFish=CCRANDOM_0_1()*5;
		addOne(numFish);
		addCount = 0;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	for (int i = FishList->count() - 1; i >= 0; i--)
	{
		auto s = (Sprite*)FishList->getObjectAtIndex(i);
		//设置鱼游动速度，通过每帧增加x坐标实现。
		s->setPositionX(s->getPositionX() + 3);
		//边界检测，移除边界外精灵
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
	int p_height=size.height/num;//道次高度
	int fishIndex;//鱼的图片索引
	int base_height;//道次基线位置

	for(int i=0;i<num;i++)
	{
		fishIndex=CCRANDOM_0_1()*7+1;
		auto fish_path=StringUtils::format("fish/E%d.png",fishIndex);//构造图片路径
		//创建精灵，加入层，加入列表
		auto sprite = Sprite::create(fish_path);
		this->addChild(sprite,3);
		FishList->addObject(sprite);
		//位置设定
		base_height=i*p_height;
		Size spriteSize = sprite->getContentSize();
		//计算边界值
		int maxY =base_height+ p_height -spriteSize.height;
	    int minY = base_height+spriteSize.height;
		//计算Y随机
		int y= CCRANDOM_0_1()*(maxY - minY) + minY;
		int x_offset= CCRANDOM_0_1()*spriteSize.width*2;//x随机偏移距离

		sprite->setPosition(Vec2(-spriteSize.width / 2+x_offset , y));
		cocos2d::log("a fish added");
	}

}