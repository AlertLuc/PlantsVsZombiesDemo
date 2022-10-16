//#include <iostream>
#include"Sunflower.h"
#include"../GameConfig/GameConfig.h"
CSunflower::CSunflower()
{
	m_Sunflowerblood = 3;
	//m_x = 0;
	//m_y = 0;
	isdowncard = true;
}
CSunflower::~CSunflower()
{
}
void CSunflower::InitSunflower(int x, int y)
{
	::loadimage(&m_SunflowerImg, PATH_PIC(sunflower.jpg));
	m_SunflowershowId = 17;
	m_Sunflowerblood = DEF_SUNFLOWER_BLOOD;
	m_x = x - IMG_SUNFLOWER_WIDHT / 2;
	m_y = y - IMG_SUNFLOWER_HEIGHT / 2;
}
void CSunflower::ShowSunflower()
{
	::putimage(m_x, m_y, IMG_SUNFLOWER_WIDHT, IMG_SUNFLOWER_HEIGHT,
		&m_SunflowerImg, IMG_SUNFLOWER_WIDHT, (17 - m_SunflowershowId) * IMG_SUNFLOWER_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_SUNFLOWER_WIDHT, IMG_SUNFLOWER_HEIGHT,
		&m_SunflowerImg, 0, (17 - m_SunflowershowId) * IMG_SUNFLOWER_HEIGHT, SRCAND);
}
void CSunflower::MoveSunflower(int x, int y) {
	m_x = x;
	m_y = y;
}
CSun* CSunflower::CreatSun()
{
	CSun* pSun = new CSun;//new一个太阳
	pSun->InitSun(m_x + IMG_SUN_WIDHT/2, m_y - IMG_SUNFLOWER_HEIGHT + IMG_SUN_HEIGHT / 2);//初始化豆位置
	return pSun;
}
