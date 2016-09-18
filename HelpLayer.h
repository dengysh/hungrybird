#include "cocos2d.h"

using namespace cocos2d;
//自定义的布景类
class HelpLayer : public cocos2d::Layer
{
public:
	
	Sprite* helpSprite;
	Sprite* help[9];
	//索引
	int currPicIndex;
	//初始化的方法
	virtual bool init();
	void initIntroPic();

	static Scene* createScene();
	void menuCallBack0(Ref* pSende);
	void menuCallBack1(Ref* pSende);
	void menuCallBack2(Ref* pSende);

	//CCPlatformMacros.h文件中定义的一个宏，创建指定类型的对象
	//并做好相应的初始化与释放工作
	CREATE_FUNC(HelpLayer);
};
