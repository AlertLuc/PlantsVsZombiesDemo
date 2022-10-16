#pragma once
#include<list>
using namespace std;
#include"Sun.h"
class CSunBox 
{
public:
	list<CSun*> m_lstSun;
	list<CSun*> m_lstSun1;//For the sun
public:
	CSunBox();
	~CSunBox();
public:
	void ShowAllSun();
	void ShowAllCreatSun();
	void MoveAllSun();
	//bool IsHitSun(int m_x, int m_y);
	bool IsHitSun(int x, int y);
};
