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
	int m_iNumb;	//����

	void setiRow(int iRow){ m_iRow = iRow; }		//��������  �����������
	void setiCol(int iCol){ m_iCol = iCol; }

	void onRender();
};

