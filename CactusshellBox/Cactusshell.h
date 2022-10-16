#pragma once
#include<easyx.h> 
class CCactusshell
{
public:
	IMAGE m_CactusshellImg;
	int   m_x;
	int   m_y;
public:
	CCactusshell();
	~CCactusshell();
public:
	void InitCactusshell(int x, int y);
	void ShowCactusshell();
	void MoveCactusshell(int step);
};
