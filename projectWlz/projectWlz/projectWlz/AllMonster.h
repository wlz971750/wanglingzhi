#pragma once
#include"Monster.h"
#include<map>
class CAllMonster
{
public:
	CAllMonster();
	~CAllMonster();


	//��ȡ�������ļ�
	void readFile(char *FileMonster);				

	//�Ƿ��ӡ����
	bool drawMonster(int iRow, int iCol, int iMapID);

	//�������
	CMonster *isColl(int iRow, int iCol, int iMapID);

private:
	map<int, CMonster*> m_pMonsterList;
};

