#include "stdafx.h"
#include "GameMap.h"



CGameMap::CGameMap()
{
	g_iPlace = PLACE_MAP;

	m_pUser = new CPlayer();
	m_pAllNpc = new CAllNpc();
	m_pAllMonster = new CAllMonster();
	m_pAllMaterial = new CAllMaterial();
	m_pFight = new CGameFight();
	m_pTalk = new CGameTalk();
	m_pShop = new CShop();
	m_pTask = new CTask();
	m_pGain = new CGain();

	m_pAllNpc->readFileNpc("Data/npc.txt");
	m_pAllMonster->readFile("Data/monster.txt");
	m_pAllMaterial->readFile("Data/material.txt");
}

CGameMap::~CGameMap()
{
	delete m_pUser;
	m_pUser = NULL;

	delete m_pAllNpc;
	m_pAllNpc = NULL;

	delete m_pAllMonster;
	m_pAllMonster = NULL;

	delete m_pAllMaterial;
	m_pAllMaterial = NULL;

	delete m_pFight;
	m_pFight = NULL;

	delete m_pTalk;
	m_pTalk = NULL;

	delete m_pShop;
	m_pShop = NULL;

	delete m_pTask;
	m_pTask = NULL;

	delete m_pGain;
	m_pGain = NULL;

	MAPDATA *pData = NULL;
	map<int, MAPDATA*>::iterator iter = m_nMapList.begin();
	for (; iter != m_nMapList.end(); iter++)
	{
		pData = (*iter).second;
		delete pData;
	}
	m_nMapList.clear();
}

void CGameMap::readFileMap(char *pFileName)
{
	ifstream file(pFileName);

	if (file)
	{
		int iNum = -1;
		bool isEnd = false;

		while (true)
		{
			MAPDATA *pData = new MAPDATA;
			file >> pData->iID
				>> pData->szName
				>> pData->iBirthRow
				>> pData->iBirthCol;
			for (int i = 0; i < MAX_ROW; i++)
			{
				for (int j = 0; j < MAX_COL; j++)
				{
					file >>iNum;
					if (iNum == -1)
					{
						pData->iData[i][j] = MAP_WALL;
						isEnd = true;
					}
					else
						pData->iData[i][j] = iNum;
				}
			}
			m_nMapList[pData->iID] = pData;
			if (isEnd)
				break;
		}

	}
}

void CGameMap::getMapID(int iID)
{
	
	map<int, MAPDATA*>::iterator iter = m_nMapList.find(iID);
	if (iter != m_nMapList.end())
	{
		m_pCurMap = (*iter).second;
		m_pUser->setiRow(m_pCurMap->iBirthRow);
		m_pUser->setiCol(m_pCurMap->iBirthCol);
	}
}

void CGameMap::_isCollWall()
{
	int iNum = m_pCurMap->iData[m_pUser->m_iRow][m_pUser->m_iCol];
	if (iNum == MAP_WALL||iNum==MAP_MON)
		m_pUser->rePos();
	else if (iNum == MAP_SEA)
	{
		if (g_bBoat == false)
		{
			MessageBox(NULL, _T("�㻹û�������洬�������º���"), _T("����"), MB_OK);
			m_pUser->rePos();
		}
	}
	else if (iNum == MAP_CHASM)
	{
		if (g_bCord == false)
		{
			MessageBox(NULL, _T("�㻹û���������ӣ�������ȥ��"), _T("����"), MB_OK);
			m_pUser->rePos();
		}
	}
	else if (iNum == MAP_SKY)
	{
		if (g_bFly == false)
		{
			MessageBox(NULL, _T("�㻹û��������򣬲������죡"), _T("����"), MB_OK);
			m_pUser->rePos();
		}
		else
			getMapID(iNum);
	}
	else if (iNum > MAP_DOOR)
		getMapID(iNum);

	//�����NPC��ײ
	CNpc *pNpc = m_pAllNpc->isColl(m_pUser->m_iRow, m_pUser->m_iCol, m_pCurMap->iID);
	if (pNpc)
	{
		m_pTalk->setTalkRole(m_pUser, pNpc);
		m_pUser->rePos();
		g_iPlace = PLACE_TALK;
	}

	//����������ײ
	CMonster *pMonster = m_pAllMonster->isColl(m_pUser->m_iRow, m_pUser->m_iCol, m_pCurMap->iID);
	if (pMonster)
	{
		m_pFight->setFightRole(m_pUser, pMonster);
		m_pUser->rePos();
		g_iPlace = PLACE_FIGHT;
	}

	//����������ײ
	CMaterial *pMaterial = m_pAllMaterial->isColl(m_pUser->m_iRow, m_pUser->m_iCol, m_pCurMap->iID);
	if (pMaterial)
	{
		m_pGain->getGainRole(m_pUser, pMaterial);
		g_iPlace = PLACE_GAIN;
	}
}

