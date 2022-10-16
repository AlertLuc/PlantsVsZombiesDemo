#include"ShopBackGround.h"
#include"../GameConfig/GameConfig.h"
CShopBackGround::CShopBackGround()
{
	m_x = 0;
	m_y = 0;
	n_x = 0;
	n_y = 0;
}
CShopBackGround::~CShopBackGround()
{
}
void CShopBackGround::InitShopBackGround()
{
	::loadimage(&m_ShopbackImg, "./res/menubar.bmp");
	m_y = 0;
	m_x = 300;
}
void CShopBackGround::InitShovelBackGround()
{
	::loadimage(&m_ShovelbackImg, "./res/ShovelBack.png");
	n_y = 30;
	n_x = 830;
}

void CShopBackGround::showShopBackGround()
{
	::putimage(m_x, m_y, &m_ShopbackImg);//Position of display
}


void CShopBackGround::showShovelBackGround()
{
	::putimage(n_x, n_y, &m_ShovelbackImg);//Position of display
}


