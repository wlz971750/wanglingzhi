#pragma once
#include"GameObject.h"

enum{
	NPC_NULL,		//0	���ܹ���
	NPC_DEF,		//1 �������
	NPC_BESTWEAPON,	//2 ����߼�����
	NPC_DRUG,		//3 ����ҩƷ
	NPC_WEAPON,		//4 ������ͨ����
	NPC_TASK=10,	//����
};
class CNpc:public CGameObject
{
public:
	CNpc();
	~CNpc();

	int m_iID;
	int m_iType;
	char m_szHead[32];
	int m_iMapID;

	void onRender();

};

