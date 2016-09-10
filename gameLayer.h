#include "cocos2d.h"
#include "Fish.h"
using namespace std;

class gameLayer:public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(gameLayer);
	//virtual void update(float time);
	 void onTouchesEnded(const vector<cocos2d::Touch*>& touches,cocos2d::Event* event);
	 void onTouchesBegan(const vector<cocos2d::Touch*>& touches,cocos2d::Event* event);
	void onTouchesMoved(const vector<cocos2d::Touch*>& touches,cocos2d::Event* event);	
	void zanting(cocos2d::Ref* pSender);
	virtual void update(float time);

	int GAME_STATUS;
	//当前分数的label
	LabelTTF *scoreL;
	int score;

	Fish* fish;
};