// projectWlz.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"GameManager.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CGameManager *pGame = new  CGameManager();
	while (true)
	{
		system("cls");
		pGame->upData();
		pGame->onRender();

		if (g_iGameState == GAME_EXIT)
			break;
		Sleep(60);
	}

	delete pGame;
	return 0;
}

