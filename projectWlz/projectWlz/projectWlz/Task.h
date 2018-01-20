#pragma once
#include"Player.h"
#include"Npc.h"
#include "GameTask.h"

class CTask
{
public:
	CTask();
	~CTask();


	bool isSetTask();

	void setTaskRole(CPlayer *pPlayer, CNpc *pNpc);

	void upData(int *iMapState);

	void onRender();


private:
	CPlayer *m_pUser;
	CNpc *m_pNpc;
	int m_iState;	//¼ýÍ·×´Ì¬

	map<int, DOTASK*> m_nList;

	DOTASK *m_pCurTask;
};
	

