#include"FlagZombie.h"
#include"../GameConfig/GameConfig.h"
CFlagZombie::CFlagZombie()
{
}
CFlagZombie::~CFlagZombie()
{
}
void CFlagZombie::InitZombie() //Logical initialization
{
	::loadimage(&m_zomImg, PATH_PIC(flagzombie.jpg));
	m_blood = DEF_FLAGZOMBIE_BLOOD;
	m_showId = 7;//5 picture
	::loadimage(&m_zomdieImg, PATH_PIC(3.jpg));
	m_dieshowId = 7;
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
void CFlagZombie::ShowZombie()
{
	::putimage(m_x, m_y, IMG_FLAGZOMBIE_WIDHT, IMG_FLAGZOMBIE_HEIGHT, &m_zomImg, IMG_FLAGZOMBIE_WIDHT, (7 - m_showId) * IMG_FLAGZOMBIE_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_FLAGZOMBIE_WIDHT, IMG_FLAGZOMBIE_HEIGHT, &m_zomImg, 0, (7 - m_showId) * IMG_FLAGZOMBIE_HEIGHT, SRCAND);
}
void CFlagZombie::ShowDieZombie()
{
	::putimage(m_x, m_y, IMG_FLAGZOMBIEB_WIDHT, IMG_FLAGZOMBIEB_HEIGHT, &m_zomdieImg, IMG_FLAGZOMBIEB_WIDHT, (7 - m_dieshowId) * IMG_FLAGZOMBIEB_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_FLAGZOMBIEB_WIDHT, IMG_FLAGZOMBIEB_HEIGHT, &m_zomdieImg, 0, (7 - m_dieshowId) * IMG_FLAGZOMBIEB_HEIGHT, SRCAND);
}
bool CFlagZombie::IsHitBullet(int x, int y)
{
	if ( m_x<x && m_x + IMG_FLAGZOMBIE_WIDHT / 2>x && m_y <= y && y <= m_y + IMG_FLAGZOMBIE_HEIGHT)
	{
		return true;
	}
	return false;
}
bool CFlagZombie::IsHitPlant(int x,int y)
{
	if (m_y + 69 == y && m_x<x && m_x + IMG_FLAGZOMBIE_WIDHT / 2>x)
	{
		return true;
	}
	return false;
}

bool CFlagZombie::IsHitCherry(int x, int y)
{
	if ((m_y + 69 == y || m_y + 168 == y || m_y - 30 == y) && ((m_x<x && m_x + IMG_FLAGZOMBIE_WIDHT * 2>x) || (m_x > x && m_x - IMG_FLAGZOMBIE_WIDHT - IMG_CHERRY_WIDHT < x)))
	{
		return true;
	}
	return false;

}

bool CFlagZombie::IsHitDolly(int x, int y)
{
	if (m_y + 91 == y && m_x<x && m_x + IMG_FLAGZOMBIE_WIDHT / 2>x)
	{
		return true;
	}
	return false;
}