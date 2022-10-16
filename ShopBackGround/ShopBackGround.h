#pragma once
#include<easyx.h>
class CShopBackGround
{
public:
	IMAGE m_ShopbackImg;
	IMAGE m_ShovelbackImg;
	int   m_x;
	int   m_y;
	int   n_x;
	int   n_y;
public:
	CShopBackGround();
	~CShopBackGround();
public:
	void InitShopBackGround();
	void showShopBackGround();
	void InitShovelBackGround();
	void showShovelBackGround();
};
