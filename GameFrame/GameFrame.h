#include<easyx.h>
#include<string>
#include<map>
#include <ctime>
#include <string>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <io.h>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <mmsystem.h>
using namespace std;
//回调函数的声明
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#define ADD_MSG(MSG_ID,MSGTYPE)\
	m_MsgMap[MSG_ID].msgType = MSGTYPE;\
	m_MsgMap[MSG_ID].p_fun_##MSGTYPE = &CGameFrame::ON_##MSG_ID;

class CGameFrame 
{
	//友元  ，吧WindowProc当做朋友，可以在WindowPro里使用当前类的私有成员
	friend LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
	HWND m_hWnd;   //窗口句柄

private:
	bool m_isQuit;   // true :程序退出 false ，不退出

	typedef void (CGameFrame::* P_FUN_MOUSE)(POINT);//处理鼠标相关
	typedef void (CGameFrame::* P_FUN_KEY)(WPARAM);
	typedef void (CGameFrame::* P_FUN_CHAR)(WPARAM);
	typedef void (CGameFrame::* P_FUN_WINDOW)(WPARAM, LPARAM);

	//消息id  ,所属消息类型，消息处理函数
	struct MSG_FUN
	{//结构体
		UINT  msgType;   //消息类型   EM_MOUSE;
		union 
		{//联合，共用空间
			P_FUN_MOUSE   p_fun_EM_MOUSE;
			P_FUN_KEY     p_fun_EM_KEY;
			P_FUN_CHAR    p_fun_EM_CHAR;
			P_FUN_WINDOW  p_fun_EM_WINDOW;
		};
	};

	map<UINT, MSG_FUN>  m_MsgMap;    //消息映射表

public:
	CGameFrame() 
	{
		m_isQuit = false;  //不退出
	}

	bool GetQuit() 
	{
		return m_isQuit;
	}

	virtual ~CGameFrame() 
	{

	}

public:
	//1. 逻辑意义上的初始化，与程序业务逻辑有关
	void OnInit(int x, int y, int w, int h, const TCHAR* title)
	{
		m_hWnd = ::initgraph(w, h);  //初始化创建窗口

		MoveWindow(m_hWnd, x, y, w, h, true);  //移动

		SetWindowText(m_hWnd, title);   //设置窗口标题

		//初始化消息映射表
		InitMsgMap();

		InitGame();   //初始化具体类游戏

		//回调函数在创建窗口之后，游戏运行之前
		//重新设定窗口的回调函数
		::SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)&WindowProc);

	}

	//2.游戏重绘
	void OnPaint() 
	{
		::BeginBatchDraw();  //开始批量重绘
		::cleardevice();   //清屏

		PaintGame();    //重绘具体的游戏
		::EndBatchDraw();  //结束批量绘图
	}

	void InitMsgMap() 
	{
		//m_MsgMap[WM_LBUTTONDOWN].msgType = EM_MOUSE;
		//m_MsgMap[WM_LBUTTONDOWN].p_fun_EM_MOUSE = &CGameFrame::ON_WM_LBUTTONDOWN;
		ADD_MSG(WM_LBUTTONDOWN, EM_MOUSE);

		ADD_MSG(WM_KEYDOWN, EM_KEY);

		ADD_MSG(WM_CHAR, EM_CHAR);

		ADD_MSG(WM_TIMER, EM_WINDOW);   //添加定时器消息
		//ADD_MSG(WM_CLOSE,EM_WINDOW);
		ADD_MSG(WM_LBUTTONDOWN, EM_MOUSE);

		ADD_MSG(WM_MOUSEMOVE, EM_MOUSE);
		ADD_MSG(WM_LBUTTONUP, EM_MOUSE);

	


	}
	//3. 游戏运行
	//void OnRun()
	// {
	//	while(1)
	// {
	//		ExMessage msg;
	//		//获取消息
	//		getmessage(&msg);
	//		if(msg.message == WM_LBUTTONDOWN)
	// {  //鼠标左键按下
	//			string str;
	//			char arr1[10]={0};
	//			itoa(msg.message,arr1,10);
	//			char arr2[10]={0};
	//			itoa(msg.x,arr2,10);
	//			char arr3[10]={0};
	//			itoa(msg.y,arr3,10);
	//			str += arr1;
	//			str += arr2;
	//			str += arr3;
	//			WM_CLOSE;
	//			WM_TIMER;
	//			OutputDebugString(str.c_str());
	//		}
	//	}
	//}
	//---------------------------------------------

	virtual void InitGame() = 0;
	virtual void PaintGame() = 0;
	virtual void CloseGame() = 0;

	/*
		添加消息处理函数，函数名 ON_消息ID的宏，函数原型见 typedef 的类成员函数指针的类型
	*/

	virtual void ON_WM_LBUTTONDOWN(POINT po)
	{

	};
	virtual void ON_WM_LBUTTONUP(POINT po)
	{

	};
	virtual void ON_WM_MOUSEMOVE(POINT po)
	{

	};
	
	virtual void ON_WM_KEYDOWN(WPARAM w) 
	{

	};
	virtual void ON_WM_CHAR(WPARAM w) 
	{
	
	};
	virtual void ON_WM_TIMER(WPARAM w, LPARAM l)
	{
	
	};


	//4. 关闭窗口-------------------------------------
	void ON_WM_CLOSE(WPARAM w, LPARAM l) 
	{
		//close 具体的游戏
		CloseGame();
		::closegraph();  //关闭 游戏壳窗口
		m_isQuit = true;
	}
};

#define DYNAMIC_OBJECT(CLASS_NAME)\
CGameFrame * CreateObject()\
{\
	return new CLASS_NAME;\
}

#define WINDOW_PARAM(X,Y,WIDHT,HEIGHT,TITLE)\
int window_x               =X;\
int window_y               =Y;\
int window_width           =WIDHT;\
int window_height          =HEIGHT;\
const TCHAR * window_title = TITLE;

/*
自定义一个子类 ，继承游戏壳类（CGameFrame）,重写里面的纯虚函数InitGame(),PaintGame(),CloseGame().
在子类的源文件中，粘贴两个宏DYNAMIC_OBJECT(CLASS_NAME)，WINDOW_PARAM(X,Y,WIDHT,HEIGHT,TITLE) ，
宏传递对应的参数 即可
*/