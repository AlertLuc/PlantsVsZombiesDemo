#include<typeinfo>
#include"NutBox.h"
#include"Nut.h"
#include"../GameConfig/GameConfig.h"
CNutBox::CNutBox()
{
}
#define DELETE_PLAY(LIST)\
	list<CNut*>::iterator ite##LIST = LIST.begin();\
	while( ite##LIST != LIST.end()  ){\
		if( *ite##LIST ){\
			delete ( *ite##LIST );\
			( *ite##LIST ) = nullptr;\
		}\
		ite##LIST++;\
	}\
	LIST.clear();
CNutBox::~CNutBox()
{
	DELETE_PLAY(m_lstNut)
}
void CNutBox::ShowAllNut()
{
	list<CNut*>::iterator ite = m_lstNut.begin();
	while (ite != m_lstNut.end())
	{
		if (*ite)
		{
			(*ite)->ShowNut();
		}
		ite++;
	}
}
void CNutBox::ShowAllBoomNut()
{
	list<CNut*>::iterator ite = m_lstBoomNut.begin();
	while (ite != m_lstBoomNut.end())
	{
		if (*ite)
		{
			(*ite)->ShowNut();
		}
		ite++;
	}
}
bool CNutBox::IsHitNut(int m_x, int m_y) {
	list<CNut*>::iterator ite = m_lstNut.begin();
	while (ite != m_lstNut.end())
	{
		if (*ite)
		{
			return true;
		}
		return false;
	}
}
