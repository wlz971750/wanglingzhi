#pragma once
#include<map>
using namespace std;

enum
{
	PLAYER_HEAD=1,
	PLAYER_NECK,
	PLAYER_CUIRASS,		//¿ø¼×
	PLAYER_SHOE,		
	PLAYER_WEAP,		//ÎäÆ÷
	PLAYER_PET,
};

struct ITEM{
	int iID;
	char szName[32];
	int iType;
	int iPos;
	int iLevel;
	int iHp;
	int iAttack;
	int iDef;
	int iPower;
	int iAgility;     // Ãô½Ý
	int iIntell;      // ÖÇÁ¦ 
	int iMoney;
};

class CGameItem
{
public:
	CGameItem();
	~CGameItem();

	void readItemFile(char *ItemFile);

	map<int, ITEM*>	getCurItem(int iType);		//È¡»õ

	static CGameItem *getItem();

private:
	map<int, ITEM*> m_pItemList;		//²Ö¿â
};

