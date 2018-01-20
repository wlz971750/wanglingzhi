#include "stdafx.h"
#include "GameTask.h"

static CGameTask *s_pTask = NULL;
CGameTask *CGameTask::getTask()
{
	if (s_pTask == NULL)
	{
		s_pTask = new CGameTask();
		s_pTask->readTask("Data/task.txt");
	}
	return s_pTask;
}

CGameTask::CGameTask()
{
}


CGameTask::~CGameTask()
{
}

void CGameTask::readTask(char *TaskFile)
{
	fstream file(TaskFile);
	if (file)
	{
		getline(file, string());
		while (true)
		{
			DOTASK *pTask = new DOTASK;
			file >> pTask->m_iID
				>> pTask->m_iType
				>> pTask->m_szContent
				>> pTask->m_iMoney
				>> pTask->m_iExp
				>> pTask->m_iState;
			if (strlen(pTask->m_szContent) <= 0)
			{
				delete pTask;
				break;
			}
			m_nTaskList[pTask->m_iID] = pTask;
		}
	}
	file.clear();
	file.close();
}

map<int, DOTASK*>	CGameTask::getCurTask(int iType)
{

	map<int, DOTASK*> nList;
	map<int, DOTASK*>::iterator iter = m_nTaskList.begin();
	for (; iter != m_nTaskList.end(); iter++)
	{
		DOTASK *pItem = (*iter).second;
		if (pItem->m_iType == iType)
		{
			nList[pItem->m_iID] = pItem;
		}

	}
	return nList;
}