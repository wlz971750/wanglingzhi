#include "stdafx.h"
#include "Material.h"


CMaterial::CMaterial()
{
	m_iRow = 1;
	m_iCol = 1;
	strcpy_s(m_szName, "wlz");
	strcpy_s(m_szHead, "²Ý");
	m_iID = 4001;
	m_iType = 1;
	m_iNumb = 1;
	m_iMapID = 101;
}


CMaterial::~CMaterial()
{
}

void CMaterial::onRender()
{
	cout << m_szHead;
}
