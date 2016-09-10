#include "cocos2d.h"

using namespace cocos2d;

class Fish :public Node
{
public:
	Array* FishList;

	Fish();
	virtual void onEnter();
	void update(); 
	void addOne(int offsetX);
	void checkDel();
	int addCount;
	int GAME_STATUS;
};