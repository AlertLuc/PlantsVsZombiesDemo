#include"PlantsVsZombiesApp.h"
#include"../GameConfig/GameConfig.h"
#include<time.h>
#include<typeinfo>
#include"../ZombieBox/BuckteHeadZombie.h"
#include"../ZombieBox/ConeHeadZombie.h"
#include"../ZombieBox/OrdinaryZombie.h"
#include"../ZombieBox/RugbyZombie.h"
#include"../ZombieBox/FlagZombie.h"
#include"../Sun/SunBox.h"
#include"../CardBackGround/CardBackGroundBox.h"
#include"../Sunflower/SunflowerBox.h"


DYNAMIC_OBJECT(CPlantsVsZombiesApp)//DYNAMIC_OBJECT(CLASS_NAME)
WINDOW_PARAM(WINDOW_X,WINDOW_Y,WINDOW_WIDTH,WINDOW_HEIGHT,WINDOW_TITLE)//WINDOW_PARAM(X,Y,WIDHT,HEIGHT,TITLE)
CPlantsVsZombiesApp::CPlantsVsZombiesApp() 
{
	//m_arrBack[5][9] = { 0 };
	m_nScore = 0;
    m_sunScore=100;
}
CPlantsVsZombiesApp::~CPlantsVsZombiesApp()
{
}
void CPlantsVsZombiesApp::InitGame()
{
	//设置随机种子
	srand((unsigned int)time(NULL));
	//初始化背景
	m_back.InitPlantsVsZombiesBackGround();
	//初始化商店背景
	m_shopback.InitShopBackGround();

	m_cardBox.ShowAllCardBackGround();
	//初始化所有豆
	m_bulletBox.ShowAllBullet();

	//初始化刺炮弹
	m_shellBox.ShowAllCactusshell();

	//初始化小车
	m_dollyBox.InitAllDolly(175,91);

	m_shopback.InitShovelBackGround();

	//
	m_shovel.InitShovel(828, 0);

	//贴分数板的图
	::loadimage(&m_scoreImg, PATH_PIC(cardboard.png));
	::loadimage(&m_sunscoreImg, PATH_PIC(sun.png));
	//设定定时器
	//植物移动
	::SetTimer(m_hWnd, TIMER_PEASHOOTER_MOVE_ID, TIMER_PEASHOOTER_MOVE_INTERVAL, nullptr);//id、间隔
	//豆移动
	::SetTimer(m_hWnd,TIMER_BULLET_MOVE_ID,TIMER_BULLET_MOVE_INTERVAL,nullptr);
	//豆移动
	::SetTimer(m_hWnd, TIMER_BULLET_MOVE_ID, TIMER_BULLET_MOVE_INTERVAL, nullptr);
	//豆定时发射
	::SetTimer(m_hWnd, TIMER_BULLET_SEND_ID, TIMER_BULLET_SEND_INTERVAL, nullptr);
	//太阳移动
	::SetTimer(m_hWnd, TIMER_SUN_MOVE_ID, TIMER_SUN_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_SUN_CREATE_ID, TIMER_SUN_CREATE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_CARDBACKGROUND_CREATE_ID, TIMER_CARDBACKGROUND_CREATE_INTERVAL, nullptr);
	//普通僵尸定时移动
	::SetTimer(m_hWnd, TIMER_ORDINARYZOMBIE_MOVE_ID, TIMER_ORDINARYZOMBIE_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_ORDINARYZOMBIE_CREATE_ID, TIMER_ORDINARYZOMBIE_CREATE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_BUCKTEHEADZOMBIE_CREATE_ID, TIMER_BUCKTEHEADZOMBIE_CREATE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_CONEHEADZOMBIE_CREATE_ID, TIMER_CONEHEADZOMBIE_CREATE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_RUGBYZOMBIE_CREATE_ID, TIMER_RUGBYZOMBIE_CREATE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_FLAGZOMBIE_CREATE_ID, TIMER_FLAGZOMBIE_CREATE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_IS_HIT_ID, TIMER_IS_HIT_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_CHANGE_SHOWID_ID, TIMER_CHANGE_SHOWID_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_START_SHOWID_ID, TIMER_KAISHI_SHOWID_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_GANGKAISHI_SHOWID_ID, TIMER_GANGKAISHI_SHOWID_INTERVAL, nullptr);
	//向日葵扭动
	::SetTimer(m_hWnd, TIMER_SUNFLOWER_SHOWID_ID, TIMER_SUNFLOWER_SHOWID_INTERVAL, nullptr);
	//向日葵产生太阳
	::SetTimer(m_hWnd, TIMER_SUNFLOWER_CREATE_ID, TIMER_SUNFLOWER_CREATE_INTERVAL, nullptr);
	//
	::SetTimer(m_hWnd, TIMER_SHELL_CREATE_ID, TIMER_SHELL_CREATE_INTERVAL, nullptr);
	//
	::SetTimer(m_hWnd, TIMER_SHELL_MOVE_ID, TIMER_SHELL_MOVE_INTERVAL, nullptr);
	//
	::SetTimer(m_hWnd, TIMER_CACTUS_SHOWID_ID, TIMER_CACTUS_SHOWID_INTERVAL, nullptr);

	::SetTimer(m_hWnd, TIMER_DOLLY_MOVE_ID, TIMER_DOLLY_MOVE_INTERVAL, nullptr);
	//樱桃爆炸
	::SetTimer(m_hWnd, TIMER_CHERRY_BOOM_ID, TIMER_CHERRY_BOOM_INTERVAL, nullptr);

	::SetTimer(m_hWnd, TIMER_CHERRY_BOOMFRAME_ID, TIMER_CHERRY_BOOMFRAME_INTERVAL, nullptr);

	::SetTimer(m_hWnd, TIMER_NUT_CREATE_ID, TIMER_SUNFLOWER_CREATE_INTERVAL, nullptr);

	::SetTimer(m_hWnd, TIMER_SHOVEL_SHOW_ID, TIMER_SHOVEL_SHOW_INTERVAL, nullptr);
}

