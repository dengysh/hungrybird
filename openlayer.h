#include"cocos2d.h"

using namespace cocos2d;
/*
  游戏启动初始场景
*/
class openlayer: public cocos2d::Layer
{
public:
	virtual bool init();
	static Scene* createscene();

	//回调函数
	void playGameCallback();
	CREATE_FUNC(openlayer);
};