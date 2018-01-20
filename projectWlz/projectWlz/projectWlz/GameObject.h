#pragma once
class CGameObject
{
public:
	CGameObject();
	~CGameObject();

	int m_iRow;
	int m_iCol;
	char m_szName[32];
	int m_iLevel;
	int m_iHp;
	int m_iNum;
	int m_iattack;
	int m_iDef;
	int m_iMoney;

	void setiRow(int iRow){ m_iRow = iRow; }		//内联函数  设置玩家坐标
	void setiCol(int iCol){ m_iCol = iCol; }
};

