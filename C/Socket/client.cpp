#include<iostream>
#include<winsock2.h>
#include<conio.h>
//#include<stdbool.h>
#include<string.h>

#define bool int
#define true 1
#define false 0

#pragma comment (lib,"ws2_32")

#define NAMELEN 20
#define BUFFSIZE 1024

typedef struct _SYS_INFO{
	OSVERSIONINFO OsVer;
	char szComputerName[NAMELEN];
	char szUserName[NAMELEN];
}SYS_INFO,*PSYS_INFO;

using namespace std;

void ShowSysInfo(PSYS_INFO sysinfo);
void editCmd();

int main(int argc,char * argv[])
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);//初始化动态链接库
	editCmd();

	SOCKET clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	char ipAddr[BUFFSIZE];
	cout << "Enter the host IP address:";
	gets_s(ipAddr);
	sockaddr_in sockaddr;
	sockaddr.sin_family = PF_INET;
	sockaddr.sin_port = htons(827);
	sockaddr.sin_addr.S_un.S_addr = inet_addr(ipAddr);

	int i = connect(clientSock, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR));
	if (i == 0)
	{
		printf("Connecttion successfully!Welcome to BdShell!\n");
	}
	else
	{
		cout << "Connecttion failed!Please open the server application!" << endl;
		return 0;
	}
	while (true)
	{
		char buff[BUFFSIZE] = {0};
		char cmd[MAXBYTE] = {0};

		recv(clientSock, buff, BUFFSIZE, NULL);
		printf("%s", buff);
		gets_s(cmd);
		send(clientSock, cmd, MAXBYTE, NULL);
		if (!strcmp(cmd, "exit") || !strcmp(cmd, "shutdown") || cmd[0] == '\0')
		{
			break;
		}
		memset(buff, 0, BUFFSIZE);
		recv(clientSock, buff, BUFFSIZE, NULL);
		if (!strcmp(cmd, "getsysinfo"))
		{
			PSYS_INFO Sysinfo = (PSYS_INFO)buff;
			int i = sizeof(Sysinfo);
			ShowSysInfo(Sysinfo);
		}
		else
		{
			printf("%s\n", buff);
		}
	}
	WSACleanup();
	return 0;
}
void ShowSysInfo(PSYS_INFO sysinfo)
{
	if (sysinfo->OsVer.dwPlatformId == VER_PLATFORM_WIN32_NT)
	{
		if (sysinfo->OsVer.dwMajorVersion == 6 && sysinfo->OsVer.dwMinorVersion == 2)
		{
			printf("Windows 8 %s\n",sysinfo->OsVer.szCSDVersion);
		}
		else if (sysinfo->OsVer.dwMajorVersion == 6 && sysinfo->OsVer.dwMinorVersion == 1)
		{
			printf("Windows 7 %s\n",sysinfo->OsVer.szCSDVersion);
		}
		else if (sysinfo->OsVer.dwMajorVersion == 6 && sysinfo->OsVer.dwMinorVersion == 0)
		{
			printf("Windows Server 2008 %s\n",sysinfo->OsVer.szCSDVersion);
		}
		else if (sysinfo->OsVer.dwMajorVersion == 5 && sysinfo->OsVer.dwMinorVersion == 2)
		{
			printf("Windows Server 2003 %s\n",sysinfo->OsVer.szCSDVersion);
		}
		else if (sysinfo->OsVer.dwMajorVersion == 5 && sysinfo->OsVer.dwMinorVersion == 1)
		{
			printf("Windows XP %s\n",sysinfo->OsVer.szCSDVersion);
		}
		else if (sysinfo->OsVer.dwMajorVersion == 5 && sysinfo->OsVer.dwMinorVersion == 0)
		{
			printf("Windows 2000 %s\n",sysinfo->OsVer.szCSDVersion);
		}
		
	}
	else
	{
		cout << " Other System" << endl;
	}
	printf("Computer Name is %s\n",sysinfo->szComputerName);
	printf("User Name is %s\n",sysinfo->szUserName);
}
void editCmd()
{
	system("color fc");
	system("title 客户端");
}
