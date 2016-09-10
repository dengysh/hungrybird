#ifndef _DialogLayer_h
#define _DialogLayer_h

#include "cocos2d.h"
using namespace std;
using namespace cocos2d;

class DialogLayer: public LayerColor
{
public:

	//主菜单界面
	Menu *m_pMenu;
	//按钮是否被点击的标志位
	bool m_bTouchedMenu;
	
public:
	//初始化的方法
	virtual bool init();
	//初始化
	void initDialog();
	//返回主菜单界面的方法
	void homeSence(Ref* pSender);
	//继续游戏按钮的单机回调方法
	void menuCallbackContinueGame(Ref *pSender);

	CREATE_FUNC(DialogLayer);
};

#endif
