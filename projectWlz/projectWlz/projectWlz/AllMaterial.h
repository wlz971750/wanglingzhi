#pragma once
#include"Material.h"
#include<map>
class CAllMaterial
{
public:
	CAllMaterial();
	~CAllMaterial();

	void readFile(char *FileMaterial);

	bool drawMaterial(int iRow, int iCol, int iMapID);

	CMaterial *isColl(int iRow, int iCol, int iMapID);

private:
	map<int, CMaterial*> m_pMaterList;
};

