#pragma once
#include<easyx.h>
#include"../CactusshellBox/Cactusshell.h"
class CCactus
{
public:
	int m_x;
	int m_y;
	int m_Cactusblood;
	IMAGE m_CactusImg;
	int m_CactusshowId;
	bool isdowncard;
public:
	CCactus();
	~CCactus();
public:
	virtual void InitCactus(int x, int y);
	virtual void ShowCactus();
	virtual void MoveCactus(int x, int y);

	//And beans
	CCactusshell* SendCactusshell();
};

