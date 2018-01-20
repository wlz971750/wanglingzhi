#include "stdafx.h"
#include "AllMaterial.h"


CAllMaterial::CAllMaterial()
{
}


CAllMaterial::~CAllMaterial()
{
	CMaterial *pData = NULL;
	map<int, CMaterial*>::iterator iter = m_pMaterList.begin();
	for (; iter != m_pMaterList.end(); iter++)
	{
		pData = (*iter).second;
		delete pData;
	}
	m_pMaterList.clear();
}

void CAllMaterial::readFile(char *FileMaterial)
{
	fstream file(FileMaterial);
	if (file)
	{
		getline(file, string());
		while (true)
		{
			CMaterial *pMater = new CMaterial();
			file >> pMater->m_iID
				>> pMater->m_szName
				>> pMater->m_iType
				>> pMater->m_iRow
				>> pMater->m_iCol
				>> pMater->m_iNumb
				>> pMater->m_szHead
				>> pMater->m_iMapID;
			if (strlen(pMater->m_szHead) <= 0)
			{
				delete pMater;
				break;
			}
			m_pMaterList[pMater->m_iID] = pMater;
		}
	}
	file.clear();
	file.close();
}

bool CAllMaterial::drawMaterial(int iRow, int iCol, int iMapID)
{
	map<int, CMaterial*>::iterator iter = m_pMaterList.begin();
	for (; iter != m_pMaterList.end(); iter++)
	{
		CMaterial *pData = (*iter).second;
		if (pData->m_iRow == iRow&&
			pData->m_iCol == iCol&&
			pData->m_iMapID == iMapID)
		{
			pData->onRender();
			return true;
		}
	}
	return false;
}

CMaterial *CAllMaterial::isColl(int iRow, int iCol, int iMapID)
{
	map<int, CMaterial*>::iterator iter = m_pMaterList.begin();
	for (; iter != m_pMaterList.end(); iter++)
	{
		CMaterial *pData = (*iter).second;
		if (pData->m_iRow == iRow&&
			pData->m_iCol == iCol&&
			pData->m_iMapID == iMapID)
		
			return pData;
	}
	return NULL;
}
