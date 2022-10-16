#pragma once
#include<list>
#include"Peashooter.h"
using namespace std;
class CPlantBox
{
public:
	list<CPeashooter*>  m_lstPlant;
	list<CPeashooter*>  m_lstBoomPla;
public:
	CPlantBox();
	~CPlantBox();
public:
	void ShowAllPlant();
	bool IsHitPlant(int m_x, int m_y);
	void ShowAllBoomPlant();
};


