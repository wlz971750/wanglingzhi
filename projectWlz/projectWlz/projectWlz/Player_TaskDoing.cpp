#include "stdafx.h"
#include "Player.h"

bool CPlayer::addDoTask(DOTASK *pDoTask)
{
	for (int i = 0; i < TASK_COUT; i++)
	{
		if (m_pDoTaskList[i] == NULL)
		{
			m_pDoTaskList[i] = pDoTask;
			return true;
		}
	}
	return false;
}

void CPlayer::drawDoTask()
{
	cout << "\t任务内容\t\t金钱\t经验" << endl << endl;
	for (int i = 0; i < TASK_COUT; i++)
	{
		if (m_pDoTask == i)
		{
			cout << "-->";
			m_iNumb = i;
		}
		else
			cout << "     ";
		if (m_pDoTaskList[i] == NULL)
			cout << "\t空..." << endl << endl;
		else
		{
			cout << "\t" << m_pDoTaskList[i]->m_szContent << "\t"
				<< m_pDoTaskList[i]->m_iMoney << "\t"
				<< m_pDoTaskList[i]->m_iExp << endl << endl;
		}
	}
	if (m_pDoTask == TASK_COUT)
		cout << "-->     返回";
	else
		cout << "        返回";
}

void CPlayer::upDataDoTask(int *pState)
{
	if (KEYDOWN(VK_ESCAPE))
	{
		*pState = PLACE_MAP;
		m_iPlayerState = PLAYER_NONE;
	}
	else if (KEYDOWN(VK_UP))
	{
		m_pDoTask--;
		if (m_pDoTask < 0)
			m_pDoTask = 0;
	}
	else if (KEYDOWN(VK_DOWN))
	{
		m_pDoTask++;
		if (m_pDoTask>TASK_COUT)
			m_pDoTask = TASK_COUT;
	}
	else if (KEYDOWN(VK_RETURN))
	{
		if (m_pDoTask == TASK_COUT)
		{
			*pState = PLACE_MAP;
			m_iPlayerState = PLAYER_NONE;
		}
		else
		{								
			if (m_pDoTaskList[m_iNumb])
			{
				if (g_igetNpcType == g_isetNpcType)
				{
					if (g_iNumber == g_iCode)
					{
						m_iMoney += m_pDoTaskList[m_iNumb]->m_iMoney;
						m_iNum += m_pDoTaskList[m_iNumb]->m_iExp;
						m_pDoTaskList[m_iNumb]->m_iState = 1;
						MessageBox(NULL, _T("任务完成"), _T("恭喜"), MB_OK);
						m_pDoTaskList[m_iNumb] = NULL;
						g_iNumber = TASK_NONE;
						g_iCode = TASK_NODO;						
					}
					else
						MessageBox(NULL, _T("你还没有完成任务！"), _T("警告"), MB_OK);
				}
				else
					MessageBox(NULL, _T("参与任务的NPC类型不同"), _T("警告"), MB_OK);
			}
		}
	}

}