#include"Bullet.h"
#include"../GameConfig/GameConfig.h"
CBullet::CBullet()
{
	m_x = 0;
	m_y = 0;
}
CBullet::~CBullet()
{
}
void CBullet::InitBullet(int x, int y)
{
	::loadimage(&m_bulletImg, PATH_PIC(gunner.jpg));
	m_x = x;
	m_y = y;
}
void CBullet::ShowBullet()
{
	::putimage(m_x, m_y, IMG_BULLET_WIDHT, IMG_BULLET_HEIGHT,
		&m_bulletImg, IMG_BULLET_WIDHT, 0, SRCPAINT);
	::putimage(m_x, m_y, IMG_BULLET_WIDHT, IMG_BULLET_HEIGHT,
		&m_bulletImg, 0, 0, SRCAND);
}
void CBullet::MoveBullet(int step)
{
	m_x += step;
}

