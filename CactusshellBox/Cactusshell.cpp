#include"Cactusshell.h"
#include"../GameConfig/GameConfig.h"
CCactusshell::CCactusshell()
{
	m_x = 0;
	m_y = 0;
}
CCactusshell::~CCactusshell()
{
}
void CCactusshell::InitCactusshell(int x, int y)
{
	::loadimage(&m_CactusshellImg, PATH_PIC(cactusshell.jpg));
	m_x = x;
	m_y = y;
}
void CCactusshell::ShowCactusshell()
{
	::putimage(m_x, m_y, IMG_SHELL_WIDHT, IMG_SHELL_HEIGHT,
		&m_CactusshellImg, IMG_SHELL_WIDHT, 0, SRCPAINT);
	::putimage(m_x, m_y, IMG_SHELL_WIDHT, IMG_SHELL_HEIGHT,
		&m_CactusshellImg, 0, 0, SRCAND);
}
void CCactusshell::MoveCactusshell(int step)
{
	m_x += step;
}

