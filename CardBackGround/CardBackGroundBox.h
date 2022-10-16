#pragma once
#include<list>
using namespace std;
#include"CardBackGround.h"
class CCardBackGroundBox
{
public:
	list<CCardBackGround*> m_lstCardBackGround;
public:
	CCardBackGroundBox();
	~CCardBackGroundBox();
public:
	void ShowAllCardBackGround();
	bool IsHitCardBackGround(int m_x, int m_y);
};
