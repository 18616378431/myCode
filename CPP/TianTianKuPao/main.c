#include<iostream>
#include<windows.h>
#include<cstring>
#include"resource.h"

#define ROAD_U 241

#define BOOL int
#define true 1
#define false 0

#define WS_EX_LAYERED 0x00080000

using namespace std;

LRESULT CALLBACK wndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
void man_jump(int * man_y,BOOL * flag);//人物跳跃

//全局程序句柄
HINSTANCE hInst = NULL;

//颜色透明指针函数
typedef BOOL (WINAPI * lpfn)(HWND hWnd,COLORREF cr,BYTE bAlpha,DWORD dwFlags);
lpfn g_pSetLayeredWindowAttributes;

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	wchar_t szAppName[] = TEXT("ttkp");
	WNDCLASSEX wc;
	HWND hWnd;
	MSG msg;

	hInst = hInstance;

	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.hbrBackground = (HBRUSH)5;
	wc.hCursor = LoadCursor(hInstance,MAKEINTRESOURCE(IDC_CURSOR1));
	wc.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));
	wc.hIconSm = NULL;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = wndProc;
	wc.lpszClassName = szAppName;
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	
	wc.style = CS_VREDRAW|CS_HREDRAW;

	RegisterClassEx(&wc);

	hWnd = CreateWindowW(szAppName,
						L"天天酷跑",
						WS_OVERLAPPED     | \
						 WS_CAPTION       | \
						 WS_SYSMENU       | \
						 WS_MINIMIZEBOX,
						40,
						80,
						1212,//1206 + 6
						540,//512 + 28
						NULL,
						NULL,
						hInstance,
						NULL);

	ShowWindow(hWnd,nShowCmd);

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT CALLBACK wndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	//背景画刷
	static HBRUSH hBackBrush;
	COLORREF clTransparent = RGB(255,255,255);

	//位图
	HBITMAP hBitmap;
	BITMAP bitmap;
	HDC hMemDC;
	//背景太阳横纵坐标
	static int sun_x = 0;
	static int sun_y = 0;
	//路面
	static int road_x = 0;
	//人物纵坐标
	static int man_y = 512 - 150 - 100 + 20;
	static BOOL jump_flag = false;
	static BOOL stop_jump = true;
	char re_name[20] = {0};
	static int index = 0;//人物图片索引
	//背景透明
	//获取函数在user32.dll中的指针
	HMODULE hUser32 = GetModuleHandle(TEXT("USER32.DLL"));
	g_pSetLayeredWindowAttributes = (lpfn)GetProcAddress(hUser32,"SetLayeredWindowAttributes");
	if(g_pSetLayeredWindowAttributes == NULL)
	{
		PostQuitMessage(0);
	}


	switch(msg)
	{
	case WM_CREATE:
		//SetTimer(hWnd,1001,20,NULL);
		
		//SetWindowLong(hWnd,GWL_EXSTYLE,GetWindowLong(hWnd,GWL_EXSTYLE)|WS_EX_LAYERED);
		//g_pSetLayeredWindowAttributes(hWnd,clTransparent,0,1);
		//RedrawWindow(hWnd,NULL,NULL,RDW_ERASE | RDW_INVALIDATE | RDW_FRAME | RDW_ALLCHILDREN);
		//SetLayeredWindowAttributes(hWnd, clTransparent, 0, LWA_COLORKEY);
		break;
	case WM_TIMER:
		/****************begin背景:太阳、墙****************/
		hdc = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hdc);
		hBitmap = (HBITMAP)LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP1));
		//hBitmap = (HBITMAP)LoadImage(NULL,L"imgs\\bg.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		GetObject(hBitmap,sizeof(BITMAP),&bitmap);
		SelectObject(hMemDC,hBitmap);
		BitBlt(hdc,0,0,1206 - sun_x,512 - sun_y,hMemDC,sun_x,sun_y,SRCCOPY);
		BitBlt(hdc,1206 - sun_x,0,sun_x,512 - sun_y,hMemDC,0,0,SRCCOPY);
		DeleteDC(hMemDC);
		DeleteObject(hBitmap);
		ReleaseDC(hWnd,hdc);
		sun_x += 3;
		if(sun_x >= 1206)
		{
			sun_x = 0;
		}
		/****************end背景太阳****************/
		/****************begin路面****************/
		//A
		hdc = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hdc);
		hBitmap = (HBITMAP)LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP2));
		//hBitmap = (HBITMAP)LoadImage(NULL,L"imgs\\roadcenter.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		GetObject(hBitmap,sizeof(BITMAP),&bitmap);
		SelectObject(hMemDC,hBitmap);
		BitBlt(hdc,1 * ROAD_U,512 - 150,241,150,hMemDC,0,0,SRCCOPY);
		DeleteDC(hMemDC);
		DeleteObject(hBitmap);
		ReleaseDC(hWnd,hdc);
		//B
		hdc = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hdc);
		hBitmap = (HBITMAP)LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP4));
		//hBitmap = (HBITMAP)LoadImage(NULL,L"imgs\\roadright.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		GetObject(hBitmap,sizeof(BITMAP),&bitmap);
		SelectObject(hMemDC,hBitmap);
		BitBlt(hdc,2 * ROAD_U,512 - 150,71,150,hMemDC,0,0,SRCCOPY);
		DeleteDC(hMemDC);
		DeleteObject(hBitmap);
		ReleaseDC(hWnd,hdc);
		//C
		hdc = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hdc);
		hBitmap = (HBITMAP)LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP3));
		//hBitmap = (HBITMAP)LoadImage(NULL,L"imgs\\roadleft.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		GetObject(hBitmap,sizeof(BITMAP),&bitmap);
		SelectObject(hMemDC,hBitmap);
		BitBlt(hdc,1 * ROAD_U - 40,512 - 150,241,150,hMemDC,0,0,SRCCOPY);
		DeleteDC(hMemDC);
		DeleteObject(hBitmap);
		ReleaseDC(hWnd,hdc);
		/****************end路面****************/
		/****************begin人物****************/
		hdc = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hdc);
		sprintf_s(re_name,"imgs\\player_%d.bmp",index);
		hBitmap = (HBITMAP)LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP5 + index));
		//hBitmap = (HBITMAP)LoadImageA(NULL,re_name,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		GetObject(hBitmap,sizeof(BITMAP),&bitmap);
		SelectObject(hMemDC,hBitmap);
		BitBlt(hdc,1 * ROAD_U + 30,man_y,123,100,hMemDC,0,0,SRCCOPY);
		DeleteDC(hMemDC);
		DeleteObject(hBitmap);
		ReleaseDC(hWnd,hdc);
		//跳跃
		if(!stop_jump)
		{
			man_jump(&man_y,&jump_flag);
		}
		if(man_y >= 512 - 150 - 100 + 20)
		{
			stop_jump = true;
		}
		if(index <= 9)
		{
			index++;
		}
		else
		{
			index = 0;
		}
		/****************end人物****************/
		break;
	case WM_LBUTTONDOWN:
		//MessageBox(NULL,L"LB",L"LB",MB_OK);
		if(stop_jump == true)
		{
			jump_flag = true;
			stop_jump = false;
		}
		break;
	case WM_RBUTTONDOWN:
		//MessageBox(NULL,L"RB",L"RB",MB_OK);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd,&ps);
		hMemDC = CreateCompatibleDC(hdc);//创建兼容DC
		hBitmap = (HBITMAP)LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP15));
		//hBitmap = (HBITMAP)LoadImage(NULL,L"imgs\\sunbg.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);//加载位图
		GetObject(hBitmap,sizeof(BITMAP),&bitmap);//得到一个位图对象
		SelectObject(hMemDC,hBitmap);//将对象选入到内存
		BitBlt(hdc,0,0,1206,512,hMemDC,0,0,SRCCOPY);//显示位图
		DeleteDC(hMemDC);//释放兼容DC
		DeleteObject(hBitmap);//删除位图对象
		EndPaint(hWnd,&ps);
		//test
		/*hdc = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hdc);
		hBitmap = (HBITMAP)LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP5));
		GetObject(hBitmap,sizeof(BITMAP),&bitmap);
		SelectObject(hMemDC,hBitmap);
		BitBlt(hdc,0,0,123,100,hMemDC,0,0,SRCCOPY);
		DeleteDC(hMemDC);
		DeleteObject(hBitmap);
		ReleaseDC(hWnd,hdc);*/
		break;
	case WM_COMMAND:
		switch(wParam)
		{
		case ID_BEGIN:
			//MessageBox(NULL,L"ID_BEGIN",L"ID_BEGIN",MB_OK);
			SetTimer(hWnd,1001,2,NULL);
			break;
		case ID_EXIT:
			PostQuitMessage(0);
			break;
		case ID_ABOUT:
			MessageBox(NULL,L"ID_ABOUT",L"ID_ABOUT",MB_OK);
			break;
		}
		break;
	case WM_CLOSE:
		if(hUser32 != NULL)
		{
			FreeLibrary(hUser32);
		}
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}
//人物跳跃
void man_jump(int * man_y,BOOL * flag)
{
	if((*man_y) <= 132)
	{
		*flag = false;
	}
	if(*flag)
	{
		(*man_y) -= 5;
	}
	else
	{
		(*man_y) += 5;
	}
}
