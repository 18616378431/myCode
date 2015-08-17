#include<iostream>
#include<windows.h>
#include<cstring>
#include"resource.h"

#define BOOL int
#define true 1
#define false 0

#define DIS_OK 40	//对号间距

using namespace std;

LRESULT CALLBACK fun(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK AboutDlgProc (HWND hDlg, UINT message,WPARAM wParam, LPARAM lParam);

HINSTANCE hInst = NULL;

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	WNDCLASSEX wc;
	HWND hWnd;
	MSG msg;
	//当前屏幕的宽高
	int sx;
	int sy;

	hInst = hInstance;

	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.hbrBackground = (HBRUSH)5;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hIcon = LoadIcon(hInstance,L"PlantsIco.ico");
	wc.hIconSm = NULL;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = fun;
	wc.lpszClassName = L"cls";
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);

	wc.style = CS_VREDRAW|CS_HREDRAW;
	
	RegisterClassEx(&wc);
	//当前屏幕的宽高
	sx = GetSystemMetrics(SM_CXSCREEN);
	sy = GetSystemMetrics(SM_CYSCREEN);

	hWnd = CreateWindowW(L"cls",
						L"植物大战僵尸外挂",
						WS_OVERLAPPED     | \
						WS_CAPTION        | \
						WS_SYSMENU        | \
						WS_MINIMIZEBOX,
						sx / 2 - 200 - 200,
						sy / 2 - 150 - 100,
						423,
						498,
						NULL,
						NULL,
						hInstance,
						NULL);
	
	ShowWindow(hWnd,nShowCmd);
	UpdateWindow(hWnd);

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT CALLBACK fun(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	HWND hWndProc;//程序窗口句柄
	DWORD Pid;//程序id
	static HANDLE hProcess = NULL;//进程句柄

	//提示信息
	const int arrSize = 4;
	char arr[arrSize][MAXBYTE] = {"F1:无限太阳","F2:无限金钱","F3:无冷却时间","F4:砸瓷器透视"};
	//横纵坐标
	int x = 150,y = 150;
	//程序操作状态
	static char OpenProc[MAXBYTE] = {0};
	//F1无限太阳
	int sun = 9990;
	static BOOL sunFlag =false;
	//F2无限金钱
	int money = 999;
	static BOOL moneyFlag = false;
	//F3无冷却
	int cd = 1;
	int index;//无冷却循环
	static BOOL cdFlag = false;//无冷却开关
	int num;//卡槽格数

	//对号基础坐标
	const int ok_x = x + 110;
	const int ok_y = 150;

	//获取程序自身路径，以供重新打开使用
	char self_path[MAX_PATH] = {0};
	
	//内存读取
	DWORD res;
	DWORD val;

	//位图
	HBITMAP hBitmap;
	BITMAP bitmap;
	HDC hMemDC;

	//对话框
	static HINSTANCE hInstance;

	//字体

	

	switch(msg)
	{
	case WM_TIMER:
		hdc = GetDC(hWnd);
		TextOutA(hdc,120,350,OpenProc,(int)strlen(OpenProc));
		//阳光对号
		if(sunFlag)
		{
			TextOutA(hdc,ok_x,ok_y + 0 * DIS_OK,"√",2);
		}
		else
		{
			TextOutA(hdc,ok_x,ok_y + 0 * DIS_OK,"        ",4);
		}
		//金钱对号
		if(moneyFlag)
		{
			TextOutA(hdc,ok_x,ok_y + 1 * DIS_OK,"√",2);
		}
		else
		{
			TextOutA(hdc,ok_x,ok_y + 1 * DIS_OK,"        ",4);
		}
		//无冷却对号
		if(cdFlag)
		{
			TextOutA(hdc,ok_x,ok_y + 2 * DIS_OK,"√",2);
		}
		else
		{
			TextOutA(hdc,ok_x,ok_y + 2 * DIS_OK,"        ",4);
		}
		//F4
		if(cdFlag)
		{
			TextOutA(hdc,ok_x,ok_y + 3 * DIS_OK,"√",2);
		}
		else
		{
			TextOutA(hdc,ok_x,ok_y + 3 * DIS_OK,"        ",4);
		}
		ReleaseDC(hWnd,hdc);
		if(cdFlag)
		{
			//读取卡槽格数
			ReadProcessMemory(hProcess,(LPVOID)(0x006A9EC0),&num,4,NULL);
			ReadProcessMemory(hProcess,(LPVOID)(num + 0x768),&num,4,NULL);
			ReadProcessMemory(hProcess,(LPVOID)(num + 0x144),&num,4,NULL);
			ReadProcessMemory(hProcess,(LPVOID)(num + 0x24),&num,4,NULL);
			//读取偏移后地址
			ReadProcessMemory(hProcess,(LPVOID)(0x006A9EC0),&val,4,NULL);
			ReadProcessMemory(hProcess,(LPVOID)(val + 0x768),&val,4,NULL);
			ReadProcessMemory(hProcess,(LPVOID)(val + 0x144),&val,4,NULL);
			for(index = 0;index < num;index++)
			{
				res = WriteProcessMemory(hProcess,(LPVOID)(val + 0x70 + index * (0x50)),&cd,4,0);
				if(res == 0)
				{
					strcpy(OpenProc,"无冷却失败                  ");
				}
				else
				{
					strcpy(OpenProc,"无冷却已打开                ");
				}
			}
		}
		break;
	case WM_CREATE:
		//对话框
		hInstance = ((LPCREATESTRUCT) lParam)->hInstance ;
		//设置背景模式
		/*hdc = GetDC(hWnd);
		SetBkMode(hdc,TRANSPARENT);
		ReleaseDC(hWnd,hdc);*/
		//设置定时器
		SetTimer(hWnd,1001,300,NULL);
		//获取程序窗口句柄
		hWndProc = FindWindowA(NULL,"植物大战僵尸中文版");
		if(hWndProc != 0)
		{
			//获取程序Pid
			GetWindowThreadProcessId(hWndProc,&Pid);
			//根据Pid打开进程
			hProcess = OpenProcess(PROCESS_ALL_ACCESS,false,Pid);
			if(hProcess)
			{
				//strcpy(OpenProc,"打开进程成功                  ");
				strcpy(OpenProc,"外挂打开成功                  ");
			}
			else
			{
				strcpy(OpenProc,"打开进程失败                  ");
			}
		}
		else
		{
			strcpy(OpenProc,"游戏未运行,请打开游戏      ");
		}
		break;
	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_F1:
			ReadProcessMemory(hProcess,(LPVOID)(0x006A9EC0),&val,4,NULL);
			ReadProcessMemory(hProcess,(LPVOID)(val + 0x768),&val,4,NULL);
			res = WriteProcessMemory(hProcess,(LPVOID)(val + 0x5560),&sun,4,0);
			if(res == 0)
			{
				strcpy(OpenProc,"修改太阳失败                  ");
			}
			else
			{
				sunFlag = true;
				strcpy(OpenProc,"修改太阳成功                  ");
			}
			break;
		case VK_F2:
			ReadProcessMemory(hProcess,(LPVOID)(0x006A9EC0),&val,4,NULL);
			ReadProcessMemory(hProcess,(LPVOID)(val + 0x82C),&val,4,NULL);
			res = WriteProcessMemory(hProcess,(LPVOID)(val + 0x28),&money,4,0);
			if(res == 0)
			{
				strcpy(OpenProc,"修改金钱失败                  ");
			}
			else
			{
				moneyFlag = true;
				strcpy(OpenProc,"修改金钱成功                  ");
			}
			break;
		case VK_F3:
			if(cdFlag == false)
			{
				cdFlag = true;
			}
			else
			{
				cdFlag = false;
			}
			break;
		case VK_F4:
			MessageBox(hWnd,L"F4",L"F4",MB_OK);
			break;
		}
		break;
	case WM_PAINT:
		//hdc = GetDC(hWnd);//BeginPaint(hWnd,&ps);
		//Rectangle(hdc,400,0,605,300);
		//for(int i = 0;i < arrSize;i++)
		//{
		//	TextOutA(hdc,x,y,arr[i],(int)strlen(arr[i]));
		//	y += 20;
		//}
		////EndPaint(hWnd,&ps);
		//ReleaseDC(hWnd,hdc);

		hdc = BeginPaint(hWnd,&ps);
		hMemDC = CreateCompatibleDC(hdc);//创建兼容DC
		hBitmap = (HBITMAP)LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BITMAP4));
		//hBitmap = (HBITMAP)LoadImage(NULL,L"Koala.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);//加载位图
		GetObject(hBitmap,sizeof(BITMAP),&bitmap);//得到一个位图对象
		SelectObject(hMemDC,hBitmap);//将对象选入到内存
		BitBlt(hdc,0,0,423,498,hMemDC,0,0,SRCCOPY);//显示位图
		DeleteDC(hMemDC);//释放兼容DC
		DeleteObject(hBitmap);//删除位图对象
		//提示信息
		SetTextColor(hdc,RGB(0,255,255));
		SetBkMode(hdc,TRANSPARENT);
		for(int i = 0;i < arrSize;i++)
		{
			TextOutA(hdc,x,y,arr[i],(int)strlen(arr[i]));
			y += 40;
		}
		EndPaint(hWnd,&ps);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_OPEN:
			GetModuleFileNameA(NULL,self_path,MAX_PATH);
			PostQuitMessage(0);
			WinExec(self_path,SW_SHOW);
			break;
		case ID_EXIT:
			PostQuitMessage(0);
			break;
		case ID_ABOUT:
			MessageBox(NULL,L"游戏进行过程中请勿关闭外挂! 作者:WJK 主页:www.wjk123.com",L"关于",MB_OK);
			break;
		/*case ID_ABOUT :
			DialogBox (hInstance, TEXT ("AboutBox"), hWnd, AboutDlgProc) ;
			break ;*/
		}
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}
BOOL CALLBACK AboutDlgProc (HWND hDlg, UINT message,WPARAM wParam, LPARAM lParam)      
{  
	switch (message)  
	{
	case WM_INITDIALOG :
		break;
	case   WM_COMMAND :
		switch (LOWORD (wParam))
		{
		case IDOK:

			break;
		case IDCANCEL:
			EndDialog (hDlg, 0) ;
			break;
		}
		break ;
	}
	return false;
}
