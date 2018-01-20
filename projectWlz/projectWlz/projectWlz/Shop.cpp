#include "stdafx.h"
#include "Shop.h"


CShop::CShop()
{
	m_pUser = NULL;
	m_pNpc = NULL;
	m_pCurItem = NULL;
	m_iArrState = 0;
}


CShop::~CShop()
{
	ITEM *pData = NULL;
	map<int, ITEM*>::iterator iter = m_nList.begin();
	for (; iter != m_nList.end(); iter++)
	{
		pData = (*iter).second;
		delete pData;
	}
	m_nList.clear();
}

bool CShop::isSetShop()
{
	if (m_pUser == NULL || m_pNpc == NULL)
		return false;
	return true;
}

void CShop::setShopRole(CPlayer *pPlayer, CNpc *pNpc)
{
	m_pUser = pPlayer;
	m_pNpc = pNpc;
	CGameItem *pItem = CGameItem::getItem();
	m_nList.clear();
	m_nList = pItem->getCurItem(m_pNpc->m_iType);

}

void CShop::upData(int *iMapState)
{
	if (KEYDOWN(VK_ESCAPE))
	{
		*iMapState = PLACE_MAP;
		m_pUser = NULL;
		m_pNpc = NULL;
	}
	else if (KEYDOWN(VK_UP))
	{
		m_iArrState--;
		if (m_iArrState < 0)
			m_iArrState = 0;
	}
	else if (KEYDOWN(VK_DOWN))
	{
		m_iArrState++;
		if (m_iArrState>m_nList.size())
			m_iArrState = m_nList.size();
	}
	else if (KEYDOWN(VK_RETURN))
	{
		if (m_iArrState == m_nList.size())
		{
			*iMapState = PLACE_MAP;
			m_pUser = NULL;
			m_pNpc = NULL;
		}
		else
		{
			if (m_pCurItem)
			{
				if (m_pCurItem->iMoney <= m_pUser->m_iMoney)
				{
					if (m_pUser->addItem(m_pCurItem))
					{
						MessageBox(NULL, _T("����ɹ���"), _T("��ϲ"), MB_OK);
						g_iCode = TASK_THREEDONE;		//����3��ɣ�
					}
					else
						MessageBox(NULL, _T("����������"), _T("��ʾ"), MB_OK);
				}
			
				else
					MessageBox(NULL, _T("��Ǯ���㣡"), _T("��ʾ"), MB_OK);
			}
		}
	}
}

void CShop::onRender()
{
	if (m_pUser == NULL || m_pNpc == NULL)
		return;
	cout << "\t��Ľ�ң�" << m_pUser->m_iMoney << endl;
	cout << "\t����return��������Ʒ" << endl<<endl;
	ITEM *pItem = NULL;
	int iCout = 0;
	
	cout << "\t����\t�ȼ�\t����\t����\t����\t��Ǯ" << endl << endl;
	map<int, ITEM*>::iterator iter = m_nList.begin();
	for (; iter != m_nList.end(); iter++)
	{	
		pItem = (*iter).second;	
		if (m_iArrState == iCout)
		{
			cout << "-->";
			m_pCurItem = pItem;
		}
		else
			cout << "    ";
		cout << "\t" << pItem->szName << "\t"
			<< pItem->iLevel << "\t"
			<< pItem->iHp << "\t"
			<< pItem->iDef << "\t"
			<< pItem->iAttack << "\t"
			<< pItem->iMoney << endl << endl;	

		iCout++;
	}
	if (m_iArrState == m_nList.size())
		cout << "-->	����";
	else
		cout << "	����"<<endl;

}

	

