#pragma once
#include<list>
#include"Sunflower.h"
using namespace std;
class CSunflowerBox
{
public:
	list<CSunflower*>  m_lstSunflower;
	list<CSunflower*>  m_lstBoomSunf;
public:
	CSunflowerBox();
	~CSunflowerBox();
public:
	void ShowAllSunflower();
	bool IsHitSunflower(int m_x, int m_y);
	void ShowAllBoomSunflower();
};


