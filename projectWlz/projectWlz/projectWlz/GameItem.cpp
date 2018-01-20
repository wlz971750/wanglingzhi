#include "stdafx.h"
#include "GameItem.h"


static CGameItem *s_pItem = NULL;
CGameItem *CGameItem::getItem()
{
	if (s_pItem == NULL)
	{
		s_pItem = new CGameItem();
		s_pItem->readItemFile("Data/item.txt");
	}
	return s_pItem;
}

CGameItem::CGameItem()
{
}


CGameItem::~CGameItem()
{
}


void CGameItem::readItemFile(char *ItemFile)
{
	fstream file(ItemFile);
	if (file)
	{
		getline(file, string());
		while (true)
		{
			ITEM *pItem = new ITEM;
			file >> pItem->iID
				>> pItem->szName
				>> pItem->iType
				>>pItem->iPos
				>>pItem->iLevel
				>> pItem->iHp
				>> pItem->iDef
				>> pItem->iAttack
				>> pItem->iPower
				>> pItem->iAgility
				>> pItem->iIntell
				>> pItem->iMoney;
			if (strlen(pItem->szName) <= 0)
			{
				delete pItem;
				break;
			}
			m_pItemList[pItem->iID] = pItem;
		}
	}
	file.clear();
	file.close();
}


//匹配好货物类型
map<int, ITEM*>	CGameItem::getCurItem(int iType)
{

	map<int, ITEM*> nList;
	map<int, ITEM*>::iterator iter = m_pItemList.begin();
	for (; iter != m_pItemList.end(); iter++)
	{
		ITEM *pItem = (*iter).second;
		if (pItem->iType == iType)
		{
			nList[pItem->iID] = pItem;
		}

	}
	return nList;
}