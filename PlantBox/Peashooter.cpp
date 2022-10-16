//#include <iostream>
#include"Peashooter.h"
#include"../GameConfig/GameConfig.h"

CPeashooter::CPeashooter()
{
	m_plantblood=1;
	//m_x = 0;
	//m_y = 0;
	isdowncard = true;  //Determine if the plant is planted
}
CPeashooter::~CPeashooter() 
{
}
void CPeashooter::InitPlant(int x,int y)
{
	::loadimage(&m_playerImg, PATH_PIC(peashooter.jpg));
	m_playershowId = 11;
	m_plantblood = DEF_PEASHOOTER_BLOOD;
    m_x = x-IMG_PEASHOOTER_WIDHT/2 ;
	m_y = y-IMG_PEASHOOTER_HEIGHT/2;
}
void CPeashooter::ShowPlant() 
{
	::putimage(m_x, m_y, IMG_PEASHOOTER_WIDHT, IMG_PEASHOOTER_HEIGHT,
		&m_playerImg, IMG_PEASHOOTER_WIDHT, (11 - m_playershowId) * IMG_PEASHOOTER_HEIGHT, SRCPAINT);
	::putimage(m_x, m_y, IMG_PEASHOOTER_WIDHT, IMG_PEASHOOTER_HEIGHT,
		&m_playerImg, 0, (11 - m_playershowId) * IMG_PEASHOOTER_HEIGHT, SRCAND);
}
void CPeashooter::MovePlant(int x, int y) {
	m_x = x;
	m_y = y;
}
CBullet* CPeashooter::SendBullet()
{
	CBullet* pBullet = new CBullet;//new A bean
	pBullet->InitBullet(m_x + IMG_BULLET_WIDHT, m_y+1 );//Initialize the bean position
	return pBullet;
}
