//#include <iostream>
#include"Nut.h"
#include"../GameConfig/GameConfig.h"
CNut::CNut()
{
	int m_plantblood = 3;
	//int m_x = 0;
	//int m_y = 0;
	isdowncard = true;
}
CNut::~CNut()
{
}
void CNut::InitNut(int x, int y)
{
	::loadimage(&m_NutImg, PATH_PIC(nut.jpg));
	m_NutshowId = 4;
	m_Nutblood = DEF_NUT_BLOOD;
	m_x = x - IMG_NUT_WIDHT / 2;
	m_y = y - IMG_NUT_HEIGHT / 2;
}
void CNut::ShowNut()
{
	::putimage(m_x, m_y, IMG_NUT_WIDHT, IMG_NUT_HEIGHT,
		&m_NutImg, IMG_NUT_WIDHT, (4 - m_NutshowId) * IMG_NUT_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_NUT_WIDHT, IMG_NUT_HEIGHT,
		&m_NutImg, 0, (4 - m_NutshowId) * IMG_NUT_HEIGHT, SRCAND);
}
void CNut::MoveNut(int x, int y) {
	m_x = x;
	m_y = y;
}