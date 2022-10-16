#pragma once
#include<easyx.h>
class CSun
{
public:
	IMAGE m_sunImg;
	int   m_x;
	int   m_y;
	int   n_x;  //Record the position where the sun produces sunlight
	int   n_y;
	int   m_destination;//The end of the sun's movement
public:
	CSun();
	~CSun();
public:
	void InitSun(int x,int y);
	void ShowSun() ;
	void ShowCreatSun();
	void MoveSun(int step);
	

};


