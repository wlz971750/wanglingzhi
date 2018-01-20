#pragma once
#include"Player.h"
#include"Material.h"

enum
{
	GAIN_START,		//准备收获
	GAIN_ONE,
	GAIN_TOW,
	GAIN_THREE,
	GAIN_FOUR,
	GAIN_FIVE,
	GAIN_SIX,
	GAIN_SEVEN,
};

class CGain
{
public:
	CGain();
	~CGain();

	void getGainRole(CPlayer *pPlayer, CMaterial *pMater);

	void upData(int *pMapState);

	void onRender();

	CMaterial *getMaterial(){ return m_pMater; }

	CPlayer *getUser(){ return m_pUser; }

private:
	CPlayer *m_pUser;
	CMaterial *m_pMater;

	int m_iGainState;
	int m_index;
};

