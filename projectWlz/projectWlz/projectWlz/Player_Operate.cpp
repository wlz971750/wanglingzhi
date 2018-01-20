#include "stdafx.h"
#include "Player.h"

void CPlayer::drawOperate()
{
	if (m_iOpeState == 0)
	{
		cout << "--------------------------------------------------------" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                     操作提示                         |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                     B键：背包                        |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                     C键：装备栏                      |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                     A键：任务栏                      |" << endl;
		cout << "|                                         按下EAS退出  |" << endl;
		cout << "--------------------------------------------------------" << endl;
	}
	else
	{
		cout << "--------------------------------------------------------" << endl;
		cout << "|                                                      |" << endl;
		cout << "|           同时按下DEF键：玩家防御无敌                |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|           同时按下ACK键：玩家攻击无敌                |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|           同时按下MON键：玩家满金钱                  |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|           同时按下HP键：玩家血量无敌                 |" << endl;
		cout << "|                                         按下EAS退出  |" << endl;
		cout << "--------------------------------------------------------" << endl;
	}
}

void  CPlayer::upDataOperate(int *pState)
{
	if (KEYDOWN(VK_ESCAPE))
	{
		m_iOpeState = 0;
		*pState = PLACE_MAP;
		m_iPlayerState = PLAYER_NONE;
	}
	else if (KEYDOWN(VK_SPACE))
		m_iOpeState = 1;
}