#pragma once
#include "GameObject.h"

class CMonster :public CGameObject
{
public:
	CMonster();
	~CMonster();

	int m_iID;			//怪物id
	int m_iType;		//怪物类型
	int m_iNum;			//怪物经验
	char m_szHead[32];	//怪物图标
	int m_iMapID;		//怪物所在地图
	int m_iMoney;		//怪物价值
	int m_iBkHp;		//备份血量
	
	void onRender();	//渲染怪物
};

