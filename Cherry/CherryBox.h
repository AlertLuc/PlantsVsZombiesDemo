#pragma once
#include<list>
#include"Cherry.h"
using namespace std;
class CCherryBox
{
public:
	list<CCherry*>  m_lstCherry;
	list<CCherry*>  m_lstBoomCHERRY;
public:
	CCherryBox();
	~CCherryBox();
public:
	void ShowAllCherry();
	bool IsHitCherry(int m_x, int m_y);
	void ShowAllBoomCherry();
};


