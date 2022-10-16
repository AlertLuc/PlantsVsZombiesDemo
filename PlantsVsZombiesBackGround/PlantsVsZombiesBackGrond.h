#pragma once
#include<easyx.h>
class CPlantsVsZombiesBackGround
{
public:
	IMAGE m_backImg;
	int   m_x;
	int   m_y;
public:
	CPlantsVsZombiesBackGround();
	~CPlantsVsZombiesBackGround();
public:
	void InitPlantsVsZombiesBackGround();
	void showPlantsVsZombiesBackGround();
};
