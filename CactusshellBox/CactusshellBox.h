#pragma once
#include<list>
using namespace std;
#include"Cactusshell.h"
class CCactusshellBox
{
public:
	list<CCactusshell*> m_lstCactusshell;
public:
	CCactusshellBox();
	~CCactusshellBox();
public:
	void ShowAllCactusshell();
	void MoveAllCactusshell(int step);
};