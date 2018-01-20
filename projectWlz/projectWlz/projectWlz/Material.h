#pragma once
class CMaterial
{
public:
	CMaterial();
	~CMaterial();

	int m_iRow;
	int m_iCol;
	char m_szName[32];
	int m_iID;
	int m_iType;
	char m_szHead[32];
	int m_iMapID;
	int m_iNumb;	//数量

	void setiRow(int iRow){ m_iRow = iRow; }		//内联函数  设置玩家坐标
	void setiCol(int iCol){ m_iCol = iCol; }

	void onRender();
};

