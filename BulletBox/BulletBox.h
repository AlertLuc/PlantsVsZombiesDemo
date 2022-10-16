#pragma once
#include<list>
using namespace std;
#include"Bullet.h"
class CBulletBox
{
public:
	list<CBullet*> m_lstbullet;
public:
	CBulletBox();
	~CBulletBox();
public:
	void ShowAllBullet();
	void MoveAllBullet(int step);
};