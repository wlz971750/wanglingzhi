// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  在此处引用程序需要的其他头文件
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>
using namespace std;

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
//* VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_H 0x48  
#define VK_L 0x4c
#define VK_P 0x50
#define VK_V 0x56
#define VK_M 0x4d
#define VK_N 0x4e
#define VK_O 0x4f 

enum
{
	GAME_MENU,
	GAME_START,				//游戏说明界面
	GAME_MAP,
	GAME_EXIT,
};
extern int g_iGameState;	//控制游戏状态


//////////////////////////////////////
//坐骑
enum
{
	BABY_NONE,
	BABY_DOG,
	BABY_HORSE,			//马
	BABY_TIGER,			//虎
	BABY_LION,			//狮
	
};
extern int g_iGameBaby;


//////////////////////////////////////
//各种场所
enum
{
	PLACE_MAP,      // 普通场所	
	PLACE_FIGHT,    // 战斗场所
	PLACE_TALK,     // 对话场所
	PLACE_GAIN,		// 收获场所
	PLACE_SHOP,		//	商店
	PLACE_TASK,		//	任务
	PLACE_PLAYER,	//	玩家（背包、属性、任务）
};


//////////////////////////////////////
//任务
enum
{
	TASK_NONE,		    //无任务
	TASK_ONE,		    //任务1
	TASK_TOW, 
	TASK_THREE,
	TASK_FOUR,
	TASK_FIVE,
	TASK_SIX,
	TASK_SEVEN,
};
extern int g_iNumber;	//做第几个任务

enum
{
	TASK_NODO,		    //任务没有完成
	TASK_ONEDONE,		//任务1完成
	TASK_TOWDONE,
	TASK_THREEDONE,
	TASK_FOURDONE,
	TASK_FIVEDONE,
	TASK_SIXDONE,
	TASK_SEVENDONE,
};
extern int g_iCode;		//任务是否完成

enum
{
	NPC_NONE,
	NPC_PASSER=10,		//路人
	NPC_MERMAID,		//美人鱼
	NPC_GOD,			//神人
};
extern int g_igetNpcType;	//提交任务时的npc类型

extern int g_isetNpcType;	//接受任务时的npc类型

///////////////////////////////////////
//材料

extern bool g_bBoat;	//是否有船
extern bool g_bFly;		//是否能上天
extern bool g_bCord;	//是否有绳子

extern int g_iGrass;	//草
extern int g_iWood;		//木
extern int g_iIron;		//铁