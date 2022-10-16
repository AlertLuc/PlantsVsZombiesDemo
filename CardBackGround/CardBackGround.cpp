#include"CardBackGround.h"
#include"../GameConfig/GameConfig.h"
CCardBackGround::CCardBackGround()
{
	 m_x = 0;
     m_y = 0;
}
CCardBackGround::~CCardBackGround()
{
}
void CCardBackGround::InitCardBackGround()
{
	::loadimage(&m_CardbackImg, "./res/pshcard1.jpg");
	m_y = 9;
	m_x = 380;
}
void CCardBackGround::ShowCardBackGround()
{
	::putimage(m_x, m_y,&m_CardbackImg);
}
