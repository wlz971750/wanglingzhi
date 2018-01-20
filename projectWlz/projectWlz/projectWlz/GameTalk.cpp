#include "stdafx.h"
#include "GameTalk.h"

char g_szInfoTalk[9][64] = {
	{ "�������ì���ҵĶ����ԣ�" },
	{ "���������������˵�����~" },
	{ "��ɭ������·������������ָ������" },
	{ "����Ҫһ���̴ܴ������ƨ�ɵĽ���" },
	{ "����͵�����ҵı��飬���ܰ������ôô�գ�" },
	{ "����һ��ȥ�����ðɣ�" },
	{ "��Ľź��࣡��Ҫ��һ˫Ь��" },
	{ "�������ʲô���Լ���ø�����" },
	{ "��ʲô��������" },
};

CGameTalk::CGameTalk()
{
	m_iTalk = TALK_SHOP;
	m_iTalks = TALK_BLOAT;
	m_pUser = NULL;
	m_pNpc = NULL;
}


CGameTalk::~CGameTalk()
{
}

void CGameTalk::setTalkRole(CPlayer *pPlayer, CNpc *pNpc)
{
	m_pUser = pPlayer;
	m_pNpc = pNpc;
}

void CGameTalk::onRender()
{

	cout << m_pNpc->m_szName << ":";

	int iNumber = (m_pNpc->m_iID - 10) - 1;
	cout << g_szInfoTalk[iNumber] << endl << endl;
	if (m_pNpc->m_iType != NPC_NONE)
	{
		if (m_iTalk == TALK_SHOP)
		{
			cout << "-> �̵�" << endl;
			cout << "   ����" << endl;
			cout << "   ����" << endl;
			cout << "   �ύ" << endl;
			cout << "   ����" << endl;
		}
		else if (m_iTalk == TALK_SELL)
		{
			cout << "   �̵�" << endl;
			cout << "-> ����" << endl;
			cout << "   ����" << endl;
			cout << "   �ύ" << endl;
			cout << "   ����" << endl;
		}
		else if (m_iTalk == TALK_TASK)
		{
			cout << "   �̵�" << endl;
			cout << "   ����" << endl;
			cout << "-> ����" << endl;
			cout << "   �ύ" << endl;
			cout << "   ����" << endl;
		}
		else if (m_iTalk == TALK_PASSTASK)
		{
			cout << "   �̵�" << endl;
			cout << "   ����" << endl;
			cout << "   ����" << endl;
			cout << "-> �ύ" << endl;
			cout << "   ����" << endl;
		}
		else if (m_iTalk == TALK_EXIT)
		{
			cout << "   �̵�" << endl;
			cout << "   ����" << endl;
			cout << "   ����" << endl;
			cout << "   �ύ" << endl;
			cout << "-> ����" << endl;
		}
	}
	else
	{
		if (m_iTalks == TALK_BLOAT)
		{
			cout << "->   �����洬(������5ľ�ġ�5����)" << endl << endl;
			cout << "     �������(������10����10����)" << endl << endl;
			cout << "     ��������(������5����)" << endl << endl;
			cout << "     ��    ��" << endl << endl;
		}
		else if (m_iTalks == TALK_FLY)
		{
			cout << "     �����洬(������5ľ�ġ�5����)" << endl << endl;;
			cout << "->   �������(������10����10����)" << endl << endl;;
			cout << "     ��������(������5����)" << endl << endl;;
			cout << "     ��    ��" << endl << endl;
		}
		else if (m_iTalks == TALK_CORD)
		{
			cout << "     �����洬(������5ľ�ġ�5����)" << endl << endl;;
			cout << "     �������(������10����10����)" << endl << endl;;
			cout << "->   ��������(������5����)" << endl << endl;;
			cout << "     ��    ��" << endl << endl;
		}
		else
		{
			cout << "     �����洬(������5ľ�ġ�5����)" << endl << endl;;
			cout << "     �������(������10����10����)" << endl << endl;;
			cout << "     ��������(������5����)" << endl << endl;;
			cout << "->   ��    ��" << endl << endl;
		}
		cout << "��ǰľ������" << g_iWood << endl;
		cout << "��ǰ��������" << g_iGrass << endl;
		cout << "��ǰ��������" << g_iIron << endl;
	}
}
	


