#include "cocos2d.h"

class BeginScene: public cocos2d::Layer
{
	public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void menustartCallback(cocos2d::Ref* pSender);
	void menuhelpCallback(cocos2d::Ref* pSender);
	void menurankCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(BeginScene);
};