#pragma once
#include<easyx.h>
class CCardBackGround
{
public:
	IMAGE m_CardbackImg;
	int   m_x;
	int   m_y;
public:
	CCardBackGround();
	~CCardBackGround();
public:
	void InitCardBackGround();
	void ShowCardBackGround();
};


