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

	//数组初始化
	//int arrFirst[3] = {1,2,3};//未初始化的数组默认赋值为0
	//int arrSecond[] = {1,2,3};//初始化时固定长度，后期访问不可越界
	//int arrThird[3];//自动类型数组元素初始化值不确定

	//静态数组,默认 初始化为0
	//static int arr1[3];

	//引用外部数组,默认 初始化为0
	/*extern int arr2[3];

	arrThird[0] = 1;
	arrThird[1] = 2;
	arrThird[2] = 3;

	printf("%d\n",arrFirst[1]);
	printf("%d\n",arrSecond[1]);
	printf("%d\n",arrThird[1]);*/

	//数组遍历
	/*int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int i;

	for(i = 0;i < (sizeof(arr)/sizeof(int));i++)
	{
		printf("%d\n",arr[i]);
	}*/


	//数组作为函数参数
	/*int arr[5] = {1,2,3,4,5};

	binali(arr,sizeof(arr)/sizeof(int));
	temp(arr[0]);*/

	//替换数组中最大值为指定值
	/*int arr1[] = {10,41,3,12,22};
	int arr2[] = {1,2,3,4,5};
	int i;

	replaceMax(arr1,arr2[0]);

	for(i = 0;i < 5;i++)
	{
		printf("%d\n",arr1[i]);
	}*/


	//数组排序,冒泡排序
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
	printf("排序后\n");
	for(i = 0;i < 10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");*/

	/*double arr[] = {1.78,1.77,1.82,1.79,1.85,1.75,1.86,1.77,1.81,1.80};

	int i,j;
	double tmp;*/

	//printf("排队前\n");
	/*for(i = 0;i < 10;i++)
	{
		printf("%.2lf ",arr[i]);
	}*/
	/*doubleBianli(arr,sizeof(arr)/sizeof(double));
	printf("\n");*/
	//冒泡排序
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
	printf("排队后\n");*/
	/*for(i = 0;i < 10;i++)
	{
		printf("%.2lf ",arr[i]);
	}*/
	/*doubleBianli(arr,sizeof(arr)/sizeof(double));
	printf("\n");*/

	//在数组中查找元素
	/*int arr[5] = {22,12,19,38,17};
	int value = 38;
	int index = getIndex(arr,sizeof(arr)/sizeof(int),value);

	if(index != -1)
	{
		printf("%d在数组中存在,下标为%d\n",value,index);
	}else{
		printf("%d在数组中不存在\n",value);
	}*/
	
	/*int arr[5] ={3,12,9,8,6};
	int value = 8;
	int index = getIndex1(arr,sizeof(arr)/sizeof(int),value);
	
	if(index != -1)
	{
		printf("%d在数组中存在,下标为%d\n",value,index);
	}else{
		printf("%d在数组中不存在\n",value);
	}*/

	//定义字符串
	/*char str[] = "abcdef";
	char str1[] = {'a','b','c','d','e','f','\0'};

	printf("%s\n",str);
	printf("%s\n",str1);
	puts(str);
	puts(str1);*/
	
	/*char str[] = "I LOVE YOU!";
	say(str);*/

	//字符串函数
	/*char str[7] = "abc";
	char str1[] = {'a','b','d','\0'};
	int i = 0;
	char str2[] = "a";
	char str3[] = "b";
	char str4[] = "a";*/

	//strlen(str);//获取字符串的长度,\0结尾,不包括\0
	//strcmp(str,str1);//比较两个字符串，相等返回0，前者ASCII大返回1，否则返回-1
	//strcpy(str,str1);//将第二个参数字符串拷贝进第一个字符串中
	//strcat(str,str1);//将str2拼接到str后面,拼接字符串
	//atoi("100");//将字符串转换为整数，100，包含在stdlib.h头文件中

	//strlen(str);
	/*printf("字符串str长度为%d\n",strlen(str));
	printf("字符串str1长度为%d\n",strlen(str1));*/

	//strcmp(str1,str2);
	/*printf("a的ASCII码为%d\n",'a');
	printf("b的ASCII码为%d\n",'b');
	printf("str2与str3比较结果为%d\n",strcmp(str2,str3));
	printf("str3与str2比较结果为%d\n",strcmp(str3,str2));
	printf("str2与str4比较结果为%d\n",strcmp(str2,str4));*/
	
	//strcpy(dest,source);//覆盖原来字符串，不能拷贝字符串常量
	/*printf("拷贝前的str为%s\n",str);
	strcpy(str,str1);
	printf("拷贝后的str为%s\n",str);*/
	
	//strcat(dest,source);//将source拼接到dest后面，dest有足够的空间，两个字符串内存空间不能重叠
	/*printf("拼接前的str:%s\n",str);
	strcat(str,str1);
	printf("拼接后的str:%s\n",str);*/

	/*char s1[100] = "";
	char s2[] = "I LOVE";
	char s3[] = " YOU!";

	strcpy(s1,s2);
	strcat(s1,s3);

	printf("%s\n",s1);*/

	//多维数组
	//int num[3][3] = {{1,2,3},{4,5,6},{7,8,9}};//可以不指定行
	//int num1[3][3];
	//int i,j;
	
	//必须同时制定行和列
	//num1[0][0] = 1;

	/*int arr1[][2] = {{10,20},{30,40}};
	int arr2[2][2];

	arr2[0][0] = 10;
	arr2[0][1] = 20;
	arr2[1][0] = 30;
	arr2[1][1] = 40;*/

	//多维数组遍历
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
	//printf("对角线元素之和为%d\n",sumary(arr,3,3));

	//计算数组的和、最大值、最小值、平均值、降序排列
	/*int score[10] = {67,98,75,63,82,79,81,91,66,84};
	
	printf("总和为%d\n",getSum(score,sizeof(score)/sizeof(int)));
	printf("最大值为%d\n",getMax(score,sizeof(score)/sizeof(int)));
	printf("最小值为%d\n",getMin(score,sizeof(score)/sizeof(int)));
	printf("平均值为%.2f\n",getAvg(score,sizeof(score)/sizeof(int)));
	printf("降序排列后的结果为:\n");
	getDesc(score,sizeof(score)/sizeof(int));
	binali(score,sizeof(score)/sizeof(int));*/

	printf("系统默认语言ID:%d\n",GetSystemDefaultLangID());
	return 0;
}

//int arr2[3];//外部数组

//数组作为函数参数,遍历一维整型数组
void binali(int arr[],int n)
{
	int i;

	for(i = 0;i < n;i++)
	{
		printf("%d\n",arr[i]);
	}
}
//数组值作为函数参数,输出数组元素的值
void temp(int arrValue)
{
	printf("%d\n",arrValue);
}
//替换指定数组中的最大值
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
//整型数组冒泡排序
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
//浮点数组冒泡排序
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
//遍历double类型一维数组
void doubleBianli(double arr[],int n)
{
	int i;

	for(i = 0;i < n;i++)
	{
		printf("%.2lf ",arr[i]);
	}
}
//在数组中查找元素
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
//输出一个字符串
void say(char *str)
{
	printf("%s\n",str);
}
//二维整型数组遍历
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
//计算整型二维数组对角线之和
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
//计算一维整型数组总和
int getSum(int arr[],int n)
{
	int i,sum = 0;

	for(i = 0;i < n;i++)
	{
		sum += arr[i];
	}
	return sum;
}
//求最大值
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
//求最小值
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
//求平均值
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
//降序排列
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