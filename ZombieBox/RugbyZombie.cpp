#include"RugbyZombie.h"
#include"../GameConfig/GameConfig.h"
CRugbyZombie::CRugbyZombie()
{
}
CRugbyZombie::~CRugbyZombie()
{
}
void CRugbyZombie::InitZombie() //Logical initialization
{
	::loadimage(&m_zomImg, PATH_PIC(RugbyZombie.jpg));
	::loadimage(&m_zomdieImg, PATH_PIC(1.jpg));
	m_dieshowId = 5;
	m_blood = DEF_RUGBYZOMBIE_BLOOD;
	m_showId = 7;//Eight diagram
	isHitePlants = false;
	m_x = IMG_PLANTSVSZOMBIESBACKGROUND_WIDTH;
	int y = rand() % (IMG_PLANTSVSZOMBIESBACKGROUND_HEIGHT);
	if (y >= 0 && y <= 120) {
		m_y = 0;
	}
	else if (y > 120 && y <= 240) {
		m_y = 99;
	}
	else if (y > 240 && y <= 360) {
		m_y = 198;
	}
	else if (y > 360 && y <= 480) {
		m_y = 297;
	}
	else
	{
		m_y = 396;
	}
}
void CRugbyZombie::ShowZombie()
{
	::putimage(m_x, m_y, IMG_RUGBYZOMBIE_WIDHT, IMG_RUGBYZOMBIE_HEIGHT, &m_zomImg, IMG_RUGBYZOMBIE_WIDHT, (7 - m_showId) * IMG_RUGBYZOMBIE_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_RUGBYZOMBIE_WIDHT, IMG_RUGBYZOMBIE_HEIGHT, &m_zomImg, 0, (7 - m_showId) * IMG_RUGBYZOMBIE_HEIGHT, SRCAND);
}
void CRugbyZombie::ShowDieZombie()
{
	::putimage(m_x, m_y, IMG_RUGBYZOMBIEB_WIDHT, IMG_RUGBYZOMBIEB_HEIGHT, &m_zomdieImg, IMG_RUGBYZOMBIEB_WIDHT, (5 - m_dieshowId) * IMG_RUGBYZOMBIEB_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_RUGBYZOMBIEB_WIDHT, IMG_RUGBYZOMBIEB_HEIGHT, &m_zomdieImg, 0, (5 - m_dieshowId) * IMG_RUGBYZOMBIEB_HEIGHT, SRCAND);
}
bool CRugbyZombie::IsHitBullet(int x, int y)
{
	if (m_x<x && m_x + IMG_RUGBYZOMBIE_WIDHT / 2>x && m_y <= y && y <= m_y + IMG_RUGBYZOMBIE_HEIGHT)
	{
		return true;
	}
	return false;
}
bool CRugbyZombie::IsHitPlant(int x,int y)
{
	if (m_y + 69 == y && m_x<x && m_x + IMG_RUGBYZOMBIE_WIDHT / 2>x)
	{
		return true;
	}
	return false;
}

bool CRugbyZombie::IsHitCherry(int x, int y)
{
	if ((m_y + 69 == y || m_y + 168 == y || m_y - 30 == y) && ((m_x<x && m_x + IMG_RUGBYZOMBIE_WIDHT * 2>x) || (m_x > x && m_x - IMG_RUGBYZOMBIE_WIDHT - IMG_CHERRY_WIDHT < x)))
	{
		return true;
	}
	return false;

}

bool CRugbyZombie::IsHitDolly(int x, int y)
{
	if (m_y + 91 == y && m_x<x && m_x + IMG_RUGBYZOMBIE_WIDHT / 2>x)
	{
		return true;
	}
	return false;
}
