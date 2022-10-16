#include"Zombie.h"
CZombie::CZombie()
{
	m_blood = 0;
	m_showId = 0;
	m_dieshowId = 0;
	m_x = 0;
	m_y = 0;
	isHitePlants = false;
}
CZombie::~CZombie() 
{
}
void CZombie::MoveZombie(int step)
{
	m_x -= step;
}
