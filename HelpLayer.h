#include "cocos2d.h"

using namespace cocos2d;
//�Զ���Ĳ�����
class HelpLayer : public cocos2d::Layer
{
public:
	
	Sprite* helpSprite;
	Sprite* help[9];
	//����
	int currPicIndex;
	//��ʼ���ķ���
	virtual bool init();
	void initIntroPic();

	static Scene* createScene();
	void menuCallBack0(Ref* pSende);
	void menuCallBack1(Ref* pSende);
	void menuCallBack2(Ref* pSende);

	//CCPlatformMacros.h�ļ��ж����һ���꣬����ָ�����͵Ķ���
	//��������Ӧ�ĳ�ʼ�����ͷŹ���
	CREATE_FUNC(HelpLayer);
};
