#pragma once
#include<map>
using namespace std;

struct DOTASK{
	int m_iID;
	int m_iType;
	char m_szContent[64];		//任务内容
	int m_iMoney;
	int m_iExp;
	int m_iState;
};



class CGameTask
{
public:
	CGameTask();
	~CGameTask();

	void readTask(char *TaskFile);

	static CGameTask *getTask();

	map<int, DOTASK*>	getCurTask(int iType);	


private:
	map<int, DOTASK*> m_nTaskList;		//任务库
};