void CGameMap::upData()
{
	if (g_iPlace == PLACE_MAP)
	{
		m_pUser->upData(&g_iPlace);
		_isCollWall();
	}
	else if (g_iPlace == PLACE_FIGHT)
	{
		m_pFight->upData(&g_iPlace);
		if (m_pUser->m_iHp <= 0)		//�����س�
		{			
			getMapID(101);
			m_pUser->m_iHp = 100;
		}
	}
	else if (g_iPlace == PLACE_TALK)
		m_pTalk->upData(&g_iPlace);
	else if (g_iPlace == PLACE_SHOP)
	{
		if (m_pShop->isSetShop() == false)
			m_pShop->setShopRole(m_pUser, m_pTalk->getNpc());
		m_pShop->upData(&g_iPlace);
	}
	else if (g_iPlace == PLACE_TASK)
	{
		if (m_pTask->isSetTask() == false)
			m_pTask->setTaskRole(m_pUser, m_pTalk->getNpc());
		m_pTask->upData(&g_iPlace);
	}
	else if (g_iPlace == PLACE_PLAYER)
		m_pUser->upData(&g_iPlace);
	else if (g_iPlace == PLACE_GAIN)
		m_pGain->upData(&g_iPlace);
}

void CGameMap::onRender()
{
	if (g_iPlace == PLACE_MAP)				//��ͼ״̬
		drawMap();
	else if (g_iPlace == PLACE_FIGHT)		//ս��״̬
		m_pFight->onRender();
	else if (g_iPlace == PLACE_TALK)		//�Ի�״̬
		m_pTalk->onRender();
	else if (g_iPlace == PLACE_SHOP)		//�̵�״̬
		m_pShop->onRender();
	else if (g_iPlace == PLACE_TASK)		//����״̬
		m_pTask->onRender();
	else if (g_iPlace == PLACE_PLAYER)		//���״̬
		m_pUser->onRender();
	else if (g_iPlace==PLACE_GAIN)			//�ջ�״̬
		m_pGain->onRender();
}

void CGameMap::drawMap()
{
	cout << m_pCurMap->szName << endl;
	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			if (m_pAllNpc->drawNpc(i, j, m_pCurMap->iID))
				continue;						
			else if (m_pUser->m_iRow == i&&m_pUser->m_iCol == j)
				m_pUser->onRender();
			else if (m_pUser->m_iPetRow == i&&m_pUser->m_iPetCol == j)	//��Ⱦ����
			{
				if (g_iGameBaby == BABY_NONE)
					cout << "  ";
				else if (g_iGameBaby == BABY_DOG)
					cout << "��";
				else if (g_iGameBaby == BABY_TIGER)
					cout << "��";
				else if (g_iGameBaby == BABY_LION)
					cout << "ʨ";
				else if (g_iGameBaby == BABY_HORSE)
					cout << "��";
			}		
			else if (m_pCurMap->iData[i][j] == MAP_WALL)
				cout << "��";
			else if (m_pCurMap->iData[i][j] == MAP_MON)
				cout << "��";
			else if (m_pAllMaterial->drawMaterial(i, j, m_pCurMap->iID))
				continue;
			else if (m_pAllMonster->drawMonster(i, j, m_pCurMap->iID))
				continue;
			else if (m_pCurMap->iData[i][j] == MAP_SEA)		//��
				cout << "~~";
			else if (m_pCurMap->iData[i][j] == MAP_CHASM)	//��Ԩ
				cout << "��";			
			else if (m_pCurMap->iData[i][j] > 100)
			{
				if (m_pCurMap->iData[i][j] == 105)
					cout << "��";
				else 
					cout << "��";
			}
			else
				cout << "  ";
		}	

		cout << endl;	
	}	
	cout << "����Tab������˵��" << endl;
	if (g_iNumber != TASK_NONE)
		cout << "����" << g_iNumber << "������..." << endl;
}

