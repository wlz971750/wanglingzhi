#pragma once
#include"Monster.h"
#include"Player.h"
enum
{	
	FIGHT_NONE,
	FIGHT_START,			//ս����ʼǰ
	FIGHT_ONE,
	FIGHT_TOW,
	FIGHT_THREE,
	FIGHT_START2,
	FIGHT_FOUR,
	FIGHT_FIVE,
	FIGHT_SIX,
	FIGHT_SEVEN,
	FIGHT_EIGHT,
};

enum
{
	FIGHT_MAP,				//ս������
	FIGHT_INFO,				//�����Ϣ����
};

class CGameFight
{
public:
	CGameFight();
	~CGameFight();

	void setFightRole(CPlayer *pPlayer, CMonster *pMons);

	void upData(int *pMapState);

	void onRender();


private:
	CPlayer *m_pUser;
	CMonster *m_pMons;

	int m_iFinghtState;
	int m_iFihgtInfo;

	int m_index;
};

