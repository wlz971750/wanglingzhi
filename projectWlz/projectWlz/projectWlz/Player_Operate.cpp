#include "stdafx.h"
#include "Player.h"

void CPlayer::drawOperate()
{
	if (m_iOpeState == 0)
	{
		cout << "--------------------------------------------------------" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                     ������ʾ                         |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                     B��������                        |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                     C����װ����                      |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                     A����������                      |" << endl;
		cout << "|                                         ����EAS�˳�  |" << endl;
		cout << "--------------------------------------------------------" << endl;
	}
	else
	{
		cout << "--------------------------------------------------------" << endl;
		cout << "|                                                      |" << endl;
		cout << "|           ͬʱ����DEF������ҷ����޵�                |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|           ͬʱ����ACK������ҹ����޵�                |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|           ͬʱ����MON�����������Ǯ                  |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|           ͬʱ����HP�������Ѫ���޵�                 |" << endl;
		cout << "|                                         ����EAS�˳�  |" << endl;
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