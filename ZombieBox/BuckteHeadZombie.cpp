#include"BuckteHeadZombie.h"
#include"../GameConfig/GameConfig.h"

CBuckteHeadZombie::CBuckteHeadZombie()
{
}
CBuckteHeadZombie::~CBuckteHeadZombie() 
{
}
void CBuckteHeadZombie::InitZombie() 
{
	::loadimage(&m_zomImg, PATH_PIC(buckteheadzombie.jpg));
	m_blood = DEF_BUCKTEHEADZOMBIE_BLOOD;
	m_showId = 7;
	isHitePlants = false;
	::loadimage(&m_zomdieImg, PATH_PIC(2.jpg));
	m_dieshowId = 7;
	m_x = IMG_PLANTSVSZOMBIESBACKGROUND_WIDTH;
	int y= rand() % (IMG_PLANTSVSZOMBIESBACKGROUND_HEIGHT);
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
void CBuckteHeadZombie::ShowZombie()
{
	::putimage(m_x, m_y, IMG_BUCKTEHEADZOMBIE_WIDHT, IMG_BUCKTEHEADZOMBIE_HEIGHT, &m_zomImg, IMG_BUCKTEHEADZOMBIE_WIDHT, (7 - m_showId) * IMG_BUCKTEHEADZOMBIE_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_BUCKTEHEADZOMBIE_WIDHT, IMG_BUCKTEHEADZOMBIE_HEIGHT, &m_zomImg, 0, (7 - m_showId) * IMG_BUCKTEHEADZOMBIE_HEIGHT, SRCAND);
}
void CBuckteHeadZombie::ShowDieZombie()
{
	::putimage(m_x, m_y, IMG_BUCKTEHEADZOMBIEB_WIDHT, IMG_BUCKTEHEADZOMBIEB_HEIGHT, &m_zomdieImg, IMG_BUCKTEHEADZOMBIEB_WIDHT, (7 - m_dieshowId) * IMG_BUCKTEHEADZOMBIEB_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_BUCKTEHEADZOMBIEB_WIDHT, IMG_BUCKTEHEADZOMBIEB_HEIGHT, &m_zomdieImg, 0, (7 - m_dieshowId) * IMG_BUCKTEHEADZOMBIEB_HEIGHT, SRCAND);
}
bool CBuckteHeadZombie::IsHitBullet(int x,int y) 
{
	//int x = X + IMG_BULLET_WIDHT / 2;
	if (m_x<x && m_x + IMG_BUCKTEHEADZOMBIE_WIDHT / 2>x &&m_y <= y && y <= m_y + IMG_BUCKTEHEADZOMBIE_HEIGHT)
	{	
		return true;
	}
	return false;
}


bool CBuckteHeadZombie::IsHitPlant(int x,int y)
{
	if(m_y+69==y&&m_x<x && m_x+ IMG_BUCKTEHEADZOMBIE_WIDHT/2>x )
	{
		return true;
	}
	return false;
	
}
bool CBuckteHeadZombie::IsHitCherry(int x, int y)
{
	if ( (m_y + 69 == y || m_y+168==y || m_y-30==y) && ((m_x<x && m_x + IMG_BUCKTEHEADZOMBIE_WIDHT * 2>x)||(m_x>x&&m_x- IMG_BUCKTEHEADZOMBIE_WIDHT- IMG_CHERRY_WIDHT<x)))
	{
		return true;
	}
	return false;

}


bool CBuckteHeadZombie::IsHitDolly(int x, int y) {
	//m_x m_y It's the coordinates of the zombie
	if (m_y + 91 == y && m_x<x && m_x + IMG_BUCKTEHEADZOMBIE_WIDHT / 2>x)
	{
		return true;
	}
	return false;
}
