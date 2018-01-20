#include "stdafx.h"
#include "GameMenu.h"


CGameMenu::CGameMenu()
{
	m_iMenuState = MENU_START;
}


CGameMenu::~CGameMenu()
{
}

void CGameMenu::upDate()
{
	if (KEYDOWN(VK_UP))
	{
		m_iMenuState--;
		if (m_iMenuState < MENU_START)
			m_iMenuState = MENU_EXIT;
	}
	else if (KEYDOWN(VK_DOWN))
	{
		m_iMenuState++;
		if (m_iMenuState > MENU_EXIT)
			m_iMenuState = MENU_START;
	}
	else if (KEYDOWN(VK_RETURN))
	{
		if (m_iMenuState == MENU_EXIT)
			g_iGameState = GAME_EXIT;
		else
			g_iGameState = GAME_START;
	}
}

void CGameMenu::onRender()
{
	cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■                                ■■" << endl;
	cout << "■■           失落的神灵           ■■" << endl;
	cout << "■■                                ■■" << endl;
	cout << "■■                                ■■" << endl;
	cout << "■■                                ■■" << endl;

	if (m_iMenuState == MENU_START)
	{
		cout << "■■       ->   开始游戏            ■■" << endl;
		cout << "■■                                ■■" << endl;
		cout << "■■            退出游戏            ■■" << endl;
	}
	else
	{
		cout << "■■            开始游戏            ■■" << endl;
		cout << "■■                                ■■" << endl;
		cout << "■■       ->   退出游戏            ■■" << endl;
	}
	cout << "■■                                ■■" << endl;
	cout << "■■                                ■■" << endl;
	cout << "■■                                ■■" << endl;
	cout << "■■                 山顶洞人工作室 ■■" << endl;
	cout << "■■                                ■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
}
