#pragma once
#include<easyx.h> 
class CDolly 
{
public:
	IMAGE m_DollyImg;
	int   m_x;
	int   m_y;
	bool ishit;
public:
	CDolly();
	~CDolly();
public:
	void InitDolly(int x, int y);
	void ShowDolly();
	void MoveDolly(int step);	
};
