#include<typeinfo>
#include"ZombieBox.h"
#include"OrdinaryZombie.h"
#include"ConeHeadZombie.h"
#include"BuckteHeadZombie.h"
#include"FlagZombie.h"
#include"RugbyZombie.h"
#include"../GameConfig/GameConfig.h"
CZombieBox::CZombieBox() 
{
}
#define DELETE_ZOM(LIST)\
	list<CZombie*>::iterator ite##LIST = LIST.begin();\
	while( ite##LIST != LIST.end()  ){\
		if( *ite##LIST ){\
			delete ( *ite##LIST );\
			( *ite##LIST ) = nullptr;\
		}\
		ite##LIST++;\
	}\
	LIST.clear();
CZombieBox::~CZombieBox() 
{
	/*list<CZombie*>::iterator ite = m_lstZom.begin();
	while( ite != m_lstZom.end()){
		if( *ite ){
			delete ( *ite );
			( *ite ) = nullptr;
		}
		ite++;
	}
	m_lstZom.clear();*/
	DELETE_ZOM(m_lstZom)
	DELETE_ZOM(m_lstBoomZom)
}
void CZombieBox::ShowAllZombie() 
{
	list<CZombie*>::iterator ite = m_lstZom.begin();
	while (ite != m_lstZom.end()) 
	{
		if (*ite)
		{
			
			(*ite)->ShowZombie();
		}
		ite++;
	}
}
void CZombieBox::ShowAllBoomZombie() 
{
	list<CZombie*>::iterator ite = m_lstBoomZom.begin();
	while (ite != m_lstBoomZom.end()) 
	{
		if (*ite) 
		{
			(*ite)->ShowDieZombie();
		}
		ite++;
	}
}
void CZombieBox::MoveAllZombie() 
{
	list<CZombie*>::iterator ite = m_lstZom.begin();  
	while (ite != m_lstZom.end()) 
	{
		if (*ite) 
		{
			//*ite    ==  CZombie*
			//**ite    ==  *(CZombie*)
			//RTTI (RunTime Type Id) 运行时类型识别
			if (typeid(**ite) == typeid(COrdinaryZombie))
			{
				(*ite)->MoveZombie(TIMER_ORDINARYZOMBIE_MOVE_STEP);
			}
			else if (typeid(**ite) == typeid(CBuckteHeadZombie))
			{
				(*ite)->MoveZombie(TIMER_BUCKTEHEADZOMBIE_MOVE_STEP);
			}
			else if (typeid(**ite) == typeid(CConeHeadZombie))
			{
				(*ite)->MoveZombie(TIMER_CONEHEADZOMBIE_MOVE_STEP);
			}
			else if (typeid(**ite) == typeid(CFlagZombie))
			{
				(*ite)->MoveZombie(TIMER_FLAGZOMBIE_MOVE_STEP);
			}
			else if (typeid(**ite) == typeid(CRugbyZombie))
			{
				(*ite)->MoveZombie(TIMER_RUGBYZOMBIE_MOVE_STEP);
			}
			//if ((*ite)->m_x <=-170)
			//{
			//	delete* ite;
			//	*ite = nullptr;
			//	ite = m_lstZom.erase(ite);
			//	continue;
			//}
		}
		ite++;
	}
}
