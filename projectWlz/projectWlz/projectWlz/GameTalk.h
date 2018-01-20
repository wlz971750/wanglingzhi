#pragma once
#include"Player.h"
#include"Npc.h"

enum
{
	TALK_SHOP,
	TALK_SELL,
	TALK_TASK,
	TALK_PASSTASK,
	TALK_EXIT,
};

enum
{
	TALK_BLOAT,
	TALK_FLY,
	TALK_CORD,
	TALK_RETURN,
};
class CGameTalk
{
public:
	CGameTalk();
	~CGameTalk();
	
	void setTalkRole(CPlayer *pPlayer, CNpc *pNpc);

	void upData(int *pMapState);

	void onRender();

	CNpc *getNpc(){ return m_pNpc; }

	CPlayer *getUser(){ return m_pUser; }

private:
	CPlayer *m_pUser;
	CNpc *m_pNpc;

	int m_iTalk;
	int m_iTalks;
};



