#include "stdafx.h"
#include "AllNpc.h"


CAllNpc::CAllNpc()
{
}


CAllNpc::~CAllNpc()
{
	CNpc *pData = NULL;
	map<int, CNpc*>::iterator iter = m_pNpcList.begin();
	for (; iter != m_pNpcList.end(); iter++)
	{
		pData = (*iter).second;
		delete pData;
	}
	m_pNpcList.clear();
}

void CAllNpc::readFileNpc(char *FileNpc)
{
	ifstream file(FileNpc);
	if (file)
	{
		getline(file, string());

		while (true)
		{
			CNpc *pNpc = new CNpc();
			file >> pNpc->m_iID
				>> pNpc->m_szName
				>> pNpc->m_iType
				>> pNpc->m_iRow
				>> pNpc->m_iCol
				>> pNpc->m_iLevel
				>> pNpc->m_iHp
				>>pNpc->m_szHead
				>> pNpc->m_iMapID;
			if (strlen(pNpc->m_szName) <= 0)
			{
				delete pNpc;
				break;
			}
			m_pNpcList[pNpc->m_iID] = pNpc;
		}
	}
	file.clear();
	file.close();
}

bool CAllNpc::drawNpc(int iRow, int iCol, int iMapID)
{
	map<int, CNpc*>::iterator iter = m_pNpcList.begin();
	for (; iter != m_pNpcList.end(); iter++)
	{
		CNpc *pData = (*iter).second;
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

CNpc *CAllNpc::isColl(int iRow,int iCol,int iMapID)
{
	map<int, CNpc*>::iterator iter = m_pNpcList.begin();
	for (; iter != m_pNpcList.end();iter++)
	{
		CNpc *pData = (*iter).second;
		if (pData->m_iRow == iRow&&
			pData->m_iCol == iCol&&
			pData->m_iMapID == iMapID)
		{
			return pData;
		}
	}
	return NULL;
}