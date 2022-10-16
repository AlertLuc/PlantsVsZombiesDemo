#pragma once
#include<easyx.h>
#include"../Sun/Sun.h"
class CSunflower
{
public:
	int m_x;
	int m_y;
	int m_Sunflowerblood;
	IMAGE m_SunflowerImg;
	int m_SunflowershowId;
	bool isdowncard;
public:
	CSunflower();
	~CSunflower();
public:
	virtual void InitSunflower(int x, int y);
	virtual void ShowSunflower();
	virtual void MoveSunflower(int x, int y);
	CSun* CreatSun();
};

