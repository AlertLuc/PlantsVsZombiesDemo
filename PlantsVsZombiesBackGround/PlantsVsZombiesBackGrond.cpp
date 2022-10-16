#include"PlantsVsZombiesBackGrond.h"
#include"../GameConfig/GameConfig.h"
CPlantsVsZombiesBackGround::CPlantsVsZombiesBackGround()
{
	m_x = 0;
	m_y = 0;
}
CPlantsVsZombiesBackGround::~CPlantsVsZombiesBackGround()
{
}
void CPlantsVsZombiesBackGround::InitPlantsVsZombiesBackGround()
{
	::loadimage(&m_backImg,"./res/background.jpg");  //Stick a background
	m_y=0;
	m_x=0;
}
void CPlantsVsZombiesBackGround::showPlantsVsZombiesBackGround()
{
	::putimage(m_x,m_y,&m_backImg);//Position of display
}



