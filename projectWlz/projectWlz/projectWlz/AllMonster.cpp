#include "stdafx.h"
#include "AllMonster.h"


CAllMonster::CAllMonster()
{
}


CAllMonster::~CAllMonster()
{
	CMonster *pData = NULL;
	map<int, CMonster*>::iterator iter = m_pMonsterList.begin();
	for (; iter != m_pMonsterList.end(); iter++)
	{
		pData = (*iter).second;
		delete pData;
	}
	m_pMonsterList.clear();
}

void CAllMonster::readFile(char*FileMonster)
{
	fstream file(FileMonster);
	if (file)
	{
		getline(file, string());
		while (true)
		{
			CMonster *pMons = new CMonster();
			file >> pMons->m_iID
				>> pMons->m_szName
				>> pMons->m_iType
				>>pMons->m_iNum
				>>pMons->m_iattack
				>> pMons->m_iRow
				>> pMons->m_iCol
				>> pMons->m_iLevel
				>> pMons->m_iHp
				>> pMons->m_szHead
				>> pMons->m_iMapID
				>>pMons->m_iMoney
				>>pMons->m_iBkHp;
			if (strlen(pMons->m_szName )<= 0)
			{
				delete pMons;
				break;
			}
			m_pMonsterList[pMons->m_iID] = pMons;
		}		
	}
	file.clear();
	file.close();
}

bool  CAllMonster::drawMonster(int iRow, int iCol, int iMapID)
{
	map<int, CMonster*>::iterator iter = m_pMonsterList.begin();
	for (; iter != m_pMonsterList.end(); iter++)
	{
		CMonster *pData = (*iter).second;
		if (pData->m_iRow == iRow&&
			pData->m_iCol ==iCol&&
			pData->m_iMapID == iMapID)
		{
			pData->onRender();
			return true;
		}
	}
	return false;
}

CMonster *CAllMonster::isColl(int iRow, int iCol, int iMapID)
{
	map<int, CMonster*>::iterator iter = m_pMonsterList.begin();
	for (; iter != m_pMonsterList.end(); iter++)
	{
		CMonster *pData = (*iter).second;
		if (pData->m_iRow == iRow&&
			pData->m_iCol == iCol&&
			pData->m_iMapID == iMapID)
			return  pData;
	}
	return NULL;
}