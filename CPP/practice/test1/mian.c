#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<windows.h>


void binali(int arr[],int n);
void temp(int arrValue);
void replaceMax(int arr[],int value);
void maopao(int arr[],int n);

void doubleMaoPao(double arr[],int n);
void doubleBianli(double arr[],int n);

int getIndex(int arr[],int n,int value);
int getIndex1(int arr[],int n,int vlaue);
void say(char *str);
void binali1(int arr[][3],int hang,int lie);
int sumary(int arr[3][3],int hang,int lie);

int getSum(int arr[],int n);
int getMax(int arr[],int n);
int getMin(int arr[],int n);
float getAvg(int arr[],int n);
void getDesc(int arr[],int n);


int main(int argc,char *argv[])
{

	//�����ʼ��
	//int arrFirst[3] = {1,2,3};//δ��ʼ��������Ĭ�ϸ�ֵΪ0
	//int arrSecond[] = {1,2,3};//��ʼ��ʱ�̶����ȣ����ڷ��ʲ���Խ��
	//int arrThird[3];//�Զ���������Ԫ�س�ʼ��ֵ��ȷ��

	//��̬����,Ĭ�� ��ʼ��Ϊ0
	//static int arr1[3];

	//�����ⲿ����,Ĭ�� ��ʼ��Ϊ0
	/*extern int arr2[3];

	arrThird[0] = 1;
	arrThird[1] = 2;
	arrThird[2] = 3;

	printf("%d\n",arrFirst[1]);
	printf("%d\n",arrSecond[1]);
	printf("%d\n",arrThird[1]);*/

	//�������
	/*int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int i;

	for(i = 0;i < (sizeof(arr)/sizeof(int));i++)
	{
		printf("%d\n",arr[i]);
	}*/


	//������Ϊ��������
	/*int arr[5] = {1,2,3,4,5};

	binali(arr,sizeof(arr)/sizeof(int));
	temp(arr[0]);*/

	//�滻���������ֵΪָ��ֵ
	/*int arr1[] = {10,41,3,12,22};
	int arr2[] = {1,2,3,4,5};
	int i;

	replaceMax(arr1,arr2[0]);

	for(i = 0;i < 5;i++)
	{
		printf("%d\n",arr1[i]);
	}*/


	//��������,ð������
	/*int arr[] = {99,94,95,93,92,91,90,88,97,89};
	int i,j,tmp;
	
	for(i = 0;i < 10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");*/

	/*for(i = 0;i < 9;i++)
	{
		for(j = 9;j > i;j--)
		{
			if(arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}*/
	/*maopao(arr,sizeof(arr)/sizeof(int));
	printf("�����\n");
	for(i = 0;i < 10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");*/

	/*double arr[] = {1.78,1.77,1.82,1.79,1.85,1.75,1.86,1.77,1.81,1.80};

	int i,j;
	double tmp;*/

	//printf("�Ŷ�ǰ\n");
	/*for(i = 0;i < 10;i++)
	{
		printf("%.2lf ",arr[i]);
	}*/
	/*doubleBianli(arr,sizeof(arr)/sizeof(double));
	printf("\n");*/
	//ð������
	/*for(i = 0;i < 9;i++)
	{
		for(j = 9;j > i;j--)
		{
			if(arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}*/
	/*doubleMaoPao(arr,sizeof(arr)/sizeof(double));
	printf("�ŶӺ�\n");*/
	/*for(i = 0;i < 10;i++)
	{
		printf("%.2lf ",arr[i]);
	}*/
	/*doubleBianli(arr,sizeof(arr)/sizeof(double));
	printf("\n");*/

	//�������в���Ԫ��
	/*int arr[5] = {22,12,19,38,17};
	int value = 38;
	int index = getIndex(arr,sizeof(arr)/sizeof(int),value);

	if(index != -1)
	{
		printf("%d�������д���,�±�Ϊ%d\n",value,index);
	}else{
		printf("%d�������в�����\n",value);
	}*/
	
	/*int arr[5] ={3,12,9,8,6};
	int value = 8;
	int index = getIndex1(arr,sizeof(arr)/sizeof(int),value);
	
	if(index != -1)
	{
		printf("%d�������д���,�±�Ϊ%d\n",value,index);
	}else{
		printf("%d�������в�����\n",value);
	}*/

	//�����ַ���
	/*char str[] = "abcdef";
	char str1[] = {'a','b','c','d','e','f','\0'};

	printf("%s\n",str);
	printf("%s\n",str1);
	puts(str);
	puts(str1);*/
	
	/*char str[] = "I LOVE YOU!";
	say(str);*/

	//�ַ�������
	/*char str[7] = "abc";
	char str1[] = {'a','b','d','\0'};
	int i = 0;
	char str2[] = "a";
	char str3[] = "b";
	char str4[] = "a";*/

	//strlen(str);//��ȡ�ַ����ĳ���,\0��β,������\0
	//strcmp(str,str1);//�Ƚ������ַ�������ȷ���0��ǰ��ASCII�󷵻�1�����򷵻�-1
	//strcpy(str,str1);//���ڶ��������ַ�����������һ���ַ�����
	//strcat(str,str1);//��str2ƴ�ӵ�str����,ƴ���ַ���
	//atoi("100");//���ַ���ת��Ϊ������100��������stdlib.hͷ�ļ���

	//strlen(str);
	/*printf("�ַ���str����Ϊ%d\n",strlen(str));
	printf("�ַ���str1����Ϊ%d\n",strlen(str1));*/

	//strcmp(str1,str2);
	/*printf("a��ASCII��Ϊ%d\n",'a');
	printf("b��ASCII��Ϊ%d\n",'b');
	printf("str2��str3�ȽϽ��Ϊ%d\n",strcmp(str2,str3));
	printf("str3��str2�ȽϽ��Ϊ%d\n",strcmp(str3,str2));
	printf("str2��str4�ȽϽ��Ϊ%d\n",strcmp(str2,str4));*/
	
	//strcpy(dest,source);//����ԭ���ַ��������ܿ����ַ�������
	/*printf("����ǰ��strΪ%s\n",str);
	strcpy(str,str1);
	printf("�������strΪ%s\n",str);*/
	
	//strcat(dest,source);//��sourceƴ�ӵ�dest���棬dest���㹻�Ŀռ䣬�����ַ����ڴ�ռ䲻���ص�
	/*printf("ƴ��ǰ��str:%s\n",str);
	strcat(str,str1);
	printf("ƴ�Ӻ��str:%s\n",str);*/

	/*char s1[100] = "";
	char s2[] = "I LOVE";
	char s3[] = " YOU!";

	strcpy(s1,s2);
	strcat(s1,s3);

	printf("%s\n",s1);*/

	//��ά����
	//int num[3][3] = {{1,2,3},{4,5,6},{7,8,9}};//���Բ�ָ����
	//int num1[3][3];
	//int i,j;
	
	//����ͬʱ�ƶ��к���
	//num1[0][0] = 1;

	/*int arr1[][2] = {{10,20},{30,40}};
	int arr2[2][2];

	arr2[0][0] = 10;
	arr2[0][1] = 20;
	arr2[1][0] = 30;
	arr2[1][1] = 40;*/

	//��ά�������
	//binali1(num,3,3);

	/*int i,j;

	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
		{
			printf("arr[%d][%d] = %d\n",i,j,num[i][j]);
		}
	}*/

	//int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	/*int i,j,sum = 0;

	for(i = 0;i < 3;i++)
	{
		for(j = 0;j < 3;j++)
		{
			if((i == j)|| (i == 0 && j == 2) || (i == 2 && j == 0))
			{
				sum += arr[i][j];
			}
		}
	}*/
	//printf("�Խ���Ԫ��֮��Ϊ%d\n",sumary(arr,3,3));

	//��������ĺ͡����ֵ����Сֵ��ƽ��ֵ����������
	/*int score[10] = {67,98,75,63,82,79,81,91,66,84};
	
	printf("�ܺ�Ϊ%d\n",getSum(score,sizeof(score)/sizeof(int)));
	printf("���ֵΪ%d\n",getMax(score,sizeof(score)/sizeof(int)));
	printf("��СֵΪ%d\n",getMin(score,sizeof(score)/sizeof(int)));
	printf("ƽ��ֵΪ%.2f\n",getAvg(score,sizeof(score)/sizeof(int)));
	printf("�������к�Ľ��Ϊ:\n");
	getDesc(score,sizeof(score)/sizeof(int));
	binali(score,sizeof(score)/sizeof(int));*/

	printf("ϵͳĬ������ID:%d\n",GetSystemDefaultLangID());
	return 0;
}

