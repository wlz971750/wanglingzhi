#include "stdafx.h"
#include "Task.h"




CTask::CTask()
{
	m_pUser = NULL;
	m_pNpc = NULL;

	m_pCurTask = NULL;
	m_iState = 0;
}


CTask::~CTask()
{
	DOTASK *pData = NULL;
	map<int, DOTASK*>::iterator iter = m_nList.begin();
	for (; iter != m_nList.end(); iter++)
	{
		pData = (*iter).second;
		delete pData;
	}
	m_nList.clear();
}


bool CTask::isSetTask()
{
	if (m_pUser == NULL || m_pNpc == NULL)
		return false;
	return true;
}

void CTask::setTaskRole(CPlayer *pPlayer, CNpc *pNpc)
{
	m_pUser = pPlayer;
	m_pNpc = pNpc;
	CGameTask *pTask = CGameTask::getTask();
	m_nList.clear();
	m_nList = pTask->getCurTask(m_pNpc->m_iType);
}

void CTask::upData(int *iMapState)
{
	if (KEYDOWN(VK_ESCAPE))
	{
		*iMapState = PLACE_MAP;
		m_pUser = NULL;
		m_pNpc = NULL;
	}
	else if (KEYDOWN(VK_UP))
	{
		m_iState--;
		if (m_iState < 0)
			m_iState = 0;
	}
	else if (KEYDOWN(VK_DOWN))
	{
		m_iState++;
		if (m_iState>m_nList.size())
			m_iState = m_nList.size();
	}
	else if (KEYDOWN(VK_RETURN))
	{
		if (m_iState == m_nList.size())
		{
			*iMapState = PLACE_MAP;
			m_pUser = NULL;
			m_pNpc = NULL;
		}
		else
		{
			if (m_pCurTask)
			{
				if (m_pCurTask->m_iState == 1)
					MessageBox(NULL, _T("你已经做过该任务了！"), _T("警告"), MB_OK);
				else
				{
					if (m_pUser->addTask(m_pCurTask))
						MessageBox(NULL, _T("接受任务成功！"), _T("提示"), MB_OK);
					else
						MessageBox(NULL, _T("请先完成任务！再接新任务"), _T("警告"), MB_OK);
				}
			}		
		}
	}

}

void CTask::onRender()
{
	DOTASK	*pTask = NULL;
	int iCout = 0;
	cout << "\tID\t任务内容\t\t金钱\t经验" << endl << endl;
	map<int, DOTASK*>::iterator iter = m_nList.begin();
	for (; iter != m_nList.end(); iter++)
	{
		pTask = (*iter).second;
		if (m_iState == iCout)
		{
			cout << "-->";
			m_pCurTask = pTask;			
		}
		else
			cout << "   ";
		if (m_pCurTask == NULL)
			cout << "空";
		else
		{
			cout << "\t" << pTask->m_iID << "\t"
				<< pTask->m_szContent << "\t"
				<< pTask->m_iMoney << "\t"
				<< pTask->m_iExp << endl << endl;
			iCout++;
		}
	
	}
	if (m_iState == m_nList.size())
		cout << "-->     返回";
	else
		cout << "        返回";
	cout << endl<<endl;
	cout << "提示：提取任务后，按下A键开始任务" << endl;
}

