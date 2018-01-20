#pragma once
#include"Npc.h"
#include<map>

class CAllNpc
{
public:
	CAllNpc();
	~CAllNpc();

	void readFileNpc(char *FileNpc);

	bool drawNpc(int iRow,int iCol,int iMapID);

	CNpc *isColl(int iRow, int iCol, int iMapID);

private:
	map<int, CNpc*> m_pNpcList;
};