void CPlantsVsZombiesApp::PaintGame()//显示
{
	//显示背景图片
	m_back.showPlantsVsZombiesBackGround();
	//显示商店图片
	m_shopback.showShopBackGround();
    ShowSunScore();
	//显示卡片图片
	m_cardBox.ShowAllCardBackGround();

	//显示豆
	m_bulletBox.ShowAllBullet();

	//显示小车
	m_dollyBox.ShowAllDolly();

	m_shopback.showShovelBackGround();
	
	//显示铲子
	m_shovel.ShowShovel();


	//显示炮弹
	m_shellBox.ShowAllCactusshell();
	
	
	//显示太阳
	m_sunBox.ShowAllSun();
	m_sunBox.ShowAllCreatSun();
	//显示僵尸
	m_zomBox.ShowAllZombie();
	
	//显示打爆的僵尸
	m_zomBox.ShowAllBoomZombie();
	
	//显示分数
	ShowScore();
	//显示豌豆射手
	ShowAllPeashooter();
	
	//显示向日葵
	ShowAllSunflower();
	
	//显示仙人掌
	ShowAllCactus();

	//显示坚果墙
	ShowAllNut();

	//显示樱桃
	ShowAllCherry();

	//显示爆炸樱桃
	ShowAllBoomCherry();
	
}
void CPlantsVsZombiesApp::CloseGame()//关闭
{
}
#define CREATE_ZOM(ZOM_CLASS)\
	CZombie* pZom = new ZOM_CLASS;\
	pZom-> InitZombie();\
	m_zomBox.m_lstZom.push_back(pZom);
//定时器消息的处理函数（子类重写）
void CPlantsVsZombiesApp::ON_WM_TIMER(WPARAM w, LPARAM l)
{
	switch (w)
	{
		//太阳的移动
	case TIMER_SUN_MOVE_ID:
	{
		m_sunBox.MoveAllSun();
		//m_sunBox.ShowAllCreatSun();
	}
	break;
	//产生阳光
	case TIMER_SUN_CREATE_ID:
	{
		CSun* pSun = new CSun;
		pSun->InitSun(0,0);
		m_sunBox.m_lstSun.push_back(pSun);
	}
	break;
	//向日葵产生阳光分数
	case TIMER_SUNFLOWER_CREATE_ID: {
		/*m_sunScore += 25 * sunfNum;*/
		for (int i = 0; i < sunfNum; i++) {
			if (!(arraysunf[i].isdowncard))
			{
				//豌豆射手去调用发射豆
				CSun* pSun = arraysunf[i].CreatSun();
				//豆放到豆盒里
				m_sunBox.m_lstSun1.push_back(pSun);
			}
		}
	}
	 break;
				  //卡片插入
	case TIMER_CARDBACKGROUND_CREATE_ID:
	{
		CCardBackGround* pCard = new CCardBackGround;
		pCard->InitCardBackGround();
		m_cardBox.m_lstCardBackGround.push_back(pCard);
	}
	break;
	//显示铲子
	case TIMER_SHOVEL_SHOW_ID: {

		m_shovel.ShowShovel();
	}
	break;
	//豆移动的定时器
	case TIMER_BULLET_MOVE_ID:
	{
		m_bulletBox.MoveAllBullet(TIMER_BULLET_MOVE_STEP);
	}
	break;

	//刺炮弹移动定时器

	case TIMER_SHELL_MOVE_ID:
	{
		m_shellBox.MoveAllCactusshell(TIMER_SHELL_MOVE_STEP);
	}
	break;

	//樱桃爆炸定时器
	case TIMER_CHERRY_BOOM_ID: 
	{
		for (int i = 0; i <= cherryNum; i++) {
			if (!(arraycherry[i].isdowncard))
			{
				mciSendString("play ./res/cherrybomb.mp3", 0, 0, 0);
				//arraycherry[i].ShowCherry();
				int length = (arraycherry[i].m_x - 251) / 83;
				int width = (arraycherry[i].m_y - 69) / 99;
				m_arrBack[length][width] = 0;
				
				m_cherry[boomframe++] = arraycherry[i];

				for (int j = i; j < cherryNum; j++) {
					arraycherry[j] = arraycherry[j + 1];
					//m_cherry[j] = arraycherry[j + 1];
				}
				cherryNum--;
			}
			
		}
	}
	break;

	//樱桃爆炸火焰销毁定时器
	case TIMER_CHERRY_BOOMFRAME_ID:
	{
		while(boomframe)
		for (int i = 0; i <= boomframe; i++) {
			m_cherry[i] = m_cherry[i + 1];
			boomframe--;
		}
	}
	break;


	//刺炮弹发射定时器
	case TIMER_SHELL_CREATE_ID:
	{
		list<CZombie*>::iterator ite = m_zomBox.m_lstZom.begin();
		while (ite != m_zomBox.m_lstZom.end())
		{
			if (*ite) {
				for (int i = 0; i < shellNum; i++) {
					if (!(arraycactus[i].isdowncard)&&((*ite)->m_y+69== arraycactus[i].m_y))
					{
						//植物种下并且这一行有植物
						CCactusshell* pshells = arraycactus[i].SendCactusshell();
						//豆放到豆盒里
						m_shellBox.m_lstCactusshell.push_back(pshells);
					}
				}
			}
			ite++;
		}
	}
	break;
	//控制小车向前移动

	case TIMER_DOLLY_MOVE_ID: {
		list<CDolly*>::iterator itedolly = m_dollyBox.m_lstDolly.begin();
		while (itedolly != m_dollyBox.m_lstDolly.end())
		{
			bool Isboomdolly = false;
			if ((*itedolly)->ishit)
			{
				(*itedolly)->MoveDolly(TIMER_DOLLY_MOVE_STEP);
			}
			if ((*itedolly)->m_x >= 1400)
			{
				delete (*itedolly);  //删除小车
				(*itedolly) = nullptr;
				//删除节点
				itedolly = m_dollyBox.m_lstDolly.erase(itedolly);
				Isboomdolly = true;
			}
			if(!Isboomdolly)
			itedolly++;
		}
	}
	break;

	//豆发射的定时器
	case TIMER_BULLET_SEND_ID:  
	{
		list<CZombie*>::iterator ite = m_zomBox.m_lstZom.begin();
		while (ite != m_zomBox.m_lstZom.end())
		{
			if (*ite) {
				for (int i = 0; i < k; i++) {
					if (!(array[i].isdowncard) && ((*ite)->m_y + 69 == array[i].m_y))
					{
						//植物种下并且这一行有植物
						CBullet* pBullets = array[i].SendBullet();
						//刺炮弹放到炮弹盒里
						m_bulletBox.m_lstbullet.push_back(pBullets); 
					}
				}
			}
			ite++;
		}
	}
	break;

	case TIMER_ORDINARYZOMBIE_MOVE_ID:
	{
		mciSendString("open ./res/theZombiesareComing.mp3", 0, 0, 0);
		//m_zomBox.MoveAllZombie();//僵尸移动
		list<CZombie*>::iterator ite = m_zomBox.m_lstZom.begin();
		while (ite != m_zomBox.m_lstZom.end())
		{
			if (*ite)
			{
				if (ite == m_zomBox.m_lstZom.begin()&& InitFristZom) {//第一个僵尸出现播放coming音乐
					mciSendString("play ./res/theZombiesareComing.mp3", 0, 0, 0);
					InitFristZom = false;
				}
				if (typeid(**ite) == typeid(COrdinaryZombie))
				{
					if (!((*ite)->isHitePlants)) {
						(*ite)->MoveZombie(TIMER_ORDINARYZOMBIE_MOVE_STEP);
					}
				}
				else if (typeid(**ite) == typeid(CBuckteHeadZombie))
				{
					if (!((*ite)->isHitePlants)) {
						(*ite)->MoveZombie(TIMER_BUCKTEHEADZOMBIE_MOVE_STEP);
					}					
				}
				else if (typeid(**ite) == typeid(CConeHeadZombie))
				{
					if (!((*ite)->isHitePlants)) {
						(*ite)->MoveZombie(TIMER_CONEHEADZOMBIE_MOVE_STEP);
					}					
				}
				else if (typeid(**ite) == typeid(CFlagZombie))
				{
					if ((!(*ite)->isHitePlants)) {
						(*ite)->MoveZombie(TIMER_FLAGZOMBIE_MOVE_STEP);
					}				
				}
				else if (typeid(**ite) == typeid(CRugbyZombie))
				{
					if ((!(*ite)->isHitePlants)) {
						(*ite)->MoveZombie(TIMER_RUGBYZOMBIE_MOVE_STEP);
					}
				}
			}
			ite++;
		}

	}
	break;
	case TIMER_ORDINARYZOMBIE_CREATE_ID:
	{
		CREATE_ZOM(COrdinaryZombie)
	}
	break;

	case TIMER_BUCKTEHEADZOMBIE_CREATE_ID:
	{
		CREATE_ZOM(CBuckteHeadZombie)
	}
	break;
	case TIMER_CONEHEADZOMBIE_CREATE_ID:
	{
		CREATE_ZOM(CConeHeadZombie)
	}
	break;
	case TIMER_FLAGZOMBIE_CREATE_ID:
	{
		CREATE_ZOM(CFlagZombie)
		mciSendString("play ./res/groan4.mp3", 0, 0, 0);
	}
	break;
	case TIMER_RUGBYZOMBIE_CREATE_ID:
	{
		CREATE_ZOM(CRugbyZombie)
	}
	break;
	case TIMER_IS_HIT_ID:   //定时检测是否撞击(僵尸-》豆，僵尸-》豌豆射手）
	{
		list<CZombie*>::iterator iteZom = m_zomBox.m_lstZom.begin();
		while (iteZom != m_zomBox.m_lstZom.end()) 
		{
			bool isBoom = false;
			bool isBoom1 = false;
			bool isBoom2 = false;
			if ((*iteZom)) 
			{
				//1. 判断是否撞击豌豆射手
				for (int i = 0; i < k; i++) {
					if ((*iteZom)->IsHitPlant(array[i].m_x,array[i].m_y) && !array[i].isdowncard )
					{	//撞击豌豆射手且植物种下时
						if (array == NULL  || k < 0) {
								

						}
						else {//删除豌豆射手
							if (array[i].m_plantblood > 0) {
								(*iteZom)->isHitePlants = true;
								m_zomBox.m_lstStopZom.push_back(*iteZom);

								mciSendString("play ./res/正在吃植物.mp3", 0, 0, 0);
								array[i].m_plantblood--;
							}
							else if (array[i].m_plantblood<=0) {//植物血量减为0
								list<CZombie*>::iterator iteStopZom = m_zomBox.m_lstStopZom.begin();
								while (iteStopZom != m_zomBox.m_lstStopZom.end())
								{
									if(*iteStopZom)
									(*iteStopZom)->isHitePlants = false;
									iteStopZom++;
								}
							int length = (array[i].m_x - 251) / 83;
							int width = (array[i].m_y - 69) / 99;
							m_arrBack[length][width] = 0;
							for (int j = i; j < k; j++) {

								array[j] = array[j + 1];

							}
							k--;
							mciSendString("play ./res/吃掉植物.mp3", 0, 0, 0);
							}
							
						}
					}
				}
				//2.检测是否撞击向日葵
				for (int i = 0; i < sunfNum; i++) {
					if ((*iteZom)->IsHitPlant(arraysunf[i].m_x, arraysunf[i].m_y) && !arraysunf[i].isdowncard )
					{	//撞击豌豆射手且植物种下时
						if (arraysunf == NULL  || sunfNum < 0) {


						}
						else {//删除向日葵
							if (arraysunf[i].m_Sunflowerblood > 0) {
								(*iteZom)->isHitePlants = true;
								m_zomBox.m_lstStopZom.push_back(*iteZom);

								mciSendString("play ./res/正在吃植物.mp3", 0, 0, 0);
								arraysunf[i].m_Sunflowerblood--;
							}
							else if (arraysunf[i].m_Sunflowerblood <= 0) {//植物血量减为0
								list<CZombie*>::iterator iteStopZom = m_zomBox.m_lstStopZom.begin();
								while (iteStopZom != m_zomBox.m_lstStopZom.end())
								{
									if (*iteStopZom)
										(*iteStopZom)->isHitePlants = false;
									iteStopZom++;
								}
								int length = (arraysunf[i].m_x - 251) / 83;
								int width = (arraysunf[i].m_y - 69) / 99;
								m_arrBack[length][width] = 0;
								for (int j = i; j < sunfNum; j++) {

									arraysunf[j] = arraysunf[j + 1];

								}
								sunfNum--;
								mciSendString("play ./res/吃掉植物.mp3", 0, 0, 0);
							}

						}
					}
				}
				//3.检测是否撞击仙人掌
				for (int i = 0; i < shellNum; i++) {
					if ((*iteZom)->IsHitPlant(arraycactus[i].m_x, arraycactus[i].m_y) && !arraycactus[i].isdowncard)
					{	//撞击豌豆射手且植物种下时
						if (arraycactus == NULL  || shellNum < 0) {


						}
						else {//删除仙人掌
							if (arraycactus[i].m_Cactusblood > 0) {
								(*iteZom)->isHitePlants = true;
								m_zomBox.m_lstStopZom.push_back(*iteZom);

								mciSendString("play ./res/正在吃植物.mp3", 0, 0, 0);
								arraycactus[i].m_Cactusblood--;
							}
							else if (arraycactus[i].m_Cactusblood <= 0) {//植物血量减为0
								list<CZombie*>::iterator iteStopZom = m_zomBox.m_lstStopZom.begin();
								while (iteStopZom != m_zomBox.m_lstStopZom.end())
								{
									if (*iteStopZom)
									{
										(*iteStopZom)->isHitePlants = false;
									}
									iteStopZom++;
								}
								int length = (arraycactus[i].m_x - 251) / 83;
								int width = (arraycactus[i].m_y - 69) / 99;
								m_arrBack[length][width] = 0;
								for (int j = i; j < shellNum; j++) {

									arraycactus[j] = arraycactus[j + 1];

								}
								shellNum--;
								mciSendString("play ./res/吃掉植物.mp3", 0, 0, 0);
							}

						}
					}
				}
				//4.检测是否撞击坚果墙
				for (int i = 0; i < nutNum; i++) {
					if ((*iteZom)->IsHitPlant(arraynut[i].m_x, arraynut[i].m_y) && !arraynut[i].isdowncard)
					{	//撞击豌豆射手且植物种下时
						if (arraynut == NULL || nutNum < 0) {


						}
						else {//删除仙人掌
							if (arraynut[i].m_Nutblood > 0) {
								(*iteZom)->isHitePlants = true;
								m_zomBox.m_lstStopZom.push_back(*iteZom);

								mciSendString("play ./res/正在吃植物.mp3", 0, 0, 0);
								arraynut[i].m_Nutblood--;
							}
							else if (arraynut[i].m_Nutblood <= 0) {//植物血量减为0
								list<CZombie*>::iterator iteStopZom = m_zomBox.m_lstStopZom.begin();
								while (iteStopZom != m_zomBox.m_lstStopZom.end())
								{
									if (*iteStopZom)
									{
										(*iteStopZom)->isHitePlants = false;
									}
									iteStopZom++;
								}
								int length = (arraynut[i].m_x - 251) / 83;
								int width = (arraynut[i].m_y - 69) / 99;
								m_arrBack[length][width] = 0;
								for (int j = i; j < nutNum; j++) {

									arraynut[j] = arraynut[j + 1];

								}
								nutNum--;
								mciSendString("play ./res/吃掉植物.mp3", 0, 0, 0);
							}
						}
					}
				}
				//5.检测是否撞击樱桃炸弹
				for (int i = 0; i < cherryNum; i++) {
					if ((*iteZom)->IsHitCherry(arraycherry[i].m_x, arraycherry[i].m_y) && !arraycherry[i].isdowncard )
					{	//撞击豌豆射手且植物种下时
						if (arraycherry == NULL || cherryNum < 0) {


						}
						else {//删除仙人掌
							if ((*iteZom)->IsHitPlant(arraycherry[i].m_x, arraycherry[i].m_y))
							{
								mciSendString("play ./res/正在吃植物.mp3", 0, 0, 0);
								//arraycherry[i].m_Cherryblood--;
							}
							(*iteZom)->m_blood -= DEF_CHERRY_HURT;
							if ((*iteZom)->m_blood <= 0)
							{
								m_zomBox.m_lstBoomZom.push_back(*iteZom);  //添加到爆炸链表中
								iteZom = m_zomBox.m_lstZom.erase(iteZom);
								isBoom2 = true;
								m_nScore += 3;
								break;
							}
							continue;
						}
					}
				}
				
				if (iteZom != m_zomBox.m_lstZom.end()) {
					// 6. 判断是否撞击豆
					list<CBullet*>::iterator iteBullet = m_bulletBox.m_lstbullet.begin();
					while (iteBullet != m_bulletBox.m_lstbullet.end())
					{
						if ((*iteZom)->IsHitBullet((*iteBullet)->m_x, (*iteBullet)->m_y))
						{ //是否撞击到豆	
							mciSendString("play ./res/豌豆打击僵尸.mp3", 0, 0, 0);
							delete (*iteBullet);  //删除豆
							(*iteBullet) = nullptr;
							//删除节点
							iteBullet = m_bulletBox.m_lstbullet.erase(iteBullet);
							//掉血
							(*iteZom)->m_blood -= DEF_BULLET_HURT;
							if ((*iteZom)->m_blood <= 0)
							{
								m_zomBox.m_lstBoomZom.push_back(*iteZom);  //添加到爆炸链表中
								iteZom = m_zomBox.m_lstZom.erase(iteZom);
								isBoom = true;
								m_nScore += 3;
								break;
							}
							continue;
						}
						iteBullet++;
					}
				}


				if (iteZom != m_zomBox.m_lstZom.end()) {
					// 7. 判断是否撞击刺
					list<CCactusshell*>::iterator iteshell = m_shellBox.m_lstCactusshell.begin();
					while (iteshell != m_shellBox.m_lstCactusshell.end())
					{
						if ((*iteZom)->IsHitBullet((*iteshell)->m_x, (*iteshell)->m_y))
						{ //是否撞击到豆
							mciSendString("play ./res/豌豆打击僵尸.mp3", 0, 0, 0);
							delete (*iteshell);  //删除豆
							(*iteshell) = nullptr;
							//删除节点
							iteshell = m_shellBox.m_lstCactusshell.erase(iteshell);
							//掉血
							(*iteZom)->m_blood -= DEF_BULLET_HURT;
							if ((*iteZom)->m_blood <= 0)
							{
								m_zomBox.m_lstBoomZom.push_back(*iteZom);  //添加到爆炸链表中
								iteZom = m_zomBox.m_lstZom.erase(iteZom);
								isBoom1 = true;
								m_nScore += 3;
								break;
							}
							continue;
						}
						iteshell++;
					}
				}
				//8.是否撞击小车
				if (iteZom != m_zomBox.m_lstZom.end()) {

					list<CDolly*>::iterator itedolly = m_dollyBox.m_lstDolly.begin();
					while (itedolly != m_dollyBox.m_lstDolly.end())
					{
						if ((*iteZom)->IsHitDolly((*itedolly)->m_x, (*itedolly)->m_y))
						{ //是否撞击到小车

							(*itedolly)->ishit = true;
							mciSendString("play ./res/小车车.mp3", 0, 0, 0);
							//掉血
							(*iteZom)->m_blood -= DEF_DOLLY_HURT;
							if ((*iteZom)->m_blood <= 0)
							{
								m_zomBox.m_lstBoomZom.push_back(*iteZom);  //添加到爆炸链表中
								iteZom = m_zomBox.m_lstZom.erase(iteZom);
								isBoom1 = true;
								m_nScore += 3;
								break;
							}
							continue;
						}
						itedolly++;
					}

				}

				if (iteZom != m_zomBox.m_lstZom.end()) {
					if ((*iteZom)->m_x <= 0) {
						GameOver();//游戏结束
					}
				}
			}
			if ((!isBoom)&&(!isBoom1)&& (!isBoom2))
				iteZom++;	
		}
	}
	break;

	case TIMER_GANGKAISHI_SHOWID_ID://豌豆射手
	{
		for (int i = 0; i < k; i++) {
			array[i].m_playershowId--;
			if (array[i].m_playershowId < 0)
			{
				array[i].m_playershowId = 11;
			}
		}
	}
	break;
	case TIMER_SUNFLOWER_SHOWID_ID://向日葵
	{
		for (int i = 0; i < sunfNum; i++) {
			arraysunf[i].m_SunflowershowId--;
			if (arraysunf[i].m_SunflowershowId < 0)
			{
				arraysunf[i].m_SunflowershowId = 17;
			}
		}
	}
	break;

	//仙人掌
	case TIMER_CACTUS_SHOWID_ID:
	{
		for (int i = 0; i < shellNum; i++) {
			arraycactus[i].m_CactusshowId--;
			if (arraycactus[i].m_CactusshowId < 0)
			{
				arraycactus[i].m_CactusshowId = 9;
			}
		}
	}
	break;

	//坚果墙
	case TIMER_PLANTS_STAXIS_ID:
	{
		for (int i = 0; i < nutNum; i++) {
			arraynut[i].m_NutshowId--;
			if (arraynut[i].m_NutshowId < 0)
			{
				arraynut[i].m_NutshowId = 4;
			}
		}
	}
	break;

	case TIMER_START_SHOWID_ID://僵尸
	{
		list<CZombie*>::iterator iteZom = m_zomBox.m_lstZom.begin();
		while (iteZom != m_zomBox.m_lstZom.end()) 
		{
			(*iteZom)->m_showId--;
			if ((*iteZom)->m_showId < 0) 
			{
				(*iteZom)->m_showId = 7;
			}
			iteZom++;
		}
	}
	break;
	case TIMER_CHANGE_SHOWID_ID://删除僵尸
	{
			list<CZombie*>::iterator iteBoom = m_zomBox.m_lstBoomZom.begin();
			while (iteBoom != m_zomBox.m_lstBoomZom.end())
			{
				(*iteBoom)->m_dieshowId--;
				if ((*iteBoom)->m_dieshowId < 0)
				{
					mciSendString("play ./res/groan4.mp3", 0, 0, 0);
					
					delete (*iteBoom);
					(*iteBoom) = nullptr;
					iteBoom = m_zomBox.m_lstBoomZom.erase(iteBoom);
					continue;
					
				}
				iteBoom++;
		}
	}
	break;
	}
}
//键盘按下消息处理
void CPlantsVsZombiesApp::ON_WM_KEYDOWN(WPARAM w)//方向w
{
}
//鼠标按下消息处理
 void  CPlantsVsZombiesApp::ON_WM_LBUTTONDOWN(POINT po)//鼠标按下
{
	 //收集落下来的阳光
	 if (m_sunBox.IsHitSun(po.x, po.y ))
	{
		int m_x;
		int m_y;
		 list<CSun*>::iterator iteSun1 = m_sunBox.m_lstSun.begin();
		 while (iteSun1 != m_sunBox.m_lstSun.end())
		 {
			 if (iteSun1 != m_sunBox.m_lstSun.end())
			 {
				 m_x = (*iteSun1)->m_x;
				 m_y = (*iteSun1)->m_y;
				 if (po.x<m_x + IMG_SUN_WIDHT && po.x>m_x && po.y<m_y + IMG_SUN_HEIGHT && po.y>m_y) {

					 mciSendString("play ./res/阳光.mp3", 0, 0, 0);
					 delete (*iteSun1);
					 (*iteSun1) = nullptr;
					 iteSun1 = m_sunBox.m_lstSun.erase(iteSun1);
					 m_sunScore += 50;
					 break;
				 }
				 else {
					 iteSun1++;
				 }
			 }
			 
		 }
		 //收集太阳花产生的阳光
		 list<CSun*>::iterator iteSun = m_sunBox.m_lstSun1.begin();
		 while (iteSun != m_sunBox.m_lstSun1.end())
		 {
			 if (iteSun != m_sunBox.m_lstSun1.end())
			 {
				 m_x = (*iteSun)->n_x;
				 m_y = (*iteSun)->n_y;
				 if (po.x<m_x + IMG_SUN_WIDHT && po.x>m_x && po.y<m_y + IMG_SUN_HEIGHT && po.y>m_y) {

					 mciSendString("play ./res/阳光.mp3", 0, 0, 0);
					 delete (*iteSun);
					 (*iteSun) = nullptr;
					 iteSun = m_sunBox.m_lstSun1.erase(iteSun);
					 m_sunScore += 50;
					 break;
				 }
				 else {
					 iteSun++;
				 }
			 }

		 }
	 }
	 //种樱桃炸弹
	 if (po.x > 528 && po.x <= 578 && po.y >= 10 && po.y <= 79 && m_sunScore >= 150) {
		 mciSendString("play ./res/点击卡片.mp3", 0, 0, 0);

		 isdowncherry = true;
		 TCherry = new CCherry;
		 arraycherry[cherryNum] = *TCherry;
		 arraycherry[cherryNum].InitCherry(po.x, po.y);

		 m_sunScore -= 150;
	 }


	 //种坚果墙
	 if (po.x > 478 && po.x <= 528 && po.y >= 10 && po.y <= 79 && m_sunScore >= 50) {
		 mciSendString("play ./res/点击卡片.mp3", 0, 0, 0);

		 isdownnut = true;
		 TNut = new CNut;
		 arraynut[nutNum] = *TNut;
		 arraynut[nutNum].InitNut(po.x, po.y);

		 m_sunScore -= 50;
	 }

	 //种仙人掌
	 if (po.x > 578 && po.x <= 628 && po.y >= 10 && po.y <= 79 && m_sunScore >= 150) {
		 mciSendString("play ./res/点击卡片.mp3", 0, 0, 0);

		 isdowncactus = true;
		 TCact = new CCactus;
		 arraycactus[shellNum] = *TCact;
		 arraycactus[shellNum].InitCactus(po.x, po.y);

		 m_sunScore -= 150;
	 }

	 //种向日葵
	 if (po.x > 428 && po.x <= 478 && po.y >= 10 && po.y <= 79 && m_sunScore >= 50) {
		 mciSendString("play ./res/点击卡片.mp3", 0, 0, 0);
		 
		 isdownflower = true;
		 TSunF = new CSunflower; 
		 arraysunf[sunfNum] = *TSunF;
		 arraysunf[sunfNum].InitSunflower(po.x, po.y);
		 
		 m_sunScore -= 50;
	 }
	  m_cardBox.IsHitCardBackGround(po.x, po.y);
	  //种豌豆
	  if (po.x>=380 && po.y>=10 && po.x<=428&&po.y<=79&&m_sunScore>=100) {
		  mciSendString("play ./res/点击卡片.mp3", 0, 0, 0);

		  isdownshooter = true;
		  temporary = new CPeashooter;
		  array[k] = *temporary;
		  array[k].InitPlant(po.x, po.y);

		  m_sunScore -=100;
	  }
	  //铲子
	  if (po.x >= 828 && po.y >= 0 && po.x <= 918 && po.y <= 72 ) {

		 // isdownshovel = true;
		 // m_shovel.InitShovel(po.x, po.y);
		  m_shovel.ishit = true;

	  }

};
 void  CPlantsVsZombiesApp::ON_WM_LBUTTONUP(POINT po) {//鼠标弹起

	 //move 将植物放置在预定位置
	 
	 if (isdownshooter)
	 {
		 if (po.x < 980 && po.x > 250 && po.y > 70 && po.y<570)
		 {
			 int i = (po.x - 250) / 83;
			 int j = (po.y - 80) / 99;
			 if (!m_arrBack[i][j]) {
				 isdownshooter = false;
				 temporary = nullptr;
				 array[k].isdowncard = false;
				 array[k].MovePlant((i) * 83 + 251, (j) * 99 + 69);//种植植物的位置
				 k++;
				 m_arrBack[i][j] = 1;
				 mciSendString("play ./res/种植.mp3", 0, 0, 0);
			 }
		 }
	 }
	 if (isdownflower) {
		 if (po.x < 980 && po.x > 250 && po.y > 70 && po.y < 570)
		 {
			 int i = (po.x - 250) / 83;
			 int j = (po.y - 80) / 99;
			 if (!m_arrBack[i][j]) {
				 isdownflower = false;
				 TSunF = nullptr;
				 arraysunf[sunfNum].isdowncard = false;
				 arraysunf[sunfNum].MoveSunflower((i) * 83 + 251, (j) * 99 + 69);
				 sunfNum++;
				 m_arrBack[i][j] = 1;
				 mciSendString("play ./res/种植.mp3", 0, 0, 0);
			 }
		 }
	 }
	 //种下
	 if (isdowncactus) 
	 {
		 if (po.x < 980 && po.x > 250 && po.y > 70 && po.y < 570)
		 {
			 int i = (po.x - 250) / 83;
			 int j = (po.y - 80) / 99;
			 if (!m_arrBack[i][j]) {
				 isdowncactus = false;
				 TCact = nullptr;
				 arraycactus[shellNum].isdowncard = false;
				 arraycactus[shellNum].MoveCactus((i) * 83 + 251, (j) * 99 + 69);
				 shellNum++;
				 m_arrBack[i][j] = 1;
				 
				 mciSendString("play ./res/种植.mp3", 0, 0, 0);
			 }
		 }
	 }

	 if (isdownnut)
	 {
		 if (po.x < 980 && po.x > 250 && po.y > 70 && po.y < 570)
		 {
			 int i = (po.x - 250) / 83;
			 int j = (po.y - 80) / 99;
			 if (!m_arrBack[i][j]) {
				 isdownnut = false;
				 TNut = nullptr;
				 arraynut[nutNum].isdowncard = false;
				 arraynut[nutNum].MoveNut((i) * 83 + 251, (j) * 99 + 69);
				 nutNum++;
				 m_arrBack[i][j] = 1;

				 mciSendString("play ./res/种植.mp3", 0, 0, 0);
			 }
		 }
	 }
	 if (isdowncherry)
	 {
		 if (po.x < 980 && po.x > 250 && po.y > 70 && po.y < 570)
		 {
			 int i = (po.x - 250) / 83;
			 int j = (po.y - 80) / 99;
			 if (!m_arrBack[i][j]) {
				 isdowncherry = false;
				 TCherry = nullptr;
				 arraycherry[cherryNum].isdowncard = false;
				 arraycherry[cherryNum].MoveCherry((i) * 83 + 251, (j) * 99 + 69);
				 cherryNum++;
				 m_arrBack[i][j] = 1;

				 mciSendString("play ./res/种植.mp3", 0, 0, 0);
			 }
		 }
	 }
	 if (m_shovel.ishit)
	 {
		 if (po.x < 980 && po.x > 250 && po.y > 70 && po.y < 570)
		 {
			 for(int i=0;i<k;i++)
				 if (m_shovel.IsHitPlant(array[i].m_x, array[i].m_y)) {

					 int length = (array[i].m_x - 251) / 83;
					 int width = (array[i].m_y - 69) / 99;
					 m_arrBack[length][width] = 0;
					 for (int j = i; j < k; j++) {
						 array[j] = array[j + 1];
					 }
					 
					 k--;
			 }
			 for (int i = 0; i < sunfNum; i++)
				 if (m_shovel.IsHitPlant(arraysunf[i].m_x, arraysunf[i].m_y)) {
					 int length = (arraysunf[i].m_x - 251) / 83;
					 int width = (arraysunf[i].m_y - 69) / 99;
					 m_arrBack[length][width] = 0;
					 for (int j = i; j < sunfNum; j++) {
						 arraysunf[j] = arraysunf[j + 1];
					 }
					 
					 sunfNum--;
				 }
			 for (int i = 0; i < nutNum; i++)
				 if (m_shovel.IsHitPlant(arraynut[i].m_x, arraynut[i].m_y)) {
					 int length = (arraynut[i].m_x - 251) / 83;
					 int width = (arraynut[i].m_y - 69) / 99;
					 m_arrBack[length][width] = 0;
					 for (int j = i; j < nutNum; j++) {
						 arraysunf[j] = arraysunf[j + 1];
					 }
					 
					 nutNum--;
				 }
			 for (int i = 0; i < shellNum; i++)
				 if (m_shovel.IsHitPlant(arraycactus[i].m_x, arraycactus[i].m_y)) {
					 int length = (arraycactus[i].m_x - 251) / 83;
					 int width = (arraycactus[i].m_y - 69) / 99;
					 m_arrBack[length][width] = 0;
					 for (int j = i; j < shellNum; j++) {
						 arraycactus[j] = arraycactus[j + 1];
					 }
					 
					 shellNum--;
				 }
			 m_shovel.ishit = false;
			 m_shovel.InitShovel(828, 0);
		 }
	 }
		 
 }
 void  CPlantsVsZombiesApp::ON_WM_MOUSEMOVE(POINT po) {//鼠标移动
	 if (isdownshooter) {
		 if (po.x > 980 || po.x < 250 || po.y < 70 || po.y>570)
		 {
			 OnBnClickedButton1();
		 }
		 else {
			 array[k].MovePlant(po.x - IMG_PEASHOOTER_WIDHT / 2, po.y - IMG_PEASHOOTER_HEIGHT / 2);
		 } 
	 }
	 if (isdownflower)
	 {
		 if (po.x > 980 || po.x < 250 || po.y < 70 || po.y>570)
		 {
			 OnBnClickedButton1();
		 }else
		 arraysunf[sunfNum].MoveSunflower(po.x - IMG_SUNFLOWER_WIDHT / 2, po.y - IMG_SUNFLOWER_HEIGHT / 2);
	 }
	 //
	 if (isdowncactus)
	 {
		 if (po.x > 980 || po.x < 250 || po.y < 70 || po.y>570)
		 {
			 OnBnClickedButton1();
		 }else
		 arraycactus[shellNum].MoveCactus(po.x - IMG_CACTUS_WIDHT / 2, po.y - IMG_CACTUS_HEIGHT / 2);
	 }
	 if (isdownnut)
	 {
		 if (po.x > 980 || po.x < 250 || po.y < 70 || po.y>570)
		 {
			 OnBnClickedButton1();
		 }
		 else
			 arraynut[nutNum].MoveNut(po.x - IMG_NUT_WIDHT / 2, po.y - IMG_NUT_HEIGHT / 2);
	 }
	 if (isdowncherry)
	 {
		 if (po.x > 980 || po.x < 250 || po.y < 70 || po.y>570)
		 {
			 OnBnClickedButton1();
		 }
		 else
			 arraycherry[cherryNum].MoveCherry(po.x - IMG_CHERRY_WIDHT / 2, po.y - IMG_CHERRY_HEIGHT / 2);
	 }
	 if (m_shovel.ishit)
	 {
		 /*if (po.x > 980 || po.x < 250 || po.y < 70 || po.y>570)
		 {
			 OnBnClickedButton1();
		 }
		 else*/
			 m_shovel.MoveShovel(po.x - IMG_SHOVEL_WIDHT / 2, po.y - IMG_SHOVEL_HEIGHT / 2);
	 }
 }


 void CPlantsVsZombiesApp::ShowAllPeashooter() {
	 
	 for (int i = 0; i <= k; i++) {
		 array[i].ShowPlant();
		// array[k].SendBullet();
	 }
 };

