#include "stdafx.h"
#include "GameExplain.h"



CGameExplain::CGameExplain()
{
}


CGameExplain::~CGameExplain()
{
}

void CGameExplain::upData()
{
	if (KEYDOWN(VK_ESCAPE))
		g_iGameState = GAME_MENU;
	else if (KEYDOWN(VK_RETURN))
		g_iGameState = GAME_MAP;
}

void CGameExplain::onRender()
{
	cout << "--------------------------------------------" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "|     崔斯特博士：勇士，很惊讶你敢单独     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   来到这里 .恶魔撒坦正在摧残着这个世     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   界，限制着神明大人的自由 .杀死撒坦     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   神明大人就会得到自由 .但是你必须完     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   成一些任务获得奖励，让自己变得强大.    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   祝你好运吧！                           |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl;
}


