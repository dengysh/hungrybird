#include"cocos2d.h"

using namespace cocos2d;
/*
  ��Ϸ������ʼ����
*/
class openlayer: public cocos2d::Layer
{
public:
	virtual bool init();
	static Scene* createscene();

	//�ص�����
	void playGameCallback();
	CREATE_FUNC(openlayer);
};