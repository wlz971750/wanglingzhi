#pragma once
#include"Player.h"
#include"Npc.h"
#include"GameItem.h"


class CShop
{
public:
	CShop();
	~CShop();

	bool isSetShop();

	void setShopRole(CPlayer *pPlayer, CNpc *pNpc);

	void upData(int *iMapState);

	void onRender();

private:
	CPlayer *m_pUser;
	CNpc *m_pNpc;
	int m_iArrState;				//��ͷ״̬

	map<int, ITEM*> m_nList;		//�̵��б�

	ITEM	*m_pCurItem;

};

