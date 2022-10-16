#include"BulletBox.h"
#include"../GameConfig/GameConfig.h"
CBulletBox::CBulletBox() 
{
}
CBulletBox::~CBulletBox() 
{
	list<CBullet*>::iterator ite = m_lstbullet.begin();
	while (ite != m_lstbullet.end()) 
	{   
		//Traversal removes the new bean
		if ((*ite))
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_lstbullet.clear();  //Deleting all Nodes
}
void CBulletBox::ShowAllBullet() 
{//Show all
	list<CBullet*>::iterator ite = m_lstbullet.begin();
	while (ite != m_lstbullet.end()) 
	{   
		//Traversal removes the new bean
		if ((*ite))
		{
			(*ite)->ShowBullet();//According to
		}
		ite++;
	}
}
void CBulletBox::MoveAllBullet(int step) 
{
	list<CBullet*>::iterator ite = m_lstbullet.begin();
	while (ite != m_lstbullet.end()) 
	{   //Traversal removes the new bean
		if ((*ite)) 
		{
			(*ite)->MoveBullet(step);
			//Determine whether the bean is out of bounds, out of bounds will be deleted
			if ((*ite)->m_x >=IMG_PLANTSVSZOMBIESBACKGROUND_WIDTH )
			{
				delete (*ite);
				(*ite) = nullptr;   //Delete the beans of new
				ite = m_lstbullet.erase(ite);  //Remove nodes
				continue;//Does not perform ite++
			}
		}
		ite++;
	}
}
