#pragma once
#include<map>
#include"Player.h"
#include"AllNpc.h"
#include"AllMonster.h"
#include"AllMaterial.h"
#include"GameFight.h"
#include"GameTalk.h"
#include"Shop.h"
#include"Task.h"
#include"Gain.h"

using namespace std;

enum{
	MAP_NONE,
	MAP_WALL,
	MAP_SEA,
	MAP_CHASM,		//…Ó‘®
	MAP_MON,		//…Ω
	MAP_DOOR=100,
	MAP_SKY=105,	//ÃÏø’
};

const int MAX_ROW = 15;
const int MAX_COL = 25;

struct MAPDATA{
	int iID;
	char szName[32];
	int iBirthRow, iBirthCol;
	int iData[MAX_ROW][MAX_COL];
};

class CGameMap
{
public:
	CGameMap();
	~CGameMap();

	void readFileMap(char *pFileName);

	void getMapID(int iID);

	void upData();

	void onRender();

	void drawMap();

	int g_iCurMap[MAX_ROW][MAX_COL];

	int g_iPlace;


private:
	map<int, MAPDATA*>  m_nMapList;
	MAPDATA *m_pCurMap;

	CPlayer *m_pUser;
	CMonster *m_pMons;
	CAllNpc *m_pAllNpc;
	CAllMonster *m_pAllMonster;
	CAllMaterial *m_pAllMaterial;
	CGameFight *m_pFight;
	CGameTalk *m_pTalk;
	CShop *m_pShop;
	CTask *m_pTask;
	CGain *m_pGain;


private:
	void _isCollWall();
};

