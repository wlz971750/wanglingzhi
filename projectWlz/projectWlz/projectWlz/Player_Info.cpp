#include "stdafx.h"
#include "Player.h"

char g_szPosName[EQUIP_COUT][7] = 
{
	{ "ͷ����" },
	{ "������" },
	{ "���ף�" },
	{ "Ь�ӣ�" },
	{ "������" },
	{ "���" },
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
	cout << "\tλ��\t����\t�ȼ�\t����\t����\t����" << endl << endl;

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
			cout << "��λ" << endl<<endl;
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
		cout << "-->     ����";
	else
		cout << "        ����";
	cout << endl << endl;
	cout << " ����return�������߷Żر���" <<endl;
	cout << "              �������                " << endl;
	cout << "|   �ȼ���" << m_iLevel << endl;
	cout << "|   ��������" << m_iattack << endl;
	cout << "|   ��������" << m_iDef << endl;
	cout << "|   ��Ǯ��" << m_iMoney << endl;
	cout << "|   Ѫ��: " << m_iHp << endl<<endl;
	cout << "|   ��ǰľ������" << g_iWood << endl;
	cout << "|   ��ǰ��������" << g_iGrass << endl;
	cout << "|   ��ǰ��������" << g_iIron << endl;
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
					MessageBox(NULL, _T("��������"), _T("����"), MB_OK);
			}
		}
	}
}