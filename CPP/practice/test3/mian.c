#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Ԥ����,����Ԥ������̽��м򵥵��ַ����滻,���峣��
#define R 10	
//�꺯��,���
#define ADD(a,b) (a+b)//�겻���ֱ�������,����Ҫ�ֺŽ�β
#define X(n) (n*10)

#define MAX_LEN 1024

int add(int a,int b);//�������ֱ�������

typedef int *p;//typedef����䣬��Ҫ�ֺŽ�β,p����(int *)
//����ṹ��
typedef struct student{
	char name[MAX_LEN];
	int sex;
	int age;
	int tall;
}STU;

int main()
{
	int a = R;
	int b = R;

	/*float c = ADD(10.5,11.0);
	float d = add(10.5,11.0);*/
	
	//����int *����,�ȼ���int *k = NULL;
	p k = NULL;

	//�����ṹ��ָ��
	STU *stu = (STU *)malloc(sizeof(STU));

	strcpy(stu->name,"wjk");
	stu->sex = 1;
	stu->age = 26;
	stu->tall = 170;
	

	printf("%d+%d=%d\n",a,b,add(a,b));
	printf("%d+%d=%d\n",a,b,ADD(a,b));

	/*printf("c=%f\n",c);
	printf("d=%f\n",d);*/

	

	printf("name:%s\n",stu->name);

	printf("sizeof(STU)=%d\n",sizeof(STU));
	printf("sizeof(STU *)=%d\n",sizeof(STU *));
	
	return 0;
}
int add(int a,int b)
{
	return a+b;
}