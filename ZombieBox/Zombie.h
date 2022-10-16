#pragma once
#include<easyx.h>
#include"../BulletBox/Bullet.h"
#include"../PlantBox/Peashooter.h"
class CZombie
{
public:
	IMAGE m_zomImg;
	IMAGE m_zomdieImg;
	int   m_blood;
	int   m_showId;
	int m_dieshowId;
	int   m_x;
	int   m_y;
	bool isHitePlants;
public:
	CZombie();
	virtual ~CZombie();
public:
	virtual void InitZombie() = 0;
	virtual void ShowZombie() = 0;
	virtual void ShowDieZombie() = 0;
	void MoveZombie(int step);
	virtual bool IsHitBullet(int x, int y) = 0;
	virtual bool IsHitPlant(int x,int y) = 0;
	virtual bool IsHitDolly(int x, int y) = 0;
	virtual bool IsHitCherry(int x, int y) = 0;

};
