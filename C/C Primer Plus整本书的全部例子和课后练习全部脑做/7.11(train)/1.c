//#include<stdio.h>
//
//int main(void)
//{
//	char ch;
//	int sp_ct = 0;//空格字符数
//	int hh_ct = 0;//换行字符数
//	int ou_ct = 0;//其他字符数
//	int total_ct = 0;//总字符数
//	
//	while((ch = getchar()) != '#')
//	{
//		total_ct++;
//		if(ch == ' ')
//		{
//			sp_ct++;
//		}
//		if(ch == '\n')
//		{
//			hh_ct++;
//		}
//	}
//	printf("spacenum = %d,hh = %d,ou = %d.\n",sp_ct,hh_ct,total_ct - sp_ct - hh_ct);
//	return 0;
//}