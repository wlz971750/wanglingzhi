// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
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
	GAME_START,				//��Ϸ˵������
	GAME_MAP,
	GAME_EXIT,
};
extern int g_iGameState;	//������Ϸ״̬


//////////////////////////////////////
//����
enum
{
	BABY_NONE,
	BABY_DOG,
	BABY_HORSE,			//��
	BABY_TIGER,			//��
	BABY_LION,			//ʨ
	
};
extern int g_iGameBaby;


//////////////////////////////////////
//���ֳ���
enum
{
	PLACE_MAP,      // ��ͨ����	
	PLACE_FIGHT,    // ս������
	PLACE_TALK,     // �Ի�����
	PLACE_GAIN,		// �ջ���
	PLACE_SHOP,		//	�̵�
	PLACE_TASK,		//	����
	PLACE_PLAYER,	//	��ң����������ԡ�����
};


//////////////////////////////////////
//����
enum
{
	TASK_NONE,		    //������
	TASK_ONE,		    //����1
	TASK_TOW, 
	TASK_THREE,
	TASK_FOUR,
	TASK_FIVE,
	TASK_SIX,
	TASK_SEVEN,
};
extern int g_iNumber;	//���ڼ�������

enum
{
	TASK_NODO,		    //����û�����
	TASK_ONEDONE,		//����1���
	TASK_TOWDONE,
	TASK_THREEDONE,
	TASK_FOURDONE,
	TASK_FIVEDONE,
	TASK_SIXDONE,
	TASK_SEVENDONE,
};
extern int g_iCode;		//�����Ƿ����

enum
{
	NPC_NONE,
	NPC_PASSER=10,		//·��
	NPC_MERMAID,		//������
	NPC_GOD,			//����
};
extern int g_igetNpcType;	//�ύ����ʱ��npc����

extern int g_isetNpcType;	//��������ʱ��npc����

///////////////////////////////////////
//����

extern bool g_bBoat;	//�Ƿ��д�
extern bool g_bFly;		//�Ƿ�������
extern bool g_bCord;	//�Ƿ�������

extern int g_iGrass;	//��
extern int g_iWood;		//ľ
extern int g_iIron;		//��