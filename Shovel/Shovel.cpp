#include"Shovel.h"
#include"../GameConfig/GameConfig.h"
CShovel::CShovel()
{
	m_x = 0;
	m_y = 0;
	ishit = false;
}
CShovel::~CShovel()
{
}
void CShovel::InitShovel(int x, int y)
{
	::loadimage(&m_ShovelImg, PATH_PIC(Shovel.jpg));
	ishit = false;
	m_x = x;
	m_y = y;
}
void CShovel::ShowShovel()
{
	::putimage(m_x, m_y, IMG_SHOVEL_WIDHT, IMG_SHOVEL_HEIGHT,
		&m_ShovelImg, IMG_SHOVEL_WIDHT, 0, SRCPAINT);
	::putimage(m_x, m_y, IMG_SHOVEL_WIDHT, IMG_SHOVEL_HEIGHT,
		&m_ShovelImg, 0, 0, SRCAND);
}
bool CShovel::IsHitPlant(int x, int y) {
	if (x<m_x && x>m_x- 81 && y>m_y &&y <m_y+ IMG_SHOVEL_HEIGHT/2)
	{
		return true;
	}
	return false;
}

void CShovel::MoveShovel(int x,int y)
{
	m_x = x;
	m_y = y;
}

