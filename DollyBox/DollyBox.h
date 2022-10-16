#pragma once
#include<list>
using namespace std;
#include"Dolly.h"
class CDollyBox
{
public:
	list<CDolly*> m_lstDolly;
	CDolly *m_dolly;

public:
	CDollyBox();
	~CDollyBox();
public:
	void ShowAllDolly();
	void MoveAllDolly(int step);
	void InitAllDolly(int x, int y);
};