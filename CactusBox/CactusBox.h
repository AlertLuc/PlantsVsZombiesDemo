#pragma once
#include<list>
#include"Cactus.h"
using namespace std;
class CCactusBox
{
public:
	list<CCactus*>  m_lstCactus;
	list<CCactus*>  m_lstBoomCa;
public:
	CCactusBox();
	~CCactusBox();
public:
	void ShowAllCactus();
	bool IsHitCactus(int m_x, int m_y);
	//void ShowAllBoomCactus();
};


