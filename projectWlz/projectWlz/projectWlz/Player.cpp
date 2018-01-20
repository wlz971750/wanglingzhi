#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	m_iRowBk = m_iRow;
	m_iColBk = m_iCol;

	m_iPlayerState = PLAYER_NONE;

//背包
	m_pBagState = 0;
	m_index = -1;
	for (int i = 0; i < BAG_COUT; i++)
		m_pBagList[i] = NULL;

	m_isSell = false;
	m_isEquip = true;

//装备属性
	m_pEquipState = 0;
	m_iPosNum = -1;
	for (int i = 0; i < EQUIP_COUT; i++)
		m_pEquipList[i] = NULL;

//任务
	m_pTaskState = 0;
	m_iCode = -1;
	for (int i = 0; i < TASK_COUT; i++)
		m_pTaskList[i] = NULL;

//做任务
	m_iNumb = -1;
	m_pDoTask = 0;
	for (int i = 0; i < TASK_COUT; i++)
		m_pDoTaskList[i] = NULL;


	m_iPetRow = 1;
	m_iPetCol = 13;


//操作提示
	m_iOpeState = 0;
}


CPlayer::~CPlayer()
{

}

void CPlayer::upData(int *pState)
{
	if (m_iPlayerState == PLAYER_NONE)
	{
		m_iRowBk = m_iRow;
		m_iColBk = m_iCol;

		m_iBkPetRow = m_iPetRow;
		m_iBkPetCol = m_iPetCol;

		if (KEYDOWN(VK_LEFT))
		{																				
			m_iPetCol = m_iColBk;
			m_iPetRow = m_iRowBk;
			m_iCol--; 
		}
		else if (KEYDOWN(VK_RIGHT))
		{
			m_iPetCol = m_iColBk;
			m_iPetRow = m_iRowBk;
			m_iCol++;
		}
		else if (KEYDOWN(VK_UP))
		{
			m_iPetCol = m_iColBk;
			m_iPetRow = m_iRowBk;
			m_iRow--;
		}
		else if (KEYDOWN(VK_DOWN))
		{
			m_iPetCol = m_iColBk;
			m_iPetRow = m_iRowBk;
			m_iRow++;
		}
		else if (KEYDOWN(VK_B))
		{
			*pState = PLACE_PLAYER;
			m_iPlayerState = PLAYER_BAG;
		}
		else if (KEYDOWN(VK_C))
		{
			*pState = PLACE_PLAYER;
			m_iPlayerState = PLAYER_INFO;
		}
		else if (KEYDOWN(VK_A))
		{
			*pState = PLACE_PLAYER;
			m_iPlayerState = PLAYER_TASK;
		}
		else if (KEYDOWN(VK_TAB))
		{
			*pState = PLACE_PLAYER;
			m_iPlayerState = PLAYER_OPERATE;
		}

		if (KEYDOWN(VK_D)&&KEYDOWN(VK_E)&&KEYDOWN(VK_F))		
			m_iDef = 10000;
		if (KEYDOWN(VK_A) && KEYDOWN(VK_C))
			m_iattack = 10000;
		if (KEYDOWN(VK_H) && KEYDOWN(VK_P))
			m_iHp = 10000;
		if (KEYDOWN(VK_L) && KEYDOWN(VK_E) && KEYDOWN(VK_V))
			m_iLevel = 99;
		if (KEYDOWN(VK_M) && KEYDOWN(VK_O) && KEYDOWN(VK_N))
			m_iMoney = 10000;
	}	
	else if (m_iPlayerState == PLAYER_BAG)
		upDataBag(pState);
	else if (m_iPlayerState == PLAYER_INFO)
		upDataInfo(pState);
	else if (m_iPlayerState == PLAYER_TASK)
		upDataTask(pState);
	else if (m_iPlayerState == PLAYER_TASKDOING)
		upDataDoTask(pState);
	else if (m_iPlayerState == PLAYER_OPERATE)
		upDataOperate(pState);
}

void CPlayer::onRender()
{
	if (m_iPlayerState == PLAYER_NONE)
		cout << "♀";
	else if (m_iPlayerState == PLAYER_BAG)
		drawBag();
	else if (m_iPlayerState == PLAYER_INFO)
		drawInfo();
	else if (m_iPlayerState == PLAYER_TASK)
		drawTask();
	else if (m_iPlayerState == PLAYER_TASKDOING)
		drawDoTask();
	else if (m_iPlayerState == PLAYER_OPERATE)
		drawOperate();
}

void CPlayer::rePos()
{
	m_iRow = m_iPetRow;
	m_iCol = m_iPetCol;

	m_iPetRow = m_iBkPetRow;
	m_iPetCol = m_iBkPetCol;	
}

void CPlayer::upLevel()
{
	if (m_iNum >= 10 && m_iNum < 20 && m_iLevel == 1)
	{
		MessageBox(NULL, _T("终于升级啦！"), _T("提示"), MB_OK);
		m_iLevel++;
		m_iattack = m_iattack + 20;
		m_iHp = m_iHp + 10;
	}
	else if (m_iNum >= 20 && m_iNum < 30 && m_iLevel == 2)
	{
		MessageBox(NULL, _T("终于升级啦！"), _T("提示"), MB_OK);
		m_iLevel++;
		m_iattack = m_iattack + 30;
		m_iHp = m_iHp + 10;
	}
	else if (m_iNum >= 30 && m_iNum < 40 && m_iLevel == 3)
	{
		MessageBox(NULL, _T("终于升级啦！"), _T("提示"), MB_OK);
		m_iLevel++;
		m_iattack = m_iattack + 40;
		m_iHp = m_iHp + 20;
	}
	else if (m_iNum >= 40 && m_iNum < 50 && m_iLevel == 4)
	{
		MessageBox(NULL, _T("终于升级啦！"), _T("提示"), MB_OK);
		m_iLevel++;
		m_iattack = m_iattack + 50;
		m_iHp = m_iHp + 40;
	}
	else if (m_iNum >= 50 && m_iNum < 60 && m_iLevel == 5)
	{
		MessageBox(NULL, _T("终于升级啦！"), _T("提示"), MB_OK);
		m_iLevel++;
		m_iattack = m_iattack + 80;
		m_iHp = m_iHp + 70;
	}
	else if (m_iNum >= 60 && m_iNum < 70 && m_iLevel == 6)
	{
		MessageBox(NULL, _T("终于升级啦！"), _T("提示"), MB_OK);
		m_iLevel++;
		m_iattack = m_iattack + 100;
		m_iHp = m_iHp + 100;
	}
	else if (m_iNum >= 70 && m_iNum < 80 && m_iLevel == 7)
	{
		MessageBox(NULL, _T("终于升级啦！"), _T("提示"), MB_OK);
		m_iLevel++;
		m_iattack = m_iattack + 100;
		m_iHp = m_iHp + 100;
	}
	else if (m_iNum >= 80 && m_iNum < 90 && m_iLevel == 8)
	{
		MessageBox(NULL, _T("终于升级啦！"), _T("提示"), MB_OK);
		m_iLevel++;
		m_iattack = m_iattack + 100;
		m_iHp = m_iHp + 100;
	}
	else if (m_iNum >= 90 && m_iNum < 100 && m_iLevel == 9)
	{
		MessageBox(NULL, _T("终于升级啦！"), _T("提示"), MB_OK);
		m_iLevel++;
		m_iattack = m_iattack + 100;
		m_iHp = m_iHp + 100;
	}
	
}
