#pragma once
#include<easyx.h>
#include"../BulletBox/Bullet.h"
class CPeashooter
{
public:
	int m_x;
	int m_y;
	int m_plantblood;
	IMAGE m_playerImg;
	int m_playershowId;
	bool isdowncard;
public:
	CPeashooter();
	~CPeashooter();
public:
	virtual void InitPlant(int x, int y);
	virtual void ShowPlant();
	virtual void MovePlant(int x, int y);

	//And beans
	CBullet* SendBullet();
};

