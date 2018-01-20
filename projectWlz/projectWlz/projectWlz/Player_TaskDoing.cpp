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
	cout << "\t��������\t\t��Ǯ\t����" << endl << endl;
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
			cout << "\t��..." << endl << endl;
		else
		{
			cout << "\t" << m_pDoTaskList[i]->m_szContent << "\t"
				<< m_pDoTaskList[i]->m_iMoney << "\t"
				<< m_pDoTaskList[i]->m_iExp << endl << endl;
		}
	}
	if (m_pDoTask == TASK_COUT)
		cout << "-->     ����";
	else
		cout << "        ����";
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
						MessageBox(NULL, _T("�������"), _T("��ϲ"), MB_OK);
						m_pDoTaskList[m_iNumb] = NULL;
						g_iNumber = TASK_NONE;
						g_iCode = TASK_NODO;						
					}
					else
						MessageBox(NULL, _T("�㻹û���������"), _T("����"), MB_OK);
				}
				else
					MessageBox(NULL, _T("���������NPC���Ͳ�ͬ"), _T("����"), MB_OK);
			}
		}
	}

}