#include"SunBox.h"
#include"../GameConfig/GameConfig.h"
#include"Sun.h"
#include"../PlantsVsZombiesApp/PlantsVsZombiesApp.h"
CSunBox::CSunBox()
{
	
}
CSunBox::~CSunBox()
{
	list<CSun*>::iterator ite = m_lstSun.begin();
	while (ite != m_lstSun.end())
	{
		if (*ite)
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_lstSun.clear();  //Deleting all Nodes
}
void CSunBox::ShowAllSun()
{
	list<CSun*>::iterator ite = m_lstSun.begin();
	while (ite != m_lstSun.end())
	{
		if (*ite)
		{
			(*ite)->ShowSun();
		}
		ite++;
	}
}
void CSunBox::ShowAllCreatSun() {
	list<CSun*>::iterator ite = m_lstSun1.begin();
	while (ite != m_lstSun1.end())
	{
		if (*ite)
		{
			(*ite)->ShowCreatSun();
		}
		ite++;
	}
}

void CSunBox::MoveAllSun()
{
	list<CSun*>::iterator ite = m_lstSun.begin();
	while (ite != m_lstSun.end())
	{
		if (*ite)
		{
				(*ite)->MoveSun(TIMER_SUN_MOVE_STEP);
		}
		ite++;
	}
}
bool CSunBox::IsHitSun(int x, int y) {
	//m_xPlant location
	//xSaid the mouse
	int m_x;
	int m_y;

	list<CSun*>::iterator ite = m_lstSun.begin();
	while (ite != m_lstSun.end())
	{
		m_x = (*ite)->m_x;
		m_y = (*ite)->m_y;
		if (x<m_x + IMG_SUN_WIDHT && x>m_x && y<m_y + IMG_SUN_HEIGHT && y>m_y) {
			/*mciSendString("play ./res/ั๔นโ.mp3", 0, 0, 0);
			delete (*ite);
			(*ite) = nullptr;*/
			return true;
		}
		ite++;
	}
	list<CSun*>::iterator ite1 = m_lstSun1.begin();
	while (ite1 != m_lstSun1.end())
	{
		m_x = (*ite1)->n_x;
		m_y = (*ite1)->n_y;
		if (x<m_x + IMG_SUN_WIDHT && x>m_x && y<m_y + IMG_SUN_HEIGHT && y>m_y) {
			/*mciSendString("play ./res/ั๔นโ.mp3", 0, 0, 0);
			delete (*ite);
			(*ite) = nullptr;*/
			return true;
		}
		ite1++;
	}

}
