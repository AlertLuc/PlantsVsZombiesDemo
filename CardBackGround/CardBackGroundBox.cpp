#include"CardBackGroundBox.h"
#include"../GameConfig/GameConfig.h"
CCardBackGroundBox::CCardBackGroundBox()
{
}
CCardBackGroundBox::~CCardBackGroundBox()
{
	list<CCardBackGround*>::iterator ite = m_lstCardBackGround.begin();
	while (ite != m_lstCardBackGround.end())
	{
		if (*ite)
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_lstCardBackGround.clear();  //Deleting all Nodes
}
void CCardBackGroundBox::ShowAllCardBackGround()
{
	list<CCardBackGround*>::iterator ite = m_lstCardBackGround.begin();
	while (ite != m_lstCardBackGround.end())
	{
		if (*ite)
		{
			(*ite)->ShowCardBackGround();
		}
		ite++;
	}
}
bool CCardBackGroundBox::IsHitCardBackGround(int m_x, int m_y) {
	list<CCardBackGround*>::iterator ite = m_lstCardBackGround.begin();
	while (ite != m_lstCardBackGround.end())
	{
		if (*ite)
		{
			return true;
		}
		return false;
	}
}
