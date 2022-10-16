#include<typeinfo>
#include"PlantBox.h"
#include"Peashooter.h"
#include"../GameConfig/GameConfig.h"
CPlantBox::CPlantBox() 
{
}
#define DELETE_PLAY(LIST)\
	list<CPeashooter*>::iterator ite##LIST = LIST.begin();\
	while( ite##LIST != LIST.end()  ){\
		if( *ite##LIST ){\
			delete ( *ite##LIST );\
			( *ite##LIST ) = nullptr;\
		}\
		ite##LIST++;\
	}\
	LIST.clear();
CPlantBox::~CPlantBox()
{
	DELETE_PLAY(m_lstPlant)
}
void CPlantBox::ShowAllPlant()
{
	list<CPeashooter*>::iterator ite = m_lstPlant.begin();
	while (ite != m_lstPlant.end()) 
	{
		if (*ite) 
		{
			(*ite)->ShowPlant();
		}
		ite++;
	}

	/*static CPeashooter* peashooter1;
	static CPeashooter* peashooter2;
	*p = peashooter1;
	peashooter2 = peashooter1;
	peashooter1->InitPlant(x,y);
	peashooter1->ShowPlant();
	
	peashooter2 ->Next = peashooter1;*/
}
void CPlantBox::ShowAllBoomPlant()
{
	list<CPeashooter*>::iterator ite = m_lstBoomPla.begin();
	while (ite != m_lstBoomPla.end())
	{
		if (*ite)
		{
			(*ite)->ShowPlant();
		}
		ite++;
	}
}
bool CPlantBox::IsHitPlant(int m_x, int m_y) {
	list<CPeashooter*>::iterator ite = m_lstPlant.begin();
	while (ite != m_lstPlant.end())
	{
		if (*ite)
		{
			return true;
		}
		return false;
	}
}
