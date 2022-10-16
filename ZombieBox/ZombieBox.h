#pragma once
#include<list>
#include"Zombie.h"
using namespace std;
class CZombieBox 
{
public:
	list<CZombie*>  m_lstZom;
	list<CZombie*>  m_lstBoomZom;
	list<CZombie*>  m_lstStopZom;//Put these zombies together when eating the same plant
public:
	CZombieBox();
	~CZombieBox();
public:
	void ShowAllZombie();
	void ShowAllBoomZombie();
	void MoveAllZombie();
};
