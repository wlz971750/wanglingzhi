#pragma once
#include"GameObject.h"
#include"GameItem.h"
#include"GameTask.h"

const int BAG_COUT = 8;			//8����λ��
const int EQUIP_COUT = 6;		//6����λ��
const int TASK_COUT = 1;		//������1������

enum
{
	PLAYER_NONE,		//Ĭ��
	PLAYER_BAG,			//����
	PLAYER_INFO,		//����
	PLAYER_TASK,		//������״̬
	PLAYER_TASKDOING,	//������״̬
	PLAYER_OPERATE,		//��������
};

class CPlayer :public CGameObject
{
public:
	CPlayer();
	~CPlayer();

	void upData(int *pState);

	void onRender();

	void rePos();

	void upLevel();	//�������
	
	void setPlayerState(int iState){ m_iPlayerState = iState; }		//ȡ���״̬

/////////////////////////////////////////////////////////////////////////////////////
//����
public:

	ITEM *m_pBagList[BAG_COUT];
	int m_pBagState;
	int m_index;			//��������λ��
	bool m_isSell;			//�Ƿ����
	bool m_isEquip;			//�Ƿ��װ��
	bool addItem(ITEM *pItem);			//������Ʒ

	bool posItem(ITEM *pItem);			//װ���Żر���

	void drawBag();		//��Ⱦ����

	void upDataBag(int *pState);

	ITEM *addBag(ITEM *pItem);			

	void setSell(bool bSell){ m_isSell = bSell; }
	
	void setEquip(bool bEquip){ m_isEquip = bEquip; }

/////////////////////////////////////////////////////////////////////////////////////
//װ�� ����
public:

	ITEM *m_pEquipList[EQUIP_COUT];
	int m_pEquipState;
	int m_iPosNum;			//��ǰװ������λ��

	void upDataInfo(int *pState);

	void drawInfo();

	ITEM *addEquip(ITEM *pItem);

////////////////////////////////////////////////////////////////////////////////////
//������
	
public:

	int m_pTaskState;
	int m_iCode;

	bool addTask(DOTASK *pTask);			//��������

	DOTASK *m_pTaskList[TASK_COUT];

	void drawTask();

	void upDataTask(int *pState);


//������
	int m_iNumb;
	int m_pDoTask;

	DOTASK *m_pDoTaskList[TASK_COUT];

	bool addDoTask(DOTASK *pDoTask);

	void drawDoTask();

	void upDataDoTask(int *pState);


////////////////////////////////////////////////////////////////////////////////////
//����

public:
	int m_iPetRow;		//�����ʼ����
	int m_iPetCol;

///////////////////////////////////////////////////////////////////////////////////
//��������
	int m_iOpeState;

	void drawOperate();

	void upDataOperate(int *pState);


private:
	int m_iRowBk, m_iColBk;	//�����������

	int m_iBkPetRow;		//������������
	int m_iBkPetCol;

	int m_iPlayerState;		//���״̬

};

