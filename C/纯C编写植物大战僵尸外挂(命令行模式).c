#include<stdio.h>
#include<windows.h>
#include<ctype.h>

#define true 1
#define false 0

int main()
{
	char command;	//输入的命令
	HWND hWnd;
	DWORD Pid;
	HANDLE hProcess = 0;

	while(true)
	{
		printf("===========植物大战僵尸外挂========\n");
		printf("	打开外挂O		修改金钱M	\n");
		printf("	修改血量H		退出外挂E	\n");
		printf("====================================\n");
		command = tolower(getchar());
		getchar();
		if(command == 'e')
		{
			break;
		}
		switch(command)
		{
		case 'o':
			hWnd = FindWindowA(NULL,"植物大战僵尸中文版");
			if(hWnd != 0)
			{
				GetWindowThreadProcessId(hWnd,&Pid);
				hProcess = OpenProcess(PROCESS_ALL_ACCESS,false,Pid);
				if(hProcess == 0)
				{
					printf("\n打开游戏进程失败\n");
				}
				else
				{
					printf("\n打开进程成功\n");
				}
			}
			break;
		case 'm':
			if(hProcess == 0)
			{
				printf("\n请先打开外挂\n");
			}
			else
			{
				int Money;
				DWORD Addr;
				DWORD res;

				DWORD val = 0x006A9EC0;
				DWORD valEx;
			/*	while(1)
				{*/
					static DWORD temp = 0;
					ReadProcessMemory(hProcess,(LPVOID)(0x006A9EC0),&val,4,NULL);
					ReadProcessMemory(hProcess,(LPVOID)(val + 0x82c),&val,4,NULL);
					valEx = val;
					ReadProcessMemory(hProcess,(LPVOID)(val + 0x28),&val,4,NULL);
					//ReadProcessMemory(hProcess,(LPVOID)(0x006A9EC0),&val,4,NULL);
					//ReadProcessMemory(hProcess,(LPVOID)(val + 0x768),&val,4,NULL);
					/*ReadProcessMemory(hProcess,(LPVOID)(val + 0x5560),&val,4,NULL);
					if(temp != val)
					{
						temp = val;
						printf("%d\n",val);
					}
					if(val < 20)
					{
						break;
					}*/
				//}
				scanf("%d",&Money);
				getchar();
				res = WriteProcessMemory(hProcess,(LPVOID)(valEx + 0x28),&Money,4,0);
				if(res == 0)
				{
					printf("\n修改太阳失败\n");
				}
				else
				{
					printf("\n修改太阳成功\n");
				}
			}
			break;
		case 'h':

			break;
		case 'e':

			break;
		}
	}
	return 0;
}
