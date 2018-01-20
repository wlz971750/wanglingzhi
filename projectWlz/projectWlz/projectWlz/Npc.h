#pragma once
#include"GameObject.h"

enum{
	NPC_NULL,		//0	不能购买
	NPC_DEF,		//1 购买防具
	NPC_BESTWEAPON,	//2 购买高级武器
	NPC_DRUG,		//3 购买药品
	NPC_WEAPON,		//4 购买普通武器
	NPC_TASK=10,	//任务
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

