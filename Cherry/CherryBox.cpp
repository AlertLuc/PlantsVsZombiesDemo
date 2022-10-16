#include<typeinfo>
#include"CherryBox.h"
#include"Cherry.h"
#include"../GameConfig/GameConfig.h"
CCherryBox::CCherryBox()
{
}
#define DELETE_PLAY(LIST)\
	list<CCherry*>::iterator ite##LIST = LIST.begin();\
	while( ite##LIST != LIST.end()  ){\
		if( *ite##LIST ){\
			delete ( *ite##LIST );\
			( *ite##LIST ) = nullptr;\
		}\
		ite##LIST++;\
	}\
	LIST.clear();
CCherryBox::~CCherryBox()
{
	DELETE_PLAY(m_lstCherry)
}
void CCherryBox::ShowAllCherry()
{
	list<CCherry*>::iterator ite = m_lstCherry.begin();
	while (ite != m_lstCherry.end())
	{
		if (*ite)
		{
			(*ite)->ShowCherry();
		}
		ite++;
	}
}
void CCherryBox::ShowAllBoomCherry()
{
	list<CCherry*>::iterator ite = m_lstBoomCHERRY.begin();
	while (ite != m_lstBoomCHERRY.end())
	{
		if (*ite)
		{
			(*ite)->ShowCherry();
		}
		ite++;
	}
}
bool CCherryBox::IsHitCherry(int m_x, int m_y) {
	list<CCherry*>::iterator ite = m_lstCherry.begin();
	while (ite != m_lstCherry.end())
	{
		if (*ite)
		{
			return true;
		}
		return false;
	}
}
