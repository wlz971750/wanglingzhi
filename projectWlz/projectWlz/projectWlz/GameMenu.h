#pragma once


enum
{
	MENU_START,
	MENU_EXIT,
};


class CGameMenu
{
public:
	CGameMenu();
	~CGameMenu();

	int m_iMenuState;

	void upDate();

	void onRender();
};

