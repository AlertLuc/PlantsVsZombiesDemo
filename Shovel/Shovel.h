#pragma once
#include<easyx.h> 
class CShovel 
{
public:
	IMAGE m_ShovelImg;
	int   m_x;
	int   m_y;
	bool ishit;
public:
	CShovel();
	~CShovel();
public:
	void InitShovel(int x, int y);
	void ShowShovel();
	void MoveShovel(int x, int y);
	bool IsHitPlant(int x, int y);
};