void CPlantsVsZombiesApp::ShowAllSunflower() {

	 for (int i = 0; i <= sunfNum; i++) {
		 arraysunf[i].ShowSunflower();
	 }
 };

void CPlantsVsZombiesApp::ShowAllCactus() {

	for (int i = 0; i <= shellNum; i++) {
		arraycactus[i].ShowCactus();
	}
};


void CPlantsVsZombiesApp::ShowAllNut() {
	for (int i = 0; i <= nutNum; i++) {
		arraynut[i].ShowNut();
	}
	
}
void CPlantsVsZombiesApp::ShowAllCherry() {
	for (int i = 0; i <= cherryNum; i++) {
		arraycherry[i].ShowCherry();
		//m_cherry[i].ShowBoomCherry();
	}

}

void CPlantsVsZombiesApp::ShowAllBoomCherry() {
	for (int i = 0; i <= boomframe; i++) {
		m_cherry[i].ShowBoomCherry();
	}

}

void CPlantsVsZombiesApp::GameOver()
{
	::mciSendString("play ./res/fail.mp3", 0, 0, 0);
	//停止所有定时器
	::KillTimer(m_hWnd, TIMER_PEASHOOTER_MOVE_ID);
	::KillTimer(m_hWnd, TIMER_BULLET_MOVE_ID);
	::KillTimer(m_hWnd, TIMER_BULLET_SEND_ID);
	::KillTimer(m_hWnd, TIMER_ORDINARYZOMBIE_MOVE_ID);
	::KillTimer(m_hWnd, TIMER_ORDINARYZOMBIE_CREATE_ID);
	::KillTimer(m_hWnd, TIMER_BUCKTEHEADZOMBIE_CREATE_ID);
	::KillTimer(m_hWnd, TIMER_RUGBYZOMBIE_CREATE_ID);
	::KillTimer(m_hWnd, TIMER_FLAGZOMBIE_CREATE_ID);
	
	::KillTimer(m_hWnd, TIMER_IS_HIT_ID);
	::KillTimer(m_hWnd, TIMER_CHANGE_SHOWID_ID);
	::KillTimer(m_hWnd, TIMER_SUN_MOVE_ID);
	::KillTimer(m_hWnd, TIMER_SUN_CREATE_ID);
	::KillTimer(m_hWnd, TIMER_CARDBACKGROUND_CREATE_ID);
	::KillTimer(m_hWnd, TIMER_CONEHEADZOMBIE_CREATE_ID);
	::KillTimer(m_hWnd, TIMER_START_SHOWID_ID);
	::KillTimer(m_hWnd, TIMER_GANGKAISHI_SHOWID_ID);
	::KillTimer(m_hWnd, TIMER_SUNFLOWER_SHOWID_ID);
	::KillTimer(m_hWnd, TIMER_SUNFLOWER_CREATE_ID);
	::KillTimer(m_hWnd, TIMER_SHELL_CREATE_ID);
	::KillTimer(m_hWnd, TIMER_SHELL_MOVE_ID);
	::KillTimer(m_hWnd, TIMER_CACTUS_SHOWID_ID);
	::KillTimer(m_hWnd, TIMER_DOLLY_MOVE_ID);
	::KillTimer(m_hWnd, TIMER_CHERRY_BOOM_ID);
	::KillTimer(m_hWnd, TIMER_NUT_CREATE_ID);
	::KillTimer(m_hWnd, TIMER_CHERRY_BOOMFRAME_ID);
	::KillTimer(m_hWnd, TIMER_SHOVEL_SHOW_ID);
	::MessageBox(m_hWnd, "GameOver", "游戏结束", MB_OK);
	
	//程序自动退出，发送退出WM_CLOSE的消息
	::PostMessage(m_hWnd, WM_CLOSE, 0, 0);
};                                                                                                                                                                                                                                    
void CPlantsVsZombiesApp::ShowScore()
{
	::putimage(1294, 0, &m_scoreImg);
	char score[5] = { 0 };
	itoa(m_nScore, score, 10);
	RECT rect = { 0,0,1385,72 };
	settextcolor(RGB(255, 0, 0));
	settextstyle(40, 0, _T("黑体"));
	::drawtext(score, &rect, DT_RIGHT);
}
void CPlantsVsZombiesApp::ShowSunScore()
{
	::putimage(312,65, &m_sunscoreImg);
	char score[5] = { 0 };
	itoa(m_sunScore, score, 10);
	RECT rect = { 0,62,367,85 };
	settextcolor(RGB(255, 255, 0));
	settextstyle(24, 0, _T("黑体"));
	::drawtext(score, &rect, DT_RIGHT);
}

void CPlantsVsZombiesApp::OnBnClickedButton1()
{
	//::putimage(312, 365, &m_sunscoreImg);
	//setbkmode(TRANSPARENT);
	char ti[] = "此处不能种植物！";
	RECT rects = { 268, 175, 238, 275 };
	settextcolor(WHITE);
	settextstyle(40, 0, _T("隶书"));
	//drawtext("此处不能种植物！", &rects, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(ti, &rects, DT_CENTER);
}
