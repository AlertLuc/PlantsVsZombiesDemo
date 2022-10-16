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
{//�̳�
public:
	short m_arrBack[9][5]={0};
	CPlantsVsZombiesBackGround m_back;//���屳���Ķ���
	CBulletBox   m_bulletBox;//���嶹�Ķ���
	CDollyBox m_dollyBox;//����С������
	CCactusshellBox m_shellBox; //������ڵ�
	CShovel m_shovel;

	CZombieBox   m_zomBox;
	IMAGE        m_scoreImg;
	int          m_nScore;
	CCardBackGroundBox m_cardBox;
	CShopBackGround m_shopback;
	//CPlantBox m_plantbox;
	//�㶹����
	CPeashooter array[46];
	CPeashooter *temporary;//��ʱָ��
	//list<CPeashooter*>m_peaShootList;
	//���տ�
	CSunflower arraysunf[46];
	CSunflower* TSunF;//̫������ʱָ��

	CCactus arraycactus[46];
	CCactus* TCact;//�����Ƶ���ʱָ��

	CNut arraynut[46];//�������һ��������ſն���
	CNut * TNut;//���ǽ����ʱָ��

	CCherry arraycherry[46];//������ͬʱ����10��ӣ��ը��
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
	bool InitFristZom = true;  //����coming����

	int k = 0;
	int sunfNum = 0;
	int shellNum = 0;
	int nutNum = 0;
	int cherryNum = 0;
	int boomframe = 0;

public:
	CPlantsVsZombiesApp();//����
	~CPlantsVsZombiesApp();//����
public:
	virtual void InitGame();
	virtual void PaintGame();
	virtual void CloseGame();
public:
	virtual void ON_WM_TIMER(WPARAM w, LPARAM l);//��ʱ��������
	virtual void ON_WM_KEYDOWN(WPARAM w);//���̵Ĵ�����
	virtual void ON_WM_LBUTTONDOWN(POINT po);//���Ĵ�����
	virtual void ON_WM_MOUSEMOVE(POINT po);//���Ĵ�����
	virtual void ON_WM_LBUTTONUP(POINT po);//���Ĵ�����
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