//int arr2[3];//�ⲿ����

//������Ϊ��������,����һά��������
void binali(int arr[],int n)
{
	int i;

	for(i = 0;i < n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
//����ֵ��Ϊ��������,�������Ԫ�ص�ֵ
void temp(int arrValue)
{
	printf("%d\n",arrValue);
}
//�滻ָ�������е����ֵ
void replaceMax(int arr[],int value)
{
	int max = arr[0];
	int index = 0;
	int i;
	
	for(i = 0;i < 5;i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
			index = i;
		}
	}
	arr[index] = value;
}
//��������ð������
void maopao(int arr[],int n)
{
	int i,j,tmp;

	for(i = 0;i < (n - 1);i++)
	{
		for(j = (n - 1);j > i;j--)
		{
			if(arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
//��������ð������
void doubleMaoPao(double arr[],int n)
{
	int i,j;
	double tmp;

	for(i = 0;i < (n - 1);i++)
	{
		for(j = (n - 1);j > i;j--)
		{
			if(arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
//����double����һά����
void doubleBianli(double arr[],int n)
{
	int i;

	for(i = 0;i < n;i++)
	{
		printf("%.2lf ",arr[i]);
	}
}
//�������в���Ԫ��
int getIndex(int arr[],int n,int value)
{
	int i;
	for(i = 0;i < n;i++)
	{
		if(arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}
int getIndex1(int arr[],int n,int value)
{
	int index,i;

	for(i = 0;i < n;i++)
	{
		if(arr[i] != value)
		{
			index = -1;
		}else{
			index = i;
			break;
		}
	}
	return index;
}
//���һ���ַ���
void say(char *str)
{
	printf("%s\n",str);
}
//��ά�����������
void binali1(int arr[][3],int hang,int lie)
{
	int i,j;

	for(i = 0;i < hang;i++)
	{
		for(j = 0;j < lie;j++)
		{
			printf("arr[%d][%d] = %d\n",i,j,arr[i][j]);
		}
	}
}
//�������Ͷ�ά����Խ���֮��
int sumary(int arr[3][3],int hang,int lie)
{
	int i,j,sum = 0;
	
	for(i = 0;i < hang;i++)
	{
		for(j = 0;j < lie;j++)
		{
			if((i == j)|| (i == 0 && j == (lie -1)) || (i == (hang -1) && j == 0))
			{
				sum += arr[i][j];
			}
		}
	}
	return sum;
}
//����һά���������ܺ�
int getSum(int arr[],int n)
{
	int i,sum = 0;

	for(i = 0;i < n;i++)
	{
		sum += arr[i];
	}
	return sum;
}
//�����ֵ
int getMax(int arr[],int n)
{
	int i,max = 0;

	for(i = 0;i < n;i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
//����Сֵ
int getMin(int arr[],int n)
{
	int i,min = arr[0];

	for(i = 0;i < n;i++)
	{
		if(arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
//��ƽ��ֵ
float getAvg(int arr[],int n)
{
	int i,sum = 0;
	float avg;

	for(i = 0;i < n;i++)
	{
		sum += arr[i];
	}
	avg = (float)sum/n;
	return avg;
}
//��������
void getDesc(int arr[],int n)
{
	int i,j,tmp;

	for(i = 0;i < n;i++)
	{
		for(j = (n - 1);j > i;j--)
		{
			if(arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}