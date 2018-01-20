#include "stdafx.h"
#include "Player.h"

char g_szPosName[EQUIP_COUT][7] = 
{
	{ "头盔：" },
	{ "项链：" },
	{ "铠甲：" },
	{ "鞋子：" },
	{ "武器：" },
	{ "坐骑：" },
};

ITEM *CPlayer::addEquip(ITEM *pItem)
{
	if (m_pEquipList[pItem->iPos-1] == NULL)
	{
		m_pEquipList[pItem->iPos-1] = pItem;
		return NULL;
	}
	else
	{
		ITEM *pDate = m_pEquipList[pItem->iPos - 1];
		m_pEquipList[pItem->iPos - 1] = pItem;
		return pDate;
	}
}

void CPlayer::drawInfo()
{
	cout << "\t位置\t名称\t等级\t生命\t防御\t攻击" << endl << endl;

	for (int i = 0; i<EQUIP_COUT; i++)
	{

		if (m_pEquipState == i)
		{
			cout << "-->     ";
			m_iPosNum = i;
		}
		else
			cout << "        ";
		cout << g_szPosName[i];
		if (m_pEquipList[i] == NULL)
			cout << "空位" << endl<<endl;
		else
		{
			cout << "\t"<< m_pEquipList[i]->szName << "\t"
				<< m_pEquipList[i]->iLevel << "\t"
				<< m_pEquipList[i]->iHp << "\t"
				<< m_pEquipList[i]->iDef << "\t"
				<< m_pEquipList[i]->iAttack << endl << endl;
				
		}
	}
	if (m_pEquipState >= EQUIP_COUT)
		cout << "-->     返回";
	else
		cout << "        返回";
	cout << endl << endl;
	cout << " 按下return键将道具放回背包" <<endl;
	cout << "              玩家属性                " << endl;
	cout << "|   等级：" << m_iLevel << endl;
	cout << "|   攻击力：" << m_iattack << endl;
	cout << "|   防御力：" << m_iDef << endl;
	cout << "|   金钱：" << m_iMoney << endl;
	cout << "|   血量: " << m_iHp << endl<<endl;
	cout << "|   当前木材数：" << g_iWood << endl;
	cout << "|   当前草藤数：" << g_iGrass << endl;
	cout << "|   当前铁矿数：" << g_iIron << endl;
}

void CPlayer::upDataInfo(int *pState)
{
	if (KEYDOWN(VK_ESCAPE))
	{
		*pState = PLACE_MAP;
		m_iPlayerState = PLAYER_NONE;
	}
	else if (KEYDOWN(VK_UP))
	{
		m_pEquipState--;
		if (m_pEquipState < 0)
			m_pEquipState = 0;
	}
	else if (KEYDOWN(VK_DOWN))
	{
		m_pEquipState++;
		if (m_pEquipState>EQUIP_COUT)
			m_pEquipState = EQUIP_COUT;
	}
	else if (KEYDOWN(VK_RETURN))
	{
		if (m_pEquipState == EQUIP_COUT)
		{
			*pState = PLACE_MAP;
			m_iPlayerState = PLAYER_NONE;
		}
		else
		{
			if (m_pEquipList[m_pEquipState])
			{
				if (posItem(m_pEquipList[m_pEquipState]))
				{
					g_iGameBaby = BABY_NONE;
					m_pEquipList[m_pEquipState] = NULL;
				}
				else
					MessageBox(NULL, _T("背包已满"), _T("警告"), MB_OK);
			}
		}
	}
}