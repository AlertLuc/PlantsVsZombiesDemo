#include"CactusshellBox.h"
#include"../GameConfig/GameConfig.h"
CCactusshellBox::CCactusshellBox()
{
}
CCactusshellBox::~CCactusshellBox()
{
	list<CCactusshell*>::iterator ite = m_lstCactusshell.begin();
	while (ite != m_lstCactusshell.end())
	{
		//Traversal removes the new bean
		if ((*ite))
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_lstCactusshell.clear();  //Deleting all Nodes
}
void CCactusshellBox::ShowAllCactusshell()
{//Show all
	list<CCactusshell*>::iterator ite = m_lstCactusshell.begin();
	while (ite != m_lstCactusshell.end())
	{
		//Traversal removes the new bean
		if ((*ite))
		{
			(*ite)->ShowCactusshell();//According to
		}
		ite++;
	}
}
void CCactusshellBox::MoveAllCactusshell(int step)
{
	list<CCactusshell*>::iterator ite = m_lstCactusshell.begin();
	while (ite != m_lstCactusshell.end())
	{   //Traversal removes the new bean
		if ((*ite))
		{
			(*ite)->MoveCactusshell(step);
			//Determine whether the bean is out of bounds, out of bounds will be deleted
			if ((*ite)->m_x >= IMG_PLANTSVSZOMBIESBACKGROUND_WIDTH)
			{
				delete (*ite);
				(*ite) = nullptr;   //Delete the beans of new
				ite = m_lstCactusshell.erase(ite);  //Remove nodes
				continue;//Does not perform ite++
			}
		}
		ite++;
	}
}
