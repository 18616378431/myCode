//#include<stdio.h>
//
//int main(void)
//{
//	int guess = 50;
//	char response;
//	char bol;		//´æ´¢´óÐ¡µÄ×Ö·û
//
//	printf("Enter a number from 1 to 100.\n");
//	printf("I'll guess which you are thinking!(yes y no n.)\n");
//	printf("It's %d?\n",guess);
//	while((response = getchar()) != 'y')
//	{
//		if(response == 'n')
//		{
//			printf("It's less than %d?...\n",guess);
//			while(getchar() != '\n')
//			{
//				continue;
//			}
//			bol = getchar();
//			if(bol == 'y')
//			{
//				guess /= 2;
//			}
//			if(bol == 'n')
//			{
//				if(guess >= 50)
//				{
//					guess = (guess + 100) / 2;
//				}
//				if(guess < 50)
//				{
//					guess = (guess + 50) / 2;
//				}
//			}
//		}
//		else
//		{
//			printf("Sorry,I only understand y or n.\n");
//		}
//		while(getchar() != '\n')
//		{
//			continue;
//		}
//		printf("It's %d?\n",guess);
//	}
//	printf("It is %d,I know i could do it!\n",guess);
//	return 0;
//}