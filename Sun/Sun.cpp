#include"Sun.h"
#include"../GameConfig/GameConfig.h"
CSun::CSun() 
{
}
CSun::~CSun() 
{
}
void CSun::InitSun(int x,int y)
{
	::loadimage(&m_sunImg, PATH_PIC(Sun.jpg));
	 m_x = rand()%(IMG_PLANTSVSZOMBIESBACKGROUND_WIDTH-IMG_SUN_WIDHT);
	 m_y = -IMG_SUN_HEIGHT;
	 n_x = x;
	 n_y = y;
	 m_destination = rand() % (IMG_PLANTSVSZOMBIESBACKGROUND_HEIGHT - IMG_SUN_HEIGHT);  //Set the end
}
void CSun::ShowSun() 
{
	::putimage(m_x, m_y, IMG_SUN_WIDHT, IMG_SUN_HEIGHT,
		&m_sunImg, IMG_SUN_WIDHT, 0, SRCPAINT);
	::putimage(m_x, m_y, IMG_SUN_WIDHT, IMG_SUN_HEIGHT,
		&m_sunImg, 0, 0, SRCAND);
}
void CSun::ShowCreatSun() {
	::putimage(n_x, n_y, IMG_SUN_WIDHT, IMG_SUN_HEIGHT,
		&m_sunImg, IMG_SUN_WIDHT, 0, SRCPAINT);
	::putimage(n_x, n_y, IMG_SUN_WIDHT, IMG_SUN_HEIGHT,
		&m_sunImg, 0, 0, SRCAND);
}
void CSun::MoveSun(int step)
{ 
	if (m_y < m_destination)
	{
		m_y += step;
	}
	else
	{
		m_y = m_destination;
	}
}
