#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject()
{
	m_iRow=1;
	m_iCol=1;
	strcpy_s(m_szName, "wlz");
	m_iLevel=1;
	m_iHp=100;
	m_iNum=0;
	m_iattack = 50;
	m_iDef = 0;
	m_iMoney = 50;
}


CGameObject::~CGameObject()
{
}
