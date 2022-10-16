#include"ConeHeadZombie.h"
#include"../GameConfig/GameConfig.h"
CConeHeadZombie::CConeHeadZombie()
{
}
CConeHeadZombie::~CConeHeadZombie() 
{
}
void CConeHeadZombie::InitZombie() 
{
	::loadimage(&m_zomImg, PATH_PIC(coneheadzombie.jpg));
	m_blood = DEF_CONEHEADZOMBIE_BLOOD;
	m_showId = 7;
	::loadimage(&m_zomdieImg, PATH_PIC(2.jpg));
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
void CConeHeadZombie::ShowZombie() 
{
	::putimage(m_x, m_y, IMG_ConeHeadZombie_WIDHT, IMG_ConeHeadZombie_HEIGHT,&m_zomImg, IMG_ConeHeadZombie_WIDHT, (7 - m_showId) * IMG_ConeHeadZombie_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_ConeHeadZombie_WIDHT, IMG_ConeHeadZombie_HEIGHT,&m_zomImg, 0, (7 - m_showId) * IMG_ConeHeadZombie_HEIGHT, SRCAND);
}
void CConeHeadZombie::ShowDieZombie()
{
	::putimage(m_x, m_y, IMG_ConeHeadZombieB_WIDHT, IMG_ConeHeadZombieB_HEIGHT, &m_zomdieImg, IMG_ConeHeadZombieB_WIDHT, (7 - m_dieshowId) * IMG_ConeHeadZombieB_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_ConeHeadZombieB_WIDHT, IMG_ConeHeadZombieB_HEIGHT, &m_zomdieImg, 0, (7 - m_dieshowId) * IMG_ConeHeadZombieB_HEIGHT, SRCAND);
 }
bool CConeHeadZombie::IsHitBullet(int x,int y) 
{
	if (m_x<x && m_x + IMG_ConeHeadZombie_WIDHT / 2>x &&m_y <= y && y <= m_y + IMG_ConeHeadZombie_HEIGHT)
	{
		return true;
	}
	return false;
}
bool CConeHeadZombie::IsHitPlant(int x, int y)
{
	if (m_y + 69 == y && m_x<x && m_x + IMG_ConeHeadZombie_WIDHT / 2>x)
	{
		return true;
	}
	return false;
}

bool CConeHeadZombie::IsHitCherry(int x, int y)
{
	if ((m_y + 69 == y || m_y + 168 == y || m_y - 30 == y) && ((m_x<x && m_x + IMG_ConeHeadZombie_WIDHT * 2>x) || (m_x > x && m_x - IMG_ConeHeadZombie_WIDHT - IMG_CHERRY_WIDHT < x)))
	{
		return true;
	}
	return false;

}

bool CConeHeadZombie::IsHitDolly(int x, int y)
{
	if (m_y + 91 == y && m_x<x && m_x + IMG_ConeHeadZombie_WIDHT / 2>x)
	{
		return true;
	}
	return false;
}