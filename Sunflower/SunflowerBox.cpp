#include<typeinfo>
#include"SunflowerBox.h"
#include"Sunflower.h"
#include"../GameConfig/GameConfig.h"
CSunflowerBox::CSunflowerBox()
{
}
#define DELETE_PLAY(LIST)\
	list<CSunflower*>::iterator ite##LIST = LIST.begin();\
	while( ite##LIST != LIST.end()  ){\
		if( *ite##LIST ){\
			delete ( *ite##LIST );\
			( *ite##LIST ) = nullptr;\
		}\
		ite##LIST++;\
	}\
	LIST.clear();
CSunflowerBox::~CSunflowerBox()
{
	DELETE_PLAY(m_lstSunflower)
}
void CSunflowerBox::ShowAllSunflower()
{
	list<CSunflower*>::iterator ite = m_lstSunflower.begin();
	while (ite != m_lstSunflower.end())
	{
		if (*ite)
		{
			(*ite)->ShowSunflower();
		}
		ite++;
	}
	
}
void CSunflowerBox::ShowAllBoomSunflower()
{
	list<CSunflower*>::iterator ite = m_lstBoomSunf.begin();
	while (ite != m_lstBoomSunf.end())
	{
		if (*ite)
		{
			(*ite)->ShowSunflower();
		}
		ite++;
	}
}
bool CSunflowerBox::IsHitSunflower(int m_x, int m_y) {
	list<CSunflower*>::iterator ite = m_lstSunflower.begin();
	while (ite != m_lstSunflower.end())
	{
		if (*ite)
		{
			return true;
		}
		return false;
	}
}
