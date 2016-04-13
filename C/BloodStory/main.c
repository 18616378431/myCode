#include<windows.h>
#include"resource.h"

LRESULT CALLBACK func(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	WNDCLASSEX cs;
	HWND hWnd;
	MSG msg;

	cs.cbClsExtra = 0;
	cs.cbSize = sizeof(WNDCLASSEX);
	cs.hbrBackground = (HBRUSH)5;
	cs.hCursor = LoadCursor(hInstance,MAKEINTRESOURCE(IDC_CURSOR1));;
	cs.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));
	cs.hIconSm =NULL;
	cs.hInstance = hInstance;
	cs.lpfnWndProc = func;
	cs.lpszClassName =L"blood";
	cs.lpszMenuName = L"Menu";
	cs.style = CS_HREDRAW | CS_VREDRAW;
	cs.cbWndExtra = 0;

	RegisterClassEx(&cs);

	hWnd = CreateWindowW(L"blood",L"BloodStory",WS_OVERLAPPEDWINDOW,100,100,800,600,NULL,NULL,hInstance,NULL);

	ShowWindow(hWnd,nCmdShow);
	
	while( GetMessage(&msg,NULL,0,0) )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK func(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}