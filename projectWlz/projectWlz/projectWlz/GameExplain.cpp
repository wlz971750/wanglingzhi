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
	cout << "|     ��˹�ز�ʿ����ʿ���ܾ�����ҵ���     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   �������� .��ħ��̹���ڴݲ��������     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   �磬�������������˵����� .ɱ����̹     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   �������˾ͻ�õ����� .�����������     |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   ��һЩ�����ý��������Լ����ǿ��.    |" << endl;
	cout << "|                                          |" << endl;
	cout << "|   ף����˰ɣ�                           |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "--------------------------------------------" << endl;
}


