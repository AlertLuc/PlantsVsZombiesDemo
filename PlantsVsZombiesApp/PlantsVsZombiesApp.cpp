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
	//�����������
	srand((unsigned int)time(NULL));
	//��ʼ������
	m_back.InitPlantsVsZombiesBackGround();
	//��ʼ���̵걳��
	m_shopback.InitShopBackGround();

	m_cardBox.ShowAllCardBackGround();
	//��ʼ�����ж�
	m_bulletBox.ShowAllBullet();

	//��ʼ�����ڵ�
	m_shellBox.ShowAllCactusshell();

	//��ʼ��С��
	m_dollyBox.InitAllDolly(175,91);

	m_shopback.InitShovelBackGround();

	//
	m_shovel.InitShovel(828, 0);

	//���������ͼ
	::loadimage(&m_scoreImg, PATH_PIC(cardboard.png));
	::loadimage(&m_sunscoreImg, PATH_PIC(sun.png));
	//�趨��ʱ��
	//ֲ���ƶ�
	::SetTimer(m_hWnd, TIMER_PEASHOOTER_MOVE_ID, TIMER_PEASHOOTER_MOVE_INTERVAL, nullptr);//id�����
	//���ƶ�
	::SetTimer(m_hWnd,TIMER_BULLET_MOVE_ID,TIMER_BULLET_MOVE_INTERVAL,nullptr);
	//���ƶ�
	::SetTimer(m_hWnd, TIMER_BULLET_MOVE_ID, TIMER_BULLET_MOVE_INTERVAL, nullptr);
	//����ʱ����
	::SetTimer(m_hWnd, TIMER_BULLET_SEND_ID, TIMER_BULLET_SEND_INTERVAL, nullptr);
	//̫���ƶ�
	::SetTimer(m_hWnd, TIMER_SUN_MOVE_ID, TIMER_SUN_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_SUN_CREATE_ID, TIMER_SUN_CREATE_INTERVAL, nullptr);
	::SetTimer(m_hWnd, TIMER_CARDBACKGROUND_CREATE_ID, TIMER_CARDBACKGROUND_CREATE_INTERVAL, nullptr);
	//��ͨ��ʬ��ʱ�ƶ�
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
	//���տ�Ť��
	::SetTimer(m_hWnd, TIMER_SUNFLOWER_SHOWID_ID, TIMER_SUNFLOWER_SHOWID_INTERVAL, nullptr);
	//���տ�����̫��
	::SetTimer(m_hWnd, TIMER_SUNFLOWER_CREATE_ID, TIMER_SUNFLOWER_CREATE_INTERVAL, nullptr);
	//
	::SetTimer(m_hWnd, TIMER_SHELL_CREATE_ID, TIMER_SHELL_CREATE_INTERVAL, nullptr);
	//
	::SetTimer(m_hWnd, TIMER_SHELL_MOVE_ID, TIMER_SHELL_MOVE_INTERVAL, nullptr);
	//
	::SetTimer(m_hWnd, TIMER_CACTUS_SHOWID_ID, TIMER_CACTUS_SHOWID_INTERVAL, nullptr);

	::SetTimer(m_hWnd, TIMER_DOLLY_MOVE_ID, TIMER_DOLLY_MOVE_INTERVAL, nullptr);
	//ӣ�ұ�ը
	::SetTimer(m_hWnd, TIMER_CHERRY_BOOM_ID, TIMER_CHERRY_BOOM_INTERVAL, nullptr);

	::SetTimer(m_hWnd, TIMER_CHERRY_BOOMFRAME_ID, TIMER_CHERRY_BOOMFRAME_INTERVAL, nullptr);

	::SetTimer(m_hWnd, TIMER_NUT_CREATE_ID, TIMER_SUNFLOWER_CREATE_INTERVAL, nullptr);

	::SetTimer(m_hWnd, TIMER_SHOVEL_SHOW_ID, TIMER_SHOVEL_SHOW_INTERVAL, nullptr);
}

void CPlantsVsZombiesApp::PaintGame()//��ʾ
{
	//��ʾ����ͼƬ
	m_back.showPlantsVsZombiesBackGround();
	//��ʾ�̵�ͼƬ
	m_shopback.showShopBackGround();
    ShowSunScore();
	//��ʾ��ƬͼƬ
	m_cardBox.ShowAllCardBackGround();

	//��ʾ��
	m_bulletBox.ShowAllBullet();

	//��ʾС��
	m_dollyBox.ShowAllDolly();

	m_shopback.showShovelBackGround();
	
	//��ʾ����
	m_shovel.ShowShovel();


	//��ʾ�ڵ�
	m_shellBox.ShowAllCactusshell();
	
	
	//��ʾ̫��
	m_sunBox.ShowAllSun();
	m_sunBox.ShowAllCreatSun();
	//��ʾ��ʬ
	m_zomBox.ShowAllZombie();
	
	//��ʾ�򱬵Ľ�ʬ
	m_zomBox.ShowAllBoomZombie();
	
	//��ʾ����
	ShowScore();
	//��ʾ�㶹����
	ShowAllPeashooter();
	
	//��ʾ���տ�
	ShowAllSunflower();
	
	//��ʾ������
	ShowAllCactus();

	//��ʾ���ǽ
	ShowAllNut();

	//��ʾӣ��
	ShowAllCherry();

	//��ʾ��ըӣ��
	ShowAllBoomCherry();
	
}
void CPlantsVsZombiesApp::CloseGame()//�ر�
{
}
#define CREATE_ZOM(ZOM_CLASS)\
	CZombie* pZom = new ZOM_CLASS;\
	pZom-> InitZombie();\
	m_zomBox.m_lstZom.push_back(pZom);
//��ʱ����Ϣ�Ĵ�������������д��
void CPlantsVsZombiesApp::ON_WM_TIMER(WPARAM w, LPARAM l)
{
	switch (w)
	{
		//̫�����ƶ�
	case TIMER_SUN_MOVE_ID:
	{
		m_sunBox.MoveAllSun();
		//m_sunBox.ShowAllCreatSun();
	}
	break;
	//��������
	case TIMER_SUN_CREATE_ID:
	{
		CSun* pSun = new CSun;
		pSun->InitSun(0,0);
		m_sunBox.m_lstSun.push_back(pSun);
	}
	break;
	//���տ������������
	case TIMER_SUNFLOWER_CREATE_ID: {
		/*m_sunScore += 25 * sunfNum;*/
		for (int i = 0; i < sunfNum; i++) {
			if (!(arraysunf[i].isdowncard))
			{
				//�㶹����ȥ���÷��䶹
				CSun* pSun = arraysunf[i].CreatSun();
				//���ŵ�������
				m_sunBox.m_lstSun1.push_back(pSun);
			}
		}
	}
	 break;
				  //��Ƭ����
	case TIMER_CARDBACKGROUND_CREATE_ID:
	{
		CCardBackGround* pCard = new CCardBackGround;
		pCard->InitCardBackGround();
		m_cardBox.m_lstCardBackGround.push_back(pCard);
	}
	break;
	//��ʾ����
	case TIMER_SHOVEL_SHOW_ID: {

		m_shovel.ShowShovel();
	}
	break;
	//���ƶ��Ķ�ʱ��
	case TIMER_BULLET_MOVE_ID:
	{
		m_bulletBox.MoveAllBullet(TIMER_BULLET_MOVE_STEP);
	}
	break;

	//���ڵ��ƶ���ʱ��

	case TIMER_SHELL_MOVE_ID:
	{
		m_shellBox.MoveAllCactusshell(TIMER_SHELL_MOVE_STEP);
	}
	break;

	//ӣ�ұ�ը��ʱ��
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

	//ӣ�ұ�ը�������ٶ�ʱ��
	case TIMER_CHERRY_BOOMFRAME_ID:
	{
		while(boomframe)
		for (int i = 0; i <= boomframe; i++) {
			m_cherry[i] = m_cherry[i + 1];
			boomframe--;
		}
	}
	break;


	//���ڵ����䶨ʱ��
	case TIMER_SHELL_CREATE_ID:
	{
		list<CZombie*>::iterator ite = m_zomBox.m_lstZom.begin();
		while (ite != m_zomBox.m_lstZom.end())
		{
			if (*ite) {
				for (int i = 0; i < shellNum; i++) {
					if (!(arraycactus[i].isdowncard)&&((*ite)->m_y+69== arraycactus[i].m_y))
					{
						//ֲ�����²�����һ����ֲ��
						CCactusshell* pshells = arraycactus[i].SendCactusshell();
						//���ŵ�������
						m_shellBox.m_lstCactusshell.push_back(pshells);
					}
				}
			}
			ite++;
		}
	}
	break;
	//����С����ǰ�ƶ�

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
				delete (*itedolly);  //ɾ��С��
				(*itedolly) = nullptr;
				//ɾ���ڵ�
				itedolly = m_dollyBox.m_lstDolly.erase(itedolly);
				Isboomdolly = true;
			}
			if(!Isboomdolly)
			itedolly++;
		}
	}
	break;

	//������Ķ�ʱ��
	case TIMER_BULLET_SEND_ID:  
	{
		list<CZombie*>::iterator ite = m_zomBox.m_lstZom.begin();
		while (ite != m_zomBox.m_lstZom.end())
		{
			if (*ite) {
				for (int i = 0; i < k; i++) {
					if (!(array[i].isdowncard) && ((*ite)->m_y + 69 == array[i].m_y))
					{
						//ֲ�����²�����һ����ֲ��
						CBullet* pBullets = array[i].SendBullet();
						//���ڵ��ŵ��ڵ�����
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
		//m_zomBox.MoveAllZombie();//��ʬ�ƶ�
		list<CZombie*>::iterator ite = m_zomBox.m_lstZom.begin();
		while (ite != m_zomBox.m_lstZom.end())
		{
			if (*ite)
			{
				if (ite == m_zomBox.m_lstZom.begin()&& InitFristZom) {//��һ����ʬ���ֲ���coming����
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
	case TIMER_IS_HIT_ID:   //��ʱ����Ƿ�ײ��(��ʬ-��������ʬ-���㶹���֣�
	{
		list<CZombie*>::iterator iteZom = m_zomBox.m_lstZom.begin();
		while (iteZom != m_zomBox.m_lstZom.end()) 
		{
			bool isBoom = false;
			bool isBoom1 = false;
			bool isBoom2 = false;
			if ((*iteZom)) 
			{
				//1. �ж��Ƿ�ײ���㶹����
				for (int i = 0; i < k; i++) {
					if ((*iteZom)->IsHitPlant(array[i].m_x,array[i].m_y) && !array[i].isdowncard )
					{	//ײ���㶹������ֲ������ʱ
						if (array == NULL  || k < 0) {
								

						}
						else {//ɾ���㶹����
							if (array[i].m_plantblood > 0) {
								(*iteZom)->isHitePlants = true;
								m_zomBox.m_lstStopZom.push_back(*iteZom);

								mciSendString("play ./res/���ڳ�ֲ��.mp3", 0, 0, 0);
								array[i].m_plantblood--;
							}
							else if (array[i].m_plantblood<=0) {//ֲ��Ѫ����Ϊ0
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
							mciSendString("play ./res/�Ե�ֲ��.mp3", 0, 0, 0);
							}
							
						}
					}
				}
				//2.����Ƿ�ײ�����տ�
				for (int i = 0; i < sunfNum; i++) {
					if ((*iteZom)->IsHitPlant(arraysunf[i].m_x, arraysunf[i].m_y) && !arraysunf[i].isdowncard )
					{	//ײ���㶹������ֲ������ʱ
						if (arraysunf == NULL  || sunfNum < 0) {


						}
						else {//ɾ�����տ�
							if (arraysunf[i].m_Sunflowerblood > 0) {
								(*iteZom)->isHitePlants = true;
								m_zomBox.m_lstStopZom.push_back(*iteZom);

								mciSendString("play ./res/���ڳ�ֲ��.mp3", 0, 0, 0);
								arraysunf[i].m_Sunflowerblood--;
							}
							else if (arraysunf[i].m_Sunflowerblood <= 0) {//ֲ��Ѫ����Ϊ0
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
								mciSendString("play ./res/�Ե�ֲ��.mp3", 0, 0, 0);
							}

						}
					}
				}
				//3.����Ƿ�ײ��������
				for (int i = 0; i < shellNum; i++) {
					if ((*iteZom)->IsHitPlant(arraycactus[i].m_x, arraycactus[i].m_y) && !arraycactus[i].isdowncard)
					{	//ײ���㶹������ֲ������ʱ
						if (arraycactus == NULL  || shellNum < 0) {


						}
						else {//ɾ��������
							if (arraycactus[i].m_Cactusblood > 0) {
								(*iteZom)->isHitePlants = true;
								m_zomBox.m_lstStopZom.push_back(*iteZom);

								mciSendString("play ./res/���ڳ�ֲ��.mp3", 0, 0, 0);
								arraycactus[i].m_Cactusblood--;
							}
							else if (arraycactus[i].m_Cactusblood <= 0) {//ֲ��Ѫ����Ϊ0
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
								mciSendString("play ./res/�Ե�ֲ��.mp3", 0, 0, 0);
							}

						}
					}
				}
				//4.����Ƿ�ײ�����ǽ
				for (int i = 0; i < nutNum; i++) {
					if ((*iteZom)->IsHitPlant(arraynut[i].m_x, arraynut[i].m_y) && !arraynut[i].isdowncard)
					{	//ײ���㶹������ֲ������ʱ
						if (arraynut == NULL || nutNum < 0) {


						}
						else {//ɾ��������
							if (arraynut[i].m_Nutblood > 0) {
								(*iteZom)->isHitePlants = true;
								m_zomBox.m_lstStopZom.push_back(*iteZom);

								mciSendString("play ./res/���ڳ�ֲ��.mp3", 0, 0, 0);
								arraynut[i].m_Nutblood--;
							}
							else if (arraynut[i].m_Nutblood <= 0) {//ֲ��Ѫ����Ϊ0
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
								mciSendString("play ./res/�Ե�ֲ��.mp3", 0, 0, 0);
							}
						}
					}
				}
				//5.����Ƿ�ײ��ӣ��ը��
				for (int i = 0; i < cherryNum; i++) {
					if ((*iteZom)->IsHitCherry(arraycherry[i].m_x, arraycherry[i].m_y) && !arraycherry[i].isdowncard )
					{	//ײ���㶹������ֲ������ʱ
						if (arraycherry == NULL || cherryNum < 0) {


						}
						else {//ɾ��������
							if ((*iteZom)->IsHitPlant(arraycherry[i].m_x, arraycherry[i].m_y))
							{
								mciSendString("play ./res/���ڳ�ֲ��.mp3", 0, 0, 0);
								//arraycherry[i].m_Cherryblood--;
							}
							(*iteZom)->m_blood -= DEF_CHERRY_HURT;
							if ((*iteZom)->m_blood <= 0)
							{
								m_zomBox.m_lstBoomZom.push_back(*iteZom);  //��ӵ���ը������
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
					// 6. �ж��Ƿ�ײ����
					list<CBullet*>::iterator iteBullet = m_bulletBox.m_lstbullet.begin();
					while (iteBullet != m_bulletBox.m_lstbullet.end())
					{
						if ((*iteZom)->IsHitBullet((*iteBullet)->m_x, (*iteBullet)->m_y))
						{ //�Ƿ�ײ������	
							mciSendString("play ./res/�㶹�����ʬ.mp3", 0, 0, 0);
							delete (*iteBullet);  //ɾ����
							(*iteBullet) = nullptr;
							//ɾ���ڵ�
							iteBullet = m_bulletBox.m_lstbullet.erase(iteBullet);
							//��Ѫ
							(*iteZom)->m_blood -= DEF_BULLET_HURT;
							if ((*iteZom)->m_blood <= 0)
							{
								m_zomBox.m_lstBoomZom.push_back(*iteZom);  //��ӵ���ը������
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
					// 7. �ж��Ƿ�ײ����
					list<CCactusshell*>::iterator iteshell = m_shellBox.m_lstCactusshell.begin();
					while (iteshell != m_shellBox.m_lstCactusshell.end())
					{
						if ((*iteZom)->IsHitBullet((*iteshell)->m_x, (*iteshell)->m_y))
						{ //�Ƿ�ײ������
							mciSendString("play ./res/�㶹�����ʬ.mp3", 0, 0, 0);
							delete (*iteshell);  //ɾ����
							(*iteshell) = nullptr;
							//ɾ���ڵ�
							iteshell = m_shellBox.m_lstCactusshell.erase(iteshell);
							//��Ѫ
							(*iteZom)->m_blood -= DEF_BULLET_HURT;
							if ((*iteZom)->m_blood <= 0)
							{
								m_zomBox.m_lstBoomZom.push_back(*iteZom);  //��ӵ���ը������
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
				//8.�Ƿ�ײ��С��
				if (iteZom != m_zomBox.m_lstZom.end()) {

					list<CDolly*>::iterator itedolly = m_dollyBox.m_lstDolly.begin();
					while (itedolly != m_dollyBox.m_lstDolly.end())
					{
						if ((*iteZom)->IsHitDolly((*itedolly)->m_x, (*itedolly)->m_y))
						{ //�Ƿ�ײ����С��

							(*itedolly)->ishit = true;
							mciSendString("play ./res/С����.mp3", 0, 0, 0);
							//��Ѫ
							(*iteZom)->m_blood -= DEF_DOLLY_HURT;
							if ((*iteZom)->m_blood <= 0)
							{
								m_zomBox.m_lstBoomZom.push_back(*iteZom);  //��ӵ���ը������
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
						GameOver();//��Ϸ����
					}
				}
			}
			if ((!isBoom)&&(!isBoom1)&& (!isBoom2))
				iteZom++;	
		}
	}
	break;

	case TIMER_GANGKAISHI_SHOWID_ID://�㶹����
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
	case TIMER_SUNFLOWER_SHOWID_ID://���տ�
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

	//������
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

	//���ǽ
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

	case TIMER_START_SHOWID_ID://��ʬ
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
	case TIMER_CHANGE_SHOWID_ID://ɾ����ʬ
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
//���̰�����Ϣ����
void CPlantsVsZombiesApp::ON_WM_KEYDOWN(WPARAM w)//����w
{
}
//��갴����Ϣ����
 void  CPlantsVsZombiesApp::ON_WM_LBUTTONDOWN(POINT po)//��갴��
{
	 //�ռ�������������
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

					 mciSendString("play ./res/����.mp3", 0, 0, 0);
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
		 //�ռ�̫��������������
		 list<CSun*>::iterator iteSun = m_sunBox.m_lstSun1.begin();
		 while (iteSun != m_sunBox.m_lstSun1.end())
		 {
			 if (iteSun != m_sunBox.m_lstSun1.end())
			 {
				 m_x = (*iteSun)->n_x;
				 m_y = (*iteSun)->n_y;
				 if (po.x<m_x + IMG_SUN_WIDHT && po.x>m_x && po.y<m_y + IMG_SUN_HEIGHT && po.y>m_y) {

					 mciSendString("play ./res/����.mp3", 0, 0, 0);
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
	 //��ӣ��ը��
	 if (po.x > 528 && po.x <= 578 && po.y >= 10 && po.y <= 79 && m_sunScore >= 150) {
		 mciSendString("play ./res/�����Ƭ.mp3", 0, 0, 0);

		 isdowncherry = true;
		 TCherry = new CCherry;
		 arraycherry[cherryNum] = *TCherry;
		 arraycherry[cherryNum].InitCherry(po.x, po.y);

		 m_sunScore -= 150;
	 }


	 //�ּ��ǽ
	 if (po.x > 478 && po.x <= 528 && po.y >= 10 && po.y <= 79 && m_sunScore >= 50) {
		 mciSendString("play ./res/�����Ƭ.mp3", 0, 0, 0);

		 isdownnut = true;
		 TNut = new CNut;
		 arraynut[nutNum] = *TNut;
		 arraynut[nutNum].InitNut(po.x, po.y);

		 m_sunScore -= 50;
	 }

	 //��������
	 if (po.x > 578 && po.x <= 628 && po.y >= 10 && po.y <= 79 && m_sunScore >= 150) {
		 mciSendString("play ./res/�����Ƭ.mp3", 0, 0, 0);

		 isdowncactus = true;
		 TCact = new CCactus;
		 arraycactus[shellNum] = *TCact;
		 arraycactus[shellNum].InitCactus(po.x, po.y);

		 m_sunScore -= 150;
	 }

	 //�����տ�
	 if (po.x > 428 && po.x <= 478 && po.y >= 10 && po.y <= 79 && m_sunScore >= 50) {
		 mciSendString("play ./res/�����Ƭ.mp3", 0, 0, 0);
		 
		 isdownflower = true;
		 TSunF = new CSunflower; 
		 arraysunf[sunfNum] = *TSunF;
		 arraysunf[sunfNum].InitSunflower(po.x, po.y);
		 
		 m_sunScore -= 50;
	 }
	  m_cardBox.IsHitCardBackGround(po.x, po.y);
	  //���㶹
	  if (po.x>=380 && po.y>=10 && po.x<=428&&po.y<=79&&m_sunScore>=100) {
		  mciSendString("play ./res/�����Ƭ.mp3", 0, 0, 0);

		  isdownshooter = true;
		  temporary = new CPeashooter;
		  array[k] = *temporary;
		  array[k].InitPlant(po.x, po.y);

		  m_sunScore -=100;
	  }
	  //����
	  if (po.x >= 828 && po.y >= 0 && po.x <= 918 && po.y <= 72 ) {

		 // isdownshovel = true;
		 // m_shovel.InitShovel(po.x, po.y);
		  m_shovel.ishit = true;

	  }

};
 void  CPlantsVsZombiesApp::ON_WM_LBUTTONUP(POINT po) {//��굯��

	 //move ��ֲ�������Ԥ��λ��
	 
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
				 array[k].MovePlant((i) * 83 + 251, (j) * 99 + 69);//��ֲֲ���λ��
				 k++;
				 m_arrBack[i][j] = 1;
				 mciSendString("play ./res/��ֲ.mp3", 0, 0, 0);
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
				 mciSendString("play ./res/��ֲ.mp3", 0, 0, 0);
			 }
		 }
	 }
	 //����
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
				 
				 mciSendString("play ./res/��ֲ.mp3", 0, 0, 0);
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

				 mciSendString("play ./res/��ֲ.mp3", 0, 0, 0);
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

				 mciSendString("play ./res/��ֲ.mp3", 0, 0, 0);
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
 void  CPlantsVsZombiesApp::ON_WM_MOUSEMOVE(POINT po) {//����ƶ�
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
	//ֹͣ���ж�ʱ��
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
	::MessageBox(m_hWnd, "GameOver", "��Ϸ����", MB_OK);
	
	//�����Զ��˳��������˳�WM_CLOSE����Ϣ
	::PostMessage(m_hWnd, WM_CLOSE, 0, 0);
};                                                                                                                                                                                                                                    
void CPlantsVsZombiesApp::ShowScore()
{
	::putimage(1294, 0, &m_scoreImg);
	char score[5] = { 0 };
	itoa(m_nScore, score, 10);
	RECT rect = { 0,0,1385,72 };
	settextcolor(RGB(255, 0, 0));
	settextstyle(40, 0, _T("����"));
	::drawtext(score, &rect, DT_RIGHT);
}
void CPlantsVsZombiesApp::ShowSunScore()
{
	::putimage(312,65, &m_sunscoreImg);
	char score[5] = { 0 };
	itoa(m_sunScore, score, 10);
	RECT rect = { 0,62,367,85 };
	settextcolor(RGB(255, 255, 0));
	settextstyle(24, 0, _T("����"));
	::drawtext(score, &rect, DT_RIGHT);
}

void CPlantsVsZombiesApp::OnBnClickedButton1()
{
	//::putimage(312, 365, &m_sunscoreImg);
	//setbkmode(TRANSPARENT);
	char ti[] = "�˴�������ֲ�";
	RECT rects = { 268, 175, 238, 275 };
	settextcolor(WHITE);
	settextstyle(40, 0, _T("����"));
	//drawtext("�˴�������ֲ�", &rects, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(ti, &rects, DT_CENTER);
}
