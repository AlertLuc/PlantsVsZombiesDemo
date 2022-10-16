#include"DollyBox.h"
#include"../GameConfig/GameConfig.h"
CDollyBox::CDollyBox() 
{
}
CDollyBox::~CDollyBox() 
{
	list<CDolly*>::iterator ite = m_lstDolly.begin();
	while (ite != m_lstDolly.end()) 
	{   
		//Iterate over and remove the new car
		if ((*ite))
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_lstDolly.clear();  //Deleting all Nodes
}
void CDollyBox::ShowAllDolly() 
{//Show all
	list<CDolly*>::iterator ite = m_lstDolly.begin();
	while (ite != m_lstDolly.end()) 
	{   
		//Traversal shows new car
		if ((*ite))
		{
			(*ite)->ShowDolly();//According to
		}
		ite++;
	}
}
void CDollyBox::MoveAllDolly(int step) 
{
	list<CDolly*>::iterator ite = m_lstDolly.begin();
	while (ite != m_lstDolly.end()) 
	{   //Iterate over and remove the new car
		if ((*ite)) 
		{
			(*ite)->MoveDolly(step);
			//Judge whether the car is out of bounds, out of bounds is deleted
			if ((*ite)->m_x >=IMG_PLANTSVSZOMBIESBACKGROUND_WIDTH )
			{
				delete (*ite);
				(*ite) = nullptr;   //Delete new's car
				ite = m_lstDolly.erase(ite);  //Remove nodes
				continue;//Does not perform ite++
			}
		}
		ite++;
	}
}
void CDollyBox::InitAllDolly(int x, int y) {
	int n = 5;
	while (n) {
		m_dolly = new CDolly;
		m_lstDolly.push_back(m_dolly);
		n--;
	}
	list<CDolly*>::iterator ite = m_lstDolly.begin();
	while (ite != m_lstDolly.end())
	{
		//Iterate over and remove the new car
		if ((*ite))
		{
			(*ite)->InitDolly(x,y);//According to
		}
		y += 99;
		ite++;
	}
}
