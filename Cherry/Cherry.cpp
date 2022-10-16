//#include <iostream>
#include"Cherry.h"
#include"../GameConfig/GameConfig.h"

CCherry::CCherry()
{
	m_Cherryblood = 3;
	//m_x = 0;
	//m_y = 0;
	isdowncard = true;
}
CCherry::~CCherry()
{
}
void CCherry::InitCherry(int x, int y)
{

	::loadimage(&m_CherryImg, PATH_PIC(cherry.jpg));
	::loadimage(&m_CherryBoomImg, PATH_PIC(cherryboom.jpg));
	m_Cherryblood = DEF_CHERRY_BLOOD;
	m_x = x - IMG_CHERRY_WIDHT / 2;
	m_y = y - IMG_CHERRY_HEIGHT / 2;
}

void CCherry::ShowBoomCherry()
{
	::putimage(m_x- 110, m_y- 190, IMG_CHERRY_BOOM_WIDHT, IMG_CHERRY_BOOM_HEIGHT,
		&m_CherryBoomImg, IMG_CHERRY_BOOM_WIDHT, 0, SRCPAINT);
	::putimage(m_x - 110, m_y - 190, IMG_CHERRY_BOOM_WIDHT, IMG_CHERRY_BOOM_HEIGHT,
		&m_CherryBoomImg, 0, 0, SRCAND);
}

void CCherry::ShowCherry()
{
	::putimage(m_x, m_y, IMG_CHERRY_WIDHT, IMG_CHERRY_HEIGHT,
		&m_CherryImg, IMG_CHERRY_WIDHT, 0, SRCPAINT);
	::putimage(m_x, m_y, IMG_CHERRY_WIDHT, IMG_CHERRY_HEIGHT,
		&m_CherryImg, 0, 0, SRCAND);
}
void CCherry::MoveCherry(int x, int y) {
	m_x = x;
	m_y = y;
}
