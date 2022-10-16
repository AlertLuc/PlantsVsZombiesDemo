#include<typeinfo>
#include"CactusBox.h"
#include"Cactus.h"
#include"../GameConfig/GameConfig.h"
CCactusBox::CCactusBox()
{
}
#define DELETE_PLAY(LIST)\
	list<CCactus*>::iterator ite##LIST = LIST.begin();\
	while( ite##LIST != LIST.end()  ){\
		if( *ite##LIST ){\
			delete ( *ite##LIST );\
			( *ite##LIST ) = nullptr;\
		}\
		ite##LIST++;\
	}\
	LIST.clear();
CCactusBox::~CCactusBox()
{
	DELETE_PLAY(m_lstCactus)
}
void CCactusBox::ShowAllCactus()
{
	list<CCactus*>::iterator ite = m_lstCactus.begin();
	while (ite != m_lstCactus.end())
	{
		if (*ite)
		{
			(*ite)->ShowCactus();
		}
		ite++;
	}
}
//void CCactusBox::ShowAllBoomCactus()
//{
//	list<CCactus*>::iterator ite = m_lstBoomCa.begin();
//	while (ite != m_lstBoomCa.end())
//	{
//		if (*ite)
//		{
//			(*ite)->ShowCactus();
//		}
//		ite++;
//	}
//}
bool CCactusBox::IsHitCactus(int m_x, int m_y) {
	list<CCactus*>::iterator ite = m_lstCactus.begin();
	while (ite != m_lstCactus.end())
	{
		if (*ite)
		{
			return true;
		}
		return false;
	}
}
