#pragma once
#include "GameObject.h"

class CMonster :public CGameObject
{
public:
	CMonster();
	~CMonster();

	int m_iID;			//����id
	int m_iType;		//��������
	int m_iNum;			//���ﾭ��
	char m_szHead[32];	//����ͼ��
	int m_iMapID;		//�������ڵ�ͼ
	int m_iMoney;		//�����ֵ
	int m_iBkHp;		//����Ѫ��
	
	void onRender();	//��Ⱦ����
};

