#include "stdafx.h"
#include "Gain.h"


CGain::CGain()
{
	m_iGainState = GAIN_START;
	m_index = GAIN_ONE;
	m_pMater = NULL;
	m_pUser = NULL;
}


CGain::~CGain()
{
}

void CGain::getGainRole(CPlayer *pPlayer, CMaterial *pMater)
{
	m_pMater = pMater;
	m_pUser = pPlayer;
}

void CGain::onRender()
{
	cout << "-------------------------------------------" << endl;
	cout << "                                           " << endl;
	cout << "                                           " << endl;
	cout << "                                           " << endl;
	if (m_iGainState==GAIN_START)
		cout << "        " << "♀"<< "      " << m_pMater->m_szHead << m_pMater->m_szHead << m_pMater->m_szHead << m_pMater->m_szHead << endl;
	else if (m_iGainState == GAIN_ONE)
	{
		cout << "          " << "♀" << "    " << m_pMater->m_szHead << m_pMater->m_szHead << m_pMater->m_szHead << m_pMater->m_szHead << endl;
		m_iGainState = GAIN_TOW;
		m_index++;
	}
	else if (m_iGainState == GAIN_TOW)
	{
		cout << "            " << "♀" << "  " << m_pMater->m_szHead << m_pMater->m_szHead << m_pMater->m_szHead << m_pMater->m_szHead << endl;
		m_iGainState = GAIN_THREE;
		m_index++;
	}
	else if (m_iGainState == GAIN_THREE)
	{
		cout << "              " << "♀" << m_pMater->m_szHead << m_pMater->m_szHead << m_pMater->m_szHead << m_pMater->m_szHead << endl;
		m_iGainState = GAIN_FOUR;
		m_index++;
	}
	else if (m_iGainState == GAIN_FOUR)
	{
		cout << "                " << "♀"  << m_pMater->m_szHead << m_pMater->m_szHead << m_pMater->m_szHead << endl;
		m_iGainState = GAIN_FIVE;
		m_index++;
	}
	else if (m_iGainState == GAIN_FIVE)
	{
		cout << "                  " << "♀"  << m_pMater->m_szHead << m_pMater->m_szHead << endl;
		m_iGainState = GAIN_SIX;
		m_index++;
	}
	else if (m_iGainState == GAIN_SIX)
	{
		cout << "                    " << "♀" << m_pMater->m_szHead << endl;
		m_iGainState = GAIN_SEVEN;
		m_index++;
	}
	else if (m_iGainState == GAIN_SEVEN)
	{
		cout << "                      " << "♀" << endl;
		m_iGainState = GAIN_START;
		m_index = GAIN_ONE;
		m_pMater->m_iNumb--;

	}
	cout << "                                           " << endl;
	cout << "                                           " << endl;
	cout << "                                           " << endl;
	cout << "-------------------------------------------" << endl<<endl;

	cout << "按下return键开始采集" << endl;
}

void CGain::upData(int *piMapState)
{
	if (KEYDOWN(VK_RETURN))
	{
		m_iGainState = m_index;

		m_pMater->m_iRow = 0;
		m_pMater->m_iCol = 0;
	}
	else if (KEYDOWN(VK_ESCAPE))
	{
		*piMapState = PLACE_MAP;
		m_iGainState = GAIN_START;
	}
	if (m_pMater->m_iNumb <= 0)
	{
		MessageBox(NULL, _T("采集成功！"), _T("恭喜"), MB_OK);
		if (m_pMater->m_iType == 1)
			g_iGrass++;
		else if (m_pMater->m_iType == 2)
			g_iWood++;
		else if (m_pMater->m_iType == 3)
			g_iIron++;
		else if (m_pMater->m_iType == 4)
			m_pUser->m_iMoney += 500;
		else if (m_pMater->m_iType == 5)
			g_iCode = TASK_SIXDONE;		//任务6完成！
		*piMapState = PLACE_MAP;

	}
	
}