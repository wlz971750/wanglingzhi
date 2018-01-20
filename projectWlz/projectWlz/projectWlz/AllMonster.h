#pragma once
#include"Monster.h"
#include<map>
class CAllMonster
{
public:
	CAllMonster();
	~CAllMonster();


	//读取怪物类文件
	void readFile(char *FileMonster);				

	//是否打印怪物
	bool drawMonster(int iRow, int iCol, int iMapID);

	//碰到玩家
	CMonster *isColl(int iRow, int iCol, int iMapID);

private:
	map<int, CMonster*> m_pMonsterList;
};

