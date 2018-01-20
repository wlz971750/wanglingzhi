#include "stdafx.h"
#include "GameManager.h"
#include"GameItem.h"
#include"GameTask.h"

int g_iGameState = GAME_MENU;
int g_iNumber = TASK_NONE;
int g_iCode = TASK_NODO;
int g_igetNpcType = NPC_NONE;
int g_isetNpcType = NPC_NONE;
int g_iGameBaby = BABY_NONE;
bool g_bBoat = false;
bool g_bFly = false;
bool g_bCord = false;
int g_iGrass = 0;
int g_iWood = 0;
int g_iIron = 0;

CGameManager::CGameManager()
{

	m_pMenu = new CGameMenu();
	m_pMap = new CGameMap();
	m_pExplain = new CGameExplain();

	m_pMap->readFileMap("Data/map.txt");
	m_pMap->getMapID(101);

	CGameItem::getItem();
	CGameTask::getTask();

}

CGameManager::~CGameManager()
{
	delete m_pMenu;
	m_pMenu = NULL;

	delete m_pMap;
	m_pMap = NULL;

	delete m_pExplain;
	m_pExplain = NULL;
}

void CGameManager::upData()
{
	if (g_iGameState == GAME_MENU)
		m_pMenu->upDate();
	else if (g_iGameState == GAME_START)
		m_pExplain->upData();
	else if (GAME_MAP == GAME_MAP)
		m_pMap->upData();
}

void CGameManager::onRender()
{
	if (g_iGameState == GAME_MENU)
		m_pMenu->onRender();
	else if (g_iGameState == GAME_START)
		m_pExplain->onRender();
	else if (GAME_MAP == GAME_MAP)
		m_pMap->onRender();
}
