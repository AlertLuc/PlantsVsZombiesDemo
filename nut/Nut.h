#pragma once
#include<easyx.h>
class CNut
{
public:
	int m_x;
	int m_y;
	int m_Nutblood;
	IMAGE m_NutImg;
	int m_NutshowId;
	bool isdowncard;
public:
	CNut();
	~CNut();
public:
	virtual void InitNut(int x, int y);
	virtual void ShowNut();
	virtual void MoveNut(int x, int y);
};

