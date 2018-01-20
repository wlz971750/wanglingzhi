#include "stdafx.h"
#include "Player.h"

bool CPlayer::addTask(DOTASK *pTask)
{
	for (int i = 0; i < TASK_COUT; i++)
	{
		if (m_pTaskList[i] == NULL)
		{
			m_pTaskList[i] = pTask;
			return true;
		}
	}
	return false;
}

void CPlayer::upDataTask(int *pState)
{
	if (KEYDOWN(VK_ESCAPE))
	{
		*pState = PLACE_MAP;
		m_iPlayerState = PLAYER_NONE;
	}
	else if (KEYDOWN(VK_UP))
	{
		m_pTaskState--;
		if (m_pTaskState < 0)
			m_pTaskState = 0;
	}
	else if (KEYDOWN(VK_DOWN))
	{
		m_pTaskState++;
		if (m_pTaskState>TASK_COUT)
			m_pTaskState = TASK_COUT;
	}
	else if (KEYDOWN(VK_RETURN))
	{
		if (m_pTaskState == TASK_COUT)
		{
			*pState = PLACE_MAP;
			m_iPlayerState = PLAYER_NONE;
		}
		else
		{
			if (m_pTaskList[m_pTaskState])
			{
				if (addDoTask(m_pTaskList[m_iCode]))
				{					
					if (m_pTaskList[m_iCode]->m_iID == 3001)			//��ʼ����1
					{
						MessageBox(NULL, _T("����ʼ"), _T("��ʾ"), MB_OK);
						m_pTaskList[m_pTaskState] = NULL;
						g_iNumber = TASK_ONE;
						g_isetNpcType = NPC_PASSER;
					}
					else if (m_pTaskList[m_iCode]->m_iID == 3002)			//��ʼ����2
					{
						MessageBox(NULL, _T("����ʼ"), _T("��ʾ"), MB_OK);
						m_pTaskList[m_pTaskState] = NULL;
						g_iNumber = TASK_TOW;
						g_isetNpcType = NPC_PASSER;
					}
					else if (m_pTaskList[m_iCode]->m_iID == 3003)			//��ʼ����3
					{
						MessageBox(NULL, _T("����ʼ"), _T("��ʾ"), MB_OK);
						m_pTaskList[m_pTaskState] = NULL;
						g_iNumber = TASK_THREE;
						g_isetNpcType = NPC_PASSER;
					}
					else if (m_pTaskList[m_iCode]->m_iID == 3004)			//��ʼ����4
					{
						MessageBox(NULL, _T("����ʼ"), _T("��ʾ"), MB_OK);
						m_pTaskList[m_pTaskState] = NULL;
						g_iNumber = TASK_FOUR;
						g_isetNpcType = NPC_MERMAID;
					}
					else if (m_pTaskList[m_iCode]->m_iID == 3005)			//��ʼ����5
					{
						MessageBox(NULL, _T("����ʼ"), _T("��ʾ"), MB_OK);
						m_pTaskList[m_pTaskState] = NULL;
						g_iNumber = TASK_FIVE;
						g_isetNpcType = NPC_MERMAID;
					}
					else if (m_pTaskList[m_iCode]->m_iID == 3006)			//��ʼ����6
					{
						MessageBox(NULL, _T("����ʼ"), _T("��ʾ"), MB_OK);
						m_pTaskList[m_pTaskState] = NULL;
						g_iNumber = TASK_SIX;
						g_isetNpcType = NPC_MERMAID;
					}
					else if (m_pTaskList[m_iCode]->m_iID == 3007)			//��ʼ����7
					{
						MessageBox(NULL, _T("����ʼ"), _T("��ʾ"), MB_OK);
						m_pTaskList[m_pTaskState] = NULL;
						g_iNumber = TASK_SEVEN;
						g_isetNpcType = NPC_GOD;
					}
				}
			
			}
		}
	}
}

void CPlayer::drawTask()
{
	cout << "\t��������\t\t��Ǯ\t����" << endl<<endl;
	for (int i = 0; i < TASK_COUT; i++)
	{
		if (m_pTaskState == i)
		{
			cout << "-->";
			m_iCode = i;
		}
		else
			cout << "      ";
		if (m_pTaskList[i] == NULL)
			cout << "\tû��������������ڽ�����..." << endl << endl;
		else
		{
			cout << "\t" << m_pTaskList[i]->m_szContent << "\t"
				<< m_pTaskList[i]->m_iMoney << "\t"
				<< m_pTaskList[i]->m_iExp << endl << endl;
		}
	}
	if (m_pTaskState == TASK_COUT)
		cout << "-->     ����";
	else
		cout << "        ����";
	cout << endl<<endl;
	cout << "��ʾ������return����ʼ����" << endl;
}
