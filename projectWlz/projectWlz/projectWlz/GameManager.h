#pragma once
#include"GameMenu.h"
#include"GameMap.h"
#include"GameExplain.h"


class CGameManager
{
public:
	CGameManager();
	~CGameManager();

	void upData();

	void onRender();


private:
	CGameMenu *m_pMenu;
	CGameMap *m_pMap;
	CGameExplain *m_pExplain;
};

