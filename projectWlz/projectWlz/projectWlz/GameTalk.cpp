#include "stdafx.h"
#include "GameTalk.h"

char g_szInfoTalk[9][64] = {
	{ "你用你的矛刺我的盾试试？" },
	{ "让我来安抚你受伤的心灵~" },
	{ "在森林里迷路了吗？我来给你指引方向！" },
	{ "你想要一把能刺穿怪物的屁股的剑吗？" },
	{ "有人偷走了我的宝珠，你能帮帮我吗？么么哒！" },
	{ "跟我一起去往天堂吧！" },
	{ "你的脚很脏！需要买一双鞋子" },
	{ "你想骑点什么让自己变得更酷吗？" },
	{ "我什么都会做！" },
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
			cout << "-> 商店" << endl;
			cout << "   当铺" << endl;
			cout << "   任务" << endl;
			cout << "   提交" << endl;
			cout << "   返回" << endl;
		}
		else if (m_iTalk == TALK_SELL)
		{
			cout << "   商店" << endl;
			cout << "-> 当铺" << endl;
			cout << "   任务" << endl;
			cout << "   提交" << endl;
			cout << "   返回" << endl;
		}
		else if (m_iTalk == TALK_TASK)
		{
			cout << "   商店" << endl;
			cout << "   当铺" << endl;
			cout << "-> 任务" << endl;
			cout << "   提交" << endl;
			cout << "   返回" << endl;
		}
		else if (m_iTalk == TALK_PASSTASK)
		{
			cout << "   商店" << endl;
			cout << "   当铺" << endl;
			cout << "   任务" << endl;
			cout << "-> 提交" << endl;
			cout << "   返回" << endl;
		}
		else if (m_iTalk == TALK_EXIT)
		{
			cout << "   商店" << endl;
			cout << "   当铺" << endl;
			cout << "   任务" << endl;
			cout << "   提交" << endl;
			cout << "-> 返回" << endl;
		}
	}
	else
	{
		if (m_iTalks == TALK_BLOAT)
		{
			cout << "->   制作渔船(需消耗5木材、5铁矿)" << endl << endl;
			cout << "     制作翅膀(需消耗10铁矿、10草藤)" << endl << endl;
			cout << "     制作绳索(需消耗5草藤)" << endl << endl;
			cout << "     退    出" << endl << endl;
		}
		else if (m_iTalks == TALK_FLY)
		{
			cout << "     制作渔船(需消耗5木材、5铁矿)" << endl << endl;;
			cout << "->   制作翅膀(需消耗10铁矿、10草藤)" << endl << endl;;
			cout << "     制作绳索(需消耗5草藤)" << endl << endl;;
			cout << "     退    出" << endl << endl;
		}
		else if (m_iTalks == TALK_CORD)
		{
			cout << "     制作渔船(需消耗5木材、5铁矿)" << endl << endl;;
			cout << "     制作翅膀(需消耗10铁矿、10草藤)" << endl << endl;;
			cout << "->   制作绳索(需消耗5草藤)" << endl << endl;;
			cout << "     退    出" << endl << endl;
		}
		else
		{
			cout << "     制作渔船(需消耗5木材、5铁矿)" << endl << endl;;
			cout << "     制作翅膀(需消耗10铁矿、10草藤)" << endl << endl;;
			cout << "     制作绳索(需消耗5草藤)" << endl << endl;;
			cout << "->   退    出" << endl << endl;
		}
		cout << "当前木材数：" << g_iWood << endl;
		cout << "当前草藤数：" << g_iGrass << endl;
		cout << "当前铁矿数：" << g_iIron << endl;
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
					MessageBox(NULL, _T("没有商品可卖！"), _T("提示"), MB_OK);
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
					MessageBox(NULL, _T("没有任务可做！"), _T("提示"), MB_OK);
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
					g_iCode = TASK_TOWDONE;				//任务2完成！
				else if (m_pNpc->m_iType == NPC_GOD&&g_iNumber==TASK_FIVE)
					g_iCode = TASK_FIVEDONE;			//任务5完成！
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
					MessageBox(NULL, _T("制作渔船成功！"), _T("恭喜"), MB_OK);
					g_bBoat = true;
					g_iWood -= 5;
					g_iIron -= 5;
				}
				else 
					MessageBox(NULL, _T("材料不足！"), _T("警告"), MB_OK);
			}
			else if (m_iTalks == TALK_FLY)
			{
				if (g_iGrass >= 10 && g_iIron >= 10)
				{
					MessageBox(NULL, _T("制作翅膀成功！"), _T("恭喜"), MB_OK);
					g_bFly = true;
					g_iGrass -= 10;
					g_iIron -= 10;
				}
				else
					MessageBox(NULL, _T("材料不足！"), _T("警告"), MB_OK);
			}
			else if (m_iTalks == TALK_CORD)
			{
				if (g_iGrass >= 5 )
				{
					MessageBox(NULL, _T("制作绳索成功！"), _T("恭喜"), MB_OK);
					g_bCord = true;
					g_iGrass -= 5;
				}
				else
					MessageBox(NULL, _T("材料不足！"), _T("警告"), MB_OK);
			}
		}
	}
}
