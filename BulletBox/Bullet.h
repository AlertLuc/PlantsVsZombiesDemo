#pragma once
#include<easyx.h> 
class CBullet 
{
public:
	IMAGE m_bulletImg;
	int   m_x;
	int   m_y;
public:
	CBullet();
	~CBullet();
public:
	void InitBullet(int x, int y);
	void ShowBullet();
	void MoveBullet(int step);	
};
