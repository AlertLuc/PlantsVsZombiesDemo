#pragma once
#include"Zombie.h"
class CConeHeadZombie :public CZombie
{
public:
	CConeHeadZombie();
	~CConeHeadZombie();
public:
	virtual void InitZombie();
	virtual void ShowZombie();
	virtual void ShowDieZombie();
	virtual bool IsHitBullet(int x, int y);
	virtual bool IsHitPlant(int x, int y);
	virtual bool IsHitDolly(int x, int y);
	virtual bool IsHitCherry(int x, int y);
};