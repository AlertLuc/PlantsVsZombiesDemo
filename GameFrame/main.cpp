#include"GameFrame.h"
#include<Windowsx.h>
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>//包含多媒体设备接口头文件
#pragma comment(lib,"winmm.lib")//加载静态库
CGameFrame *pGameFrame = nullptr;
void BGM()
{
	mciSendString("play ./res/openingmusic.mp3", 0, 0, 0);
	mciSendString("play ./res/openingmusic.mp3 repeat", NULL, 0, NULL);//循环播放

}

// 3. 游戏运行

//回调函数的定义
LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{ //窗口句柄、消息、按下那个消息在后两个获取

	if(pGameFrame && pGameFrame->m_MsgMap.count(uMsg))
	{

		switch (pGameFrame->m_MsgMap[uMsg].msgType)
		{
		case EM_MOUSE:  //鼠标
			{
				POINT po={0};
				po.x = GET_X_LPARAM(lParam); //需要头像文件#include<Windowsx.h>
				po.y= GET_Y_LPARAM(lParam);
				(pGameFrame->*(pGameFrame->m_MsgMap[uMsg].p_fun_EM_MOUSE)  )(po);
			}
			break;
		case EM_KEY:  //键盘
			{
				(pGameFrame->*(pGameFrame->m_MsgMap[uMsg].p_fun_EM_KEY)   )(wParam);
			}
			break;
		case EM_CHAR:
			{
				(pGameFrame->*(pGameFrame->m_MsgMap[uMsg].p_fun_EM_CHAR)   )(wParam);
			}
			break;
		case EM_WINDOW:
			{
				(pGameFrame->*(pGameFrame->m_MsgMap[uMsg].p_fun_EM_WINDOW)   )(wParam,lParam);
			}
			break;
		}

		//只要有消息，就重绘，保证及时刷新窗口
		if (pGameFrame) 
		{
			pGameFrame->OnPaint();
		}
	}
	if(uMsg == WM_CLOSE)
	{
		pGameFrame->ON_WM_CLOSE(wParam,lParam);
	}

	return DefWindowProc(hwnd,uMsg,wParam,lParam);  //window 的默认回调
}

CGameFrame * CreateObject();
extern int window_x ;
extern int window_y ;
extern int window_width ;
extern int window_height ;
extern const TCHAR * window_title ;

int main()
{
	BGM();
	pGameFrame =CreateObject();//定义一个对象
	pGameFrame->OnInit(window_x,window_y,window_width,window_height,window_title);

	while(!pGameFrame->GetQuit())
	{  //判断程序是否退出
		Sleep(100);
	}//程序即将退出

	if(pGameFrame)
	{  //回收new 的空间
		delete pGameFrame;
		pGameFrame = nullptr;
	}
	return 0;
}
