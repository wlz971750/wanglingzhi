#pragma once
#include"GameObject.h"
#include"GameItem.h"
#include"GameTask.h"

const int BAG_COUT = 8;			//8背包位置
const int EQUIP_COUT = 6;		//6穿戴位置
const int TASK_COUT = 1;		//最多接受1个任务

enum
{
	PLAYER_NONE,		//默认
	PLAYER_BAG,			//背包
	PLAYER_INFO,		//属性
	PLAYER_TASK,		//接任务状态
	PLAYER_TASKDOING,	//做任务状态
	PLAYER_OPERATE,		//操作介绍
};

class CPlayer :public CGameObject
{
public:
	CPlayer();
	~CPlayer();

	void upData(int *pState);

	void onRender();

	void rePos();

	void upLevel();	//玩家升级
	
	void setPlayerState(int iState){ m_iPlayerState = iState; }		//取玩家状态

/////////////////////////////////////////////////////////////////////////////////////
//背包
public:

	ITEM *m_pBagList[BAG_COUT];
	int m_pBagState;
	int m_index;			//背包道具位置
	bool m_isSell;			//是否可卖
	bool m_isEquip;			//是否可装备
	bool addItem(ITEM *pItem);			//购买商品

	bool posItem(ITEM *pItem);			//装备放回背包

	void drawBag();		//渲染背包

	void upDataBag(int *pState);

	ITEM *addBag(ITEM *pItem);			

	void setSell(bool bSell){ m_isSell = bSell; }
	
	void setEquip(bool bEquip){ m_isEquip = bEquip; }

/////////////////////////////////////////////////////////////////////////////////////
//装备 属性
public:

	ITEM *m_pEquipList[EQUIP_COUT];
	int m_pEquipState;
	int m_iPosNum;			//当前装备道具位置

	void upDataInfo(int *pState);

	void drawInfo();

	ITEM *addEquip(ITEM *pItem);

////////////////////////////////////////////////////////////////////////////////////
//接任务
	
public:

	int m_pTaskState;
	int m_iCode;

	bool addTask(DOTASK *pTask);			//接受任务

	DOTASK *m_pTaskList[TASK_COUT];

	void drawTask();

	void upDataTask(int *pState);


//做任务
	int m_iNumb;
	int m_pDoTask;

	DOTASK *m_pDoTaskList[TASK_COUT];

	bool addDoTask(DOTASK *pDoTask);

	void drawDoTask();

	void upDataDoTask(int *pState);


////////////////////////////////////////////////////////////////////////////////////
//坐骑

public:
	int m_iPetRow;		//坐骑初始坐标
	int m_iPetCol;

///////////////////////////////////////////////////////////////////////////////////
//操作介绍
	int m_iOpeState;

	void drawOperate();

	void upDataOperate(int *pState);


private:
	int m_iRowBk, m_iColBk;	//备份玩家坐标

	int m_iBkPetRow;		//备份坐骑坐标
	int m_iBkPetCol;

	int m_iPlayerState;		//玩家状态

};