void CGameTalk::upData(int *pMapState)
{
	if (m_pNpc->m_iType != NPC_NONE)
	{
		if (KEYDOWN(VK_ESCAPE))
		{
			*pMapState = PLACE_MAP;
			m_pUser->m_isSell = false;
			m_pUser->m_isEquip = true;
		}
			
		else if (KEYDOWN(VK_UP))
		{
			m_iTalk--;
			if (m_iTalk < TALK_SHOP)
				m_iTalk = TALK_EXIT;
		}
		else if (KEYDOWN(VK_DOWN))
		{
			m_iTalk++;
			if (m_iTalk > TALK_EXIT)
				m_iTalk = TALK_SHOP;
		}
		else if (KEYDOWN(VK_RETURN))
		{
			if (m_iTalk == TALK_EXIT)
			{
				*pMapState = PLACE_MAP;
				m_iTalk = TALK_SHOP;
			}
			else if (m_iTalk == TALK_SHOP)
			{
				if (m_pNpc->m_iType >= NPC_TASK)
					MessageBox(NULL, _T("û����Ʒ������"), _T("��ʾ"), MB_OK);
				else
					*pMapState = PLACE_SHOP;
			}
			else if (m_iTalk == TALK_SELL)
			{
				*pMapState = PLACE_PLAYER;
				m_pUser->setPlayerState(PLAYER_BAG);
				m_iTalk = TALK_SHOP;
				m_pUser->setSell(true);
				m_pUser->setEquip(false);
			}
			else if (m_iTalk == TALK_TASK)
			{
				if (m_pNpc->m_iType >= NPC_TASK)
					*pMapState = PLACE_TASK;
				else
					MessageBox(NULL, _T("û�����������"), _T("��ʾ"), MB_OK);
			}
			else if (m_iTalk == TALK_PASSTASK)
			{
				if (m_pNpc->m_iType >= NPC_TASK)
				{
					*pMapState = PLACE_PLAYER;
					m_pUser->setPlayerState(PLAYER_TASKDOING);
					g_igetNpcType = m_pNpc->m_iType;
				}
				if (m_pNpc->m_iType == NPC_MERMAID&&g_iNumber==TASK_TOW)
					g_iCode = TASK_TOWDONE;				//����2��ɣ�
				else if (m_pNpc->m_iType == NPC_GOD&&g_iNumber==TASK_FIVE)
					g_iCode = TASK_FIVEDONE;			//����5��ɣ�
			}
		}
	}
	else
	{
		if (KEYDOWN(VK_ESCAPE))
			*pMapState = PLACE_MAP;
		else if (KEYDOWN(VK_UP))
		{
			m_iTalks--;
			if (m_iTalks < TALK_BLOAT)
				m_iTalks = TALK_BLOAT;
		}
		else if (KEYDOWN(VK_DOWN))
		{
			m_iTalks++;
			if (m_iTalks > TALK_RETURN)
				m_iTalks = TALK_RETURN;
		}
		else if (KEYDOWN(VK_RETURN))
		{
			if (m_iTalks == TALK_RETURN)
			{
				*pMapState = PLACE_MAP;
				m_iTalks = TALK_BLOAT;
			}
			else if (m_iTalks == TALK_BLOAT)
			{
				if (g_iWood >= 5 && g_iIron >= 5)
				{
					MessageBox(NULL, _T("�����洬�ɹ���"), _T("��ϲ"), MB_OK);
					g_bBoat = true;
					g_iWood -= 5;
					g_iIron -= 5;
				}
				else 
					MessageBox(NULL, _T("���ϲ��㣡"), _T("����"), MB_OK);
			}
			else if (m_iTalks == TALK_FLY)
			{
				if (g_iGrass >= 10 && g_iIron >= 10)
				{
					MessageBox(NULL, _T("�������ɹ���"), _T("��ϲ"), MB_OK);
					g_bFly = true;
					g_iGrass -= 10;
					g_iIron -= 10;
				}
				else
					MessageBox(NULL, _T("���ϲ��㣡"), _T("����"), MB_OK);
			}
			else if (m_iTalks == TALK_CORD)
			{
				if (g_iGrass >= 5 )
				{
					MessageBox(NULL, _T("���������ɹ���"), _T("��ϲ"), MB_OK);
					g_bCord = true;
					g_iGrass -= 5;
				}
				else
					MessageBox(NULL, _T("���ϲ��㣡"), _T("����"), MB_OK);
			}
		}
	}
}
