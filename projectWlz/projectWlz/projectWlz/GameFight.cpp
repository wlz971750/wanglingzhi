#include "stdafx.h"
#include "GameFight.h"


CGameFight::CGameFight()
{
	m_iFinghtState = FIGHT_NONE;
	
	m_iFihgtInfo = FIGHT_MAP;
	m_index = FIGHT_START;
	m_pUser = NULL;
	m_pMons = NULL;
	
}


CGameFight::~CGameFight()
{

}

void CGameFight::setFightRole(CPlayer *pPlayer, CMonster *pMons)
{
	 m_pUser= pPlayer;
	 m_pMons = pMons;
}

void CGameFight::upData(int *pMapState)
{	
	if (KEYDOWN(VK_RETURN))
		m_iFinghtState = m_index;
	else if (KEYDOWN(VK_ESCAPE))
		*pMapState = PLACE_MAP;
	else if (KEYDOWN(VK_SPACE))
		m_iFihgtInfo = FIGHT_INFO;					
	if (m_pMons->m_iHp <= 0)
	{
		if (g_iNumber==TASK_ONE)
		g_iCode = TASK_ONEDONE;			//任务1完成！
		else if (m_pMons->m_iType == 4&&g_iNumber==TASK_FOUR)
			g_iCode = TASK_FOURDONE;	//任务4完成！
		else if (m_pMons->m_iType == 6 && g_iNumber==TASK_SEVEN)
			g_iCode = TASK_SEVENDONE;		//任务7完成！
		m_iFinghtState = FIGHT_NONE;
		m_pUser->m_iNum += m_pMons->m_iNum;		//玩家获得经验
		m_pUser->m_iMoney += m_pMons->m_iMoney;	//玩家获得金钱
		MessageBox(NULL, _T("你已经把它宰啦！"), _T("提示"), MB_OK);
		m_index = FIGHT_START;
		if (m_pMons->m_iType>0 && m_pMons->m_iType<3)
			m_pMons->m_iHp = m_pMons->m_iBkHp;
		else
		{
			m_pMons->m_iRow = 0;
			m_pMons->m_iCol = 0;
		}
		m_pUser->upLevel();
		*pMapState = PLACE_MAP;
	}	
	else if (m_pUser->m_iHp <= 0)
	{
		m_pMons->m_iHp = m_pMons->m_iBkHp;
		MessageBox(NULL, _T("你的血槽已空！去药店补充体力吧"), _T("提示"), MB_OK);
		m_index = FIGHT_START;
		*pMapState = PLACE_MAP;
	}
	
}

void CGameFight::onRender()
{
	if (m_iFihgtInfo == FIGHT_MAP)
	{
		cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■                                      ■"<<"    攻击（return）" << endl;
		cout << "■                                      ■" << endl;
		cout << "■                                      ■"<<"    逃跑（escape）" << endl;
		cout << "■                                      ■" << endl;

		if (m_iFinghtState == FIGHT_NONE)
		{
			cout << "■                                      ■" << endl;
			cout << "■              ♀      "<<m_pMons->m_szHead<<"              ■" << endl;
		}
		if (m_iFinghtState == FIGHT_START)
		{
			cout << "■                                      ■" << endl;
			cout << "■              ♀      " << m_pMons->m_szHead << "              ■" << endl;
			m_iFinghtState = FIGHT_ONE;
			m_index ++;
		}

		else if (m_iFinghtState == FIGHT_ONE)
		{
			cout << "■                                      ■" << endl;
			cout << "■                ♀    " << m_pMons->m_szHead << "              ■" << endl;
			m_iFinghtState = FIGHT_TOW;
			m_index++;
		}

		else if (m_iFinghtState == FIGHT_TOW)
		{
			cout << "■                                      ■" << endl;
			cout << "■                  ♀  " << m_pMons->m_szHead << "              ■" << endl;
			m_iFinghtState = FIGHT_THREE;
			m_index++;
		}
		else if (m_iFinghtState == FIGHT_THREE)
		{
			cout << "■                                      ■" << endl;
			cout << "■                    ♀" << m_pMons->m_szHead << "              ■" << endl;
			m_pMons->m_iHp = m_pMons->m_iHp - m_pUser->m_iattack;					//怪物掉血
			m_iFinghtState = FIGHT_START2;
			m_index++;
		}
		else if (m_iFinghtState == FIGHT_START2)
		{
			cout << "■                                      ■" << endl;
			cout << "■              ♀      " << m_pMons->m_szHead << "              ■" << endl;
			m_iFinghtState = FIGHT_FOUR;
			m_index++;
		}
		else if (m_iFinghtState == FIGHT_FOUR)
		{
			cout << "■                                      ■" << endl;
			cout << "■              ♀    " << m_pMons->m_szHead << "                ■" << endl;
			m_iFinghtState = FIGHT_FIVE;
			m_index++;
		}
		else if (m_iFinghtState == FIGHT_FIVE)
		{
			cout << "■                                      ■" << endl;
			cout << "■              ♀  " << m_pMons->m_szHead << "                  ■" << endl;
			m_iFinghtState = FIGHT_SIX;
			m_index++;
		}
		else if (m_iFinghtState == FIGHT_SIX)
		{
			cout << "■                " << m_pMons->m_szHead << "                    ■" << endl;
			cout << "■              ♀                      ■" << endl;
			m_iFinghtState = FIGHT_SEVEN;
			m_index++;
		}
		else if (m_iFinghtState == FIGHT_SEVEN)
		{
			cout << "■              " << m_pMons->m_szHead << "                      ■" << endl;
			cout << "■              ♀                      ■" << endl;
			m_pUser->m_iHp = m_pUser->m_iHp - m_pMons->m_iattack + m_pUser->m_iDef;	//玩家掉血
			m_iFinghtState = FIGHT_NONE;
			m_index = FIGHT_START;
		}
		
	
		cout << "■                                      ■" << endl;
		cout << "■                                      ■" <<"    怪物属性（长按space）" << endl;
		cout << "■                                      ■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
		if (m_iFinghtState == FIGHT_THREE || m_iFinghtState == FIGHT_START2)
			cout << "玩家血量:" << m_pUser->m_iHp << "\t\t  " << "怪物遭受" << m_pUser->m_iattack <<"点攻击"<< endl;
		else if (m_iFinghtState == FIGHT_SIX || m_iFinghtState == FIGHT_FIVE)
			cout << "玩家受到" << m_pMons->m_iattack<<"点伤害" << "\t\t  " << "怪物血量：" << m_pMons->m_iHp << endl;
		else
			cout << "玩家血量:" << m_pUser->m_iHp<<  "\t\t  " <<  "怪物血量："<<m_pMons->m_iHp<< endl;
	}
	else if (m_iFihgtInfo == FIGHT_INFO)
	{
		if (KEYDOWN(VK_SPACE))
			m_iFihgtInfo = FIGHT_MAP;
		cout << m_pMons->m_szName <<endl<< endl;
		cout << "等级:" << m_pMons->m_iLevel << endl;
		cout << "可得经验：" << m_pMons->m_iNum << endl;
		cout << "攻击力：" << m_pMons->m_iattack << endl;
		cout << "防御力：" << m_pMons->m_iDef << endl;
		cout << "血量:" << m_pMons->m_iHp << endl;
		cout << "可获金钱：" << m_pMons->m_iMoney << endl << endl;
	}
	
}