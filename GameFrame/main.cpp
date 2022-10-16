#include"GameFrame.h"
#include<Windowsx.h>
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>//������ý���豸�ӿ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")//���ؾ�̬��
CGameFrame *pGameFrame = nullptr;
void BGM()
{
	mciSendString("play ./res/openingmusic.mp3", 0, 0, 0);
	mciSendString("play ./res/openingmusic.mp3 repeat", NULL, 0, NULL);//ѭ������

}

// 3. ��Ϸ����

//�ص������Ķ���
LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{ //���ھ������Ϣ�������Ǹ���Ϣ�ں�������ȡ

	if(pGameFrame && pGameFrame->m_MsgMap.count(uMsg))
	{

		switch (pGameFrame->m_MsgMap[uMsg].msgType)
		{
		case EM_MOUSE:  //���
			{
				POINT po={0};
				po.x = GET_X_LPARAM(lParam); //��Ҫͷ���ļ�#include<Windowsx.h>
				po.y= GET_Y_LPARAM(lParam);
				(pGameFrame->*(pGameFrame->m_MsgMap[uMsg].p_fun_EM_MOUSE)  )(po);
			}
			break;
		case EM_KEY:  //����
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

		//ֻҪ����Ϣ�����ػ棬��֤��ʱˢ�´���
		if (pGameFrame) 
		{
			pGameFrame->OnPaint();
		}
	}
	if(uMsg == WM_CLOSE)
	{
		pGameFrame->ON_WM_CLOSE(wParam,lParam);
	}

	return DefWindowProc(hwnd,uMsg,wParam,lParam);  //window ��Ĭ�ϻص�
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
	pGameFrame =CreateObject();//����һ������
	pGameFrame->OnInit(window_x,window_y,window_width,window_height,window_title);

	while(!pGameFrame->GetQuit())
	{  //�жϳ����Ƿ��˳�
		Sleep(100);
	}//���򼴽��˳�

	if(pGameFrame)
	{  //����new �Ŀռ�
		delete pGameFrame;
		pGameFrame = nullptr;
	}
	return 0;
}
