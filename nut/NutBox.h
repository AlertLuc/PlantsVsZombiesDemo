#pragma once
#include<list>
#include"Nut.h"
using namespace std;
class CNutBox
{
public:
	list<CNut*>  m_lstNut;
	list<CNut*>  m_lstBoomNut;
public:
	CNutBox();
	~CNutBox();
public:
	void ShowAllNut();
	bool IsHitNut(int m_x, int m_y);
	void ShowAllBoomNut();
};


