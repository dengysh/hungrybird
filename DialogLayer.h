#ifndef _DialogLayer_h
#define _DialogLayer_h

#include "cocos2d.h"
using namespace std;
using namespace cocos2d;

class DialogLayer: public LayerColor
{
public:

	//���˵�����
	Menu *m_pMenu;
	//��ť�Ƿ񱻵���ı�־λ
	bool m_bTouchedMenu;
	
public:
	//��ʼ���ķ���
	virtual bool init();
	//��ʼ��
	void initDialog();
	//�������˵�����ķ���
	void homeSence(Ref* pSender);
	//������Ϸ��ť�ĵ����ص�����
	void menuCallbackContinueGame(Ref *pSender);

	CREATE_FUNC(DialogLayer);
};

#endif
