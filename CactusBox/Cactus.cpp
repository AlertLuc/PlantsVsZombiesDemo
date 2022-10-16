//#include <iostream>
#include"Cactus.h"
#include"../GameConfig/GameConfig.h"

CCactus::CCactus()
{
	m_Cactusblood = 3;
	//m_x = 0;
	//m_y = 0;
	isdowncard = true;
}
CCactus::~CCactus()
{
}
void CCactus::InitCactus(int x, int y)
{
	::loadimage(&m_CactusImg, PATH_PIC(cactus.jpg));
	m_CactusshowId = 9;
	m_Cactusblood = DEF_CACTUS_BLOOD;
	m_x = x - IMG_CACTUS_WIDHT / 2;
	m_y = y - IMG_CACTUS_HEIGHT / 2;
}
void CCactus::ShowCactus()
{
	::putimage(m_x, m_y, IMG_CACTUS_WIDHT, IMG_CACTUS_HEIGHT,
		&m_CactusImg, IMG_CACTUS_WIDHT, (9 - m_CactusshowId) * IMG_CACTUS_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_CACTUS_WIDHT, IMG_CACTUS_HEIGHT,
		&m_CactusImg, 0, (9 - m_CactusshowId) * IMG_CACTUS_HEIGHT, SRCAND);
}
void CCactus::MoveCactus(int x, int y) {
	m_x = x;
	m_y = y;
}
CCactusshell* CCactus::SendCactusshell()
{
	CCactusshell* pCactusshell = new CCactusshell;//new A cannonball
	pCactusshell->InitCactusshell(m_x + 54, m_y + 20);//Position of initialization
	return pCactusshell;
}
