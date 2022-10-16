#pragma once
#include<easyx.h>
class CCherry
{
public:
	int m_x;
	int m_y;
	
	int m_Cherryblood;
	IMAGE m_CherryImg;
	IMAGE m_CherryBoomImg;
	bool isdowncard;
public:
	CCherry();
	~CCherry();
public:
	virtual void InitCherry(int x, int y);
	virtual void ShowCherry();
	virtual void MoveCherry(int x, int y);
	virtual void ShowBoomCherry();
};

