#include"Dolly.h"
#include"../GameConfig/GameConfig.h"
CDolly::CDolly()
{
	m_x = 0;
	m_y = 0;
	ishit = false;
}
CDolly::~CDolly()
{
}
void CDolly::InitDolly(int x, int y)
{
	::loadimage(&m_DollyImg, PATH_PIC(car.jpg));
	m_x = x;
	m_y = y;
}
void CDolly::ShowDolly()
{
	::putimage(m_x, m_y, IMG_DOLLY_WIDHT, IMG_DOLLY_HEIGHT,
		&m_DollyImg, IMG_DOLLY_WIDHT, 0, SRCPAINT);
	::putimage(m_x, m_y, IMG_DOLLY_WIDHT, IMG_DOLLY_HEIGHT,
		&m_DollyImg, 0, 0, SRCAND);
}
void CDolly::MoveDolly(int step)
{
	m_x += step;
}

