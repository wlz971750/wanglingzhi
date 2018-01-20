#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
	m_iBkHp = m_iHp;
}


CMonster::~CMonster()
{
}

void CMonster::onRender()
{
	cout << m_szHead;
}
