#pragma once
#include"../GameFrame/GameFrame.h"
#include"../PlantsVsZombiesBackGround/PlantsVsZombiesBackGrond.h"
#include"../PlantBox/Peashooter.h"
#include"../BulletBox/BulletBox.h"
#include"../ZombieBox/ZombieBox.h"
#include"../ShopBackGround/ShopBackGround.h"
#include"../PlantBox/PlantBox.h"
#include"../CardBackGround/CardBackGround.h"
#include"../Sun/SunBox.h"
#include"../CardBackGround/CardBackGroundBox.h"
#include"../Sunflower/Sunflower.h"
#include"../CactusBox/Cactus.h"
#include"../CactusshellBox/Cactusshell.h"
#include"../CactusshellBox/CactusshellBox.h"
#include"../DollyBox/DollyBox.h"
#include"../nut/NutBox.h"
#include"../Cherry/CherryBox.h"
#include"../Shovel/Shovel.h"

class CPlantsVsZombiesApp:public CGameFrame
{//继承
public:
	short m_arrBack[9][5]={0};
	CPlantsVsZombiesBackGround m_back;//定义背景的对象
	CBulletBox   m_bulletBox;//定义豆的对象
	CDollyBox m_dollyBox;//定义小车对象
	CCactusshellBox m_shellBox; //定义刺炮弹
	CShovel m_shovel;

	CZombieBox   m_zomBox;
	IMAGE        m_scoreImg;
	int          m_nScore;
	CCardBackGroundBox m_cardBox;
	CShopBackGround m_shopback;
	//CPlantBox m_plantbox;
	//豌豆射手
	CPeashooter array[46];
	CPeashooter *temporary;//临时指针
	//list<CPeashooter*>m_peaShootList;
	//向日葵
	CSunflower arraysunf[46];
	CSunflower* TSunF;//太阳的临时指针

	CCactus arraycactus[46];
	CCactus* TCact;//仙人掌的临时指针

	CNut arraynut[46];//多出来的一个用来存放空对象
	CNut * TNut;//坚果墙的临时指针

	CCherry arraycherry[46];//最多界面同时出现10个樱桃炸弹
	CCherry* TCherry;
	CCherry m_cherry[46];

	CSunBox m_sunBox;
	IMAGE        m_sunscoreImg;
	int          m_sunScore=0;
	
	bool isHiteCard = false;
	bool isdownshooter = false;
	bool isdownflower = false;
	bool isdowncactus = false;
	bool isdownnut = false;
	bool isdowncherry = false;
	bool isdownshovel = false;
	bool InitFristZom = true;  //控制coming音乐

	int k = 0;
	int sunfNum = 0;
	int shellNum = 0;
	int nutNum = 0;
	int cherryNum = 0;
	int boomframe = 0;

public:
	CPlantsVsZombiesApp();//构造
	~CPlantsVsZombiesApp();//析构
public:
	virtual void InitGame();
	virtual void PaintGame();
	virtual void CloseGame();
public:
	virtual void ON_WM_TIMER(WPARAM w, LPARAM l);//定时器处理函数
	virtual void ON_WM_KEYDOWN(WPARAM w);//键盘的处理函数
	virtual void ON_WM_LBUTTONDOWN(POINT po);//鼠标的处理函数
	virtual void ON_WM_MOUSEMOVE(POINT po);//鼠标的处理函数
	virtual void ON_WM_LBUTTONUP(POINT po);//鼠标的处理函数
public:
	void GameOver();
	void ShowScore();
	void ShowSunScore();
	void ShowAllPeashooter();
	void ShowAllSunflower();
	void ShowAllCactus();
	void ShowAllNut();
	void OnBnClickedButton1();
	void ShowAllCherry();
	void ShowAllBoomCherry();
};
