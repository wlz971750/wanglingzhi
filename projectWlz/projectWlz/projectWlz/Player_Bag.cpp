#include "stdafx.h"
#include "Player.h"

bool CPlayer::addItem(ITEM *pItem)
{
	for (int i = 0; i < BAG_COUT; i++)
	{
		if (m_pBagList[i] == NULL)
		{
			m_pBagList[i] = pItem;
			m_iMoney -= pItem->iMoney;

			return true;
		}
	}
	return false;
}

bool CPlayer::posItem(ITEM *pItem)
{
	for (int i = 0; i < BAG_COUT; i++)
	{
		if (m_pBagList[i] == NULL)
		{
			m_pBagList[i] = pItem;
			m_iattack -= pItem->iAttack;
			m_iDef -= pItem->iDef;
			m_iHp -= pItem->iHp;
			return true;
		}
	}
	return false;
}

void  CPlayer::drawBag()
{
	cout << "\t\t����\t�ȼ�\t����\t����\t����\t�ۼ�" << endl << endl;
	
	for (int i=0; i<BAG_COUT; i++)
	{
	
		if (m_pBagState == i)
		{
			cout << "-->     ";
			m_index = i;
		}
		else
			cout << "        ";
		if (m_pBagList[i]==NULL)
			cout << "��λ" << endl<<endl;
		else 
		{
			cout << "\t" << m_pBagList[i]->szName << "\t"
				<< m_pBagList[i]->iLevel << "\t"
				<< m_pBagList[i]->iHp << "\t"
				<< m_pBagList[i]->iDef << "\t"
				<< m_pBagList[i]->iAttack << "\t"
				<< m_pBagList[i]->iMoney*0.8 << endl << endl;
		}
	}	
	if (m_pBagState >= BAG_COUT)
		cout << "-->     ����";
	else
		cout << "        ����";
	cout << endl<<endl;
	cout << "�ڱ����ﰴ��return��װ������" << endl;
	cout << "�ڵ����ﰴ��space�����۵���" << endl;
}

void CPlayer::upDataBag(int *pState)
{
	if (KEYDOWN(VK_ESCAPE))
	{
		*pState = PLACE_MAP;
		m_iPlayerState = PLAYER_NONE;
		m_isSell = false;
		m_isEquip = true;
	}
	else if (KEYDOWN(VK_UP))
	{
		m_pBagState--;
		if (m_pBagState < 0)
			m_pBagState = 0;
	}
	else if (KEYDOWN(VK_DOWN))
	{
		m_pBagState++;
		if (m_pBagState>BAG_COUT)
			m_pBagState = BAG_COUT;
	}
	else if (KEYDOWN(VK_RETURN))
	{
		if (m_isEquip == false)
			return;
		if (m_pBagState == BAG_COUT)
		{
			*pState = PLACE_MAP;
			m_iPlayerState = PLAYER_NONE;
		}
		else
		{
			if (m_index != -1 && m_pBagList[m_index] && m_iLevel >= m_pBagList[m_index]->iLevel)
			{	
				m_iattack = m_iattack + m_pBagList[m_index]->iAttack;
				m_iDef = m_iDef + m_pBagList[m_index]->iDef;
				m_iHp = m_iHp + m_pBagList[m_index]->iHp;
				if (m_pBagList[m_index]->iID == 2018)
					g_iGameBaby = BABY_HORSE;
				else if (m_pBagList[m_index]->iID == 2017)
					g_iGameBaby = BABY_DOG;
				else if (m_pBagList[m_index]->iID == 2019)
					g_iGameBaby = BABY_LION;
				else if (m_pBagList[m_index]->iID == 2020)
					g_iGameBaby = BABY_TIGER;
				if (m_pBagList[m_index]->iType > 1)
					m_pBagList[m_index] = addEquip(m_pBagList[m_index]);
				else
				{
					m_pBagList[m_index] = NULL;
					MessageBox(NULL, _T("�ɹ��ָ�����ֵ"), _T("��ʾ"), MB_OK);
				}
			}
			else 
				MessageBox(NULL, _T("��ǰ�ȼ�����������װ����"), _T("��ʾ"), MB_OK);
		}
	}
	else if (KEYDOWN(VK_SPACE))
	{
		if (m_isSell ==false)
			return;
		if (m_pBagState != BAG_COUT&&m_index != -1 && m_pBagList[m_index])
		{
			m_iMoney = m_iMoney + m_pBagList[m_index]->iMoney*0.8;
			m_pBagList[m_index] = NULL;
		}
	}
		
}