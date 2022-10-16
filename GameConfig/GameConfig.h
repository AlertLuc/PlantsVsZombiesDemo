#pragma once
//With the macro optimization
#define PATH_PIC(PIC_NAME) "./res/"#PIC_NAME
//The size of the background image
#define IMG_PLANTSVSZOMBIESBACKGROUND_WIDTH   1400
#define IMG_PLANTSVSZOMBIESBACKGROUND_HEIGHT   600

//The size of the pea shooter
#define IMG_PEASHOOTER_WIDHT      71
#define IMG_PEASHOOTER_HEIGHT     71

//The size of a sunflower
#define IMG_SUNFLOWER_WIDHT       73
#define IMG_SUNFLOWER_HEIGHT       74

//The size of a cactus
#define IMG_CACTUS_WIDHT         72
#define IMG_CACTUS_HEIGHT         70


//Size of nut
#define IMG_NUT_WIDHT           65
#define IMG_NUT_HEIGHT          73


//The size of the bullet 
#define IMG_SHELL_WIDHT         30
#define IMG_SHELL_HEIGHT        16

//The size of the car
#define IMG_DOLLY_WIDHT         70
#define IMG_DOLLY_HEIGHT        57

//The size of the shovel
#define IMG_SHOVEL_WIDHT         70
#define IMG_SHOVEL_HEIGHT        74

//The size of a pea
#define IMG_BULLET_WIDHT      56
#define IMG_BULLET_HEIGHT     34
//The size of the sun
#define IMG_SUN_WIDHT      78
#define IMG_SUN_HEIGHT     78

//Solar recovery timer
#define IMG_CARDSUN_RECYCLE_ID 19
#define IMG_CARDSUN_RECYCLE_INTERVAL 200

//Border of background image
#define IMG_FRAME_WIDTH       250 
#define IMG_FRAME_HEIGTH       70

//The size of a cherry bomb
#define IMG_CHERRY_WIDHT     84
#define IMG_CHERRY_HEIGHT     84

//The cherry after the explosion
#define IMG_CHERRY_BOOM_WIDHT     320
#define IMG_CHERRY_BOOM_HEIGHT     227

//草格的宽高
#define IMG_CHECK_WIDTH        81
#define IMG_CHECK_HEIGTH         99

//商店的大小
#define IMG_SHOPBACKGROUND_WIDTH   447
#define IMG_SHOPBACKGROUND_HEIGHT  88
//卡片的大小
#define IMG_CARDBACKGROUND_WIDTH    1018
#define IMG_CARDBACKGROUND_HEIGHT  373
//窗口的大小
#define WINDOW_X  0
#define WINDOW_Y   25
//窗口的大小
#define WINDOW_WIDTH    IMG_PLANTSVSZOMBIESBACKGROUND_WIDTH
#define WINDOW_HEIGHT   IMG_PLANTSVSZOMBIESBACKGROUND_HEIGHT
#define WINDOW_TITLE    "植物大战僵尸"
//植物移动定时器
#define TIMER_PEASHOOTER_MOVE_ID              1
#define TIMER_PEASHOOTER_MOVE_INTERVAL        60
#define TIMER_PEASHOOTER_MOVE_STEP            6
#define TIMER_PEASHOOTER_ID 16
#define TIMER_PEASHOOTER_SEND_INTERVAL     1000
//豆移动定时器
#define TIMER_BULLET_MOVE_ID              2
#define TIMER_BULLET_MOVE_INTERVAL        80
#define TIMER_BULLET_MOVE_STEP            8

//小车移动的步伐
#define TIMER_DOLLY_MOVE_ID              4
#define TIMER_DOLLY_MOVE_INTERVAL        80
#define TIMER_DOLLY_MOVE_STEP     10

//豆发射定时器
#define TIMER_BULLET_SEND_ID              3
#define TIMER_BULLET_SEND_INTERVAL        2000

#define TIMER_SUN_MOVE_ID              13
#define TIMER_SUN_MOVE_INTERVAL        200
#define TIMER_SUN_MOVE_STEP            10
#define TIMER_SUN_CREATE_ID              14
#define TIMER_SUN_CREATE_INTERVAL        16000

#define TIMER_CARDBACKGROUND_CREATE_ID              15
#define TIMER_CARDBACKGROUND_CREATE_INTERVAL        7000

#define IMG_ORDINARYZOMBIE_WIDHT      166
#define IMG_ORDINARYZOMBIE_HEIGHT     144
#define IMG_BUCKTEHEADZOMBIE_WIDHT   166
#define IMG_BUCKTEHEADZOMBIE_HEIGHT   144
#define IMG_ConeHeadZombie_WIDHT     166
#define IMG_ConeHeadZombie_HEIGHT     144
#define IMG_RUGBYZOMBIE_WIDHT     154
#define IMG_RUGBYZOMBIE_HEIGHT    160
#define IMG_FLAGZOMBIE_WIDHT     166
#define IMG_FLAGZOMBIE_HEIGHT     144

//僵尸死亡之后的图
#define IMG_ORDINARYZOMBIEB_WIDHT      332
#define IMG_ORDINARYZOMBIEB_HEIGHT     144
#define IMG_BUCKTEHEADZOMBIEB_WIDHT    332
#define IMG_BUCKTEHEADZOMBIEB_HEIGHT   144
#define IMG_ConeHeadZombieB_WIDHT      332
#define IMG_ConeHeadZombieB_HEIGHT     144
#define IMG_RUGBYZOMBIEB_WIDHT         366
#define IMG_RUGBYZOMBIEB_HEIGHT    204
#define IMG_FLAGZOMBIEB_WIDHT           332
#define IMG_FLAGZOMBIEB_HEIGHT     144

//僵尸移动和步长
#define TIMER_ORDINARYZOMBIE_MOVE_ID              5
#define TIMER_ORDINARYZOMBIE_MOVE_INTERVAL        250
#define TIMER_ORDINARYZOMBIE_MOVE_STEP          6
#define TIMER_BUCKTEHEADZOMBIE_MOVE_STEP        4
#define TIMER_CONEHEADZOMBIE_MOVE_STEP          5
#define TIMER_FLAGZOMBIE_MOVE_STEP              2
#define TIMER_RUGBYZOMBIE_MOVE_STEP             7

//僵尸的创造
#define TIMER_ORDINARYZOMBIE_CREATE_ID              6
#define TIMER_ORDINARYZOMBIE_CREATE_INTERVAL        12000

#define TIMER_BUCKTEHEADZOMBIE_CREATE_ID              7
#define TIMER_BUCKTEHEADZOMBIE_CREATE_INTERVAL        26000//秒

#define TIMER_CONEHEADZOMBIE_CREATE_ID              8
#define TIMER_CONEHEADZOMBIE_CREATE_INTERVAL        18000


#define TIMER_FLAGZOMBIE_CREATE_ID              17
#define TIMER_FLAGZOMBIE_CREATE_INTERVAL        40000

#define TIMER_RUGBYZOMBIE_CREATE_ID              18
#define TIMER_RUGBYZOMBIE_CREATE_INTERVAL        32000

//碰撞和删除僵尸
#define TIMER_IS_HIT_ID                     9
#define TIMER_IS_HIT_INTERVAL               10
#define TIMER_CHANGE_SHOWID_ID                     10
#define TIMER_CHANGE_SHOWID_INTERVAL               300
//僵尸的血量
#define DEF_ORDINARYZOMBIE_BLOOD   5
#define DEF_BUCKTEHEADZOMBIE_BLOOD    9
#define DEF_CONEHEADZOMBIE_BLOOD     7
#define DEF_RUGBYZOMBIE_BLOOD        10
#define DEF_FLAGZOMBIE_BLOOD         6

//植物的血量
#define DEF_PEASHOOTER_BLOOD    100
#define DEF_CACTUS_BLOOD          100
#define DEF_NUT_BLOOD           500
#define DEF_SUNFLOWER_BLOOD      100
#define DEF_CHERRY_BLOOD          3000

//武器攻击的伤害
#define DEF_BULLET_HURT     1
#define  DEF_DOLLY_HURT     10
#define  DEF_CHERRY_HURT    10


#define TIMER_START_SHOWID_ID                     11
#define TIMER_KAISHI_SHOWID_INTERVAL               300
//豌豆摆动的频率
#define TIMER_GANGKAISHI_SHOWID_ID                     12
#define TIMER_GANGKAISHI_SHOWID_INTERVAL               100

//太阳摆动的频率
#define TIMER_SUNFLOWER_SHOWID_ID                 20
#define TIMER_SUNFLOWER_SHOWID_INTERVAL          100


//向日葵产生太阳
#define TIMER_SUNFLOWER_CREATE_ID      21
#define TIMER_SUNFLOWER_CREATE_INTERVAL      120000

//The creation of the cannonball
#define TIMER_SHELL_CREATE_ID       22
#define TIMER_SHELL_CREATE_INTERVAL   3000

//The movement of the cannonball
#define TIMER_SHELL_MOVE_ID          23
#define TIMER_SHELL_MOVE_INTERVAL      80
#define TIMER_SHELL_MOVE_STEP          8

//The frequency of the sun's swing
#define TIMER_CACTUS_SHOWID_ID                 24
#define TIMER_CACTUS_SHOWID_INTERVAL          100

//How often the wall of nuts oscillates
#define TIMER_NUT_CREATE_ID                25
/**
 * \brief 
 */
#define TIMER_SUNFLOWER_CREATE_INTERVAL       3000

//Plants drop blood
#define TIMER_PLANTS_STAXIS_ID                 26
#define TIMER_PLANTS_STAXIS_INTERVAL          500

//Cherry blast
#define TIMER_CHERRY_BOOM_ID                  27
#define TIMER_CHERRY_BOOM_INTERVAL            2000

//Cherry blast
#define TIMER_CHERRY_BOOMFRAME_ID                  28
#define TIMER_CHERRY_BOOMFRAME_INTERVAL            3000

//Display a shovel
#define TIMER_SHOVEL_SHOW_ID                  29
#define TIMER_SHOVEL_SHOW_INTERVAL            300
