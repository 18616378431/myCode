//�������ݽṹ
#include<stdio.h>
#define LEN 51

struct funds{
	char bank[LEN];
	double bankfund;
	char save[LEN];
	double savefund;
};

double sum(struct funds moolah);

int main()
{
	//��ʼ���ṹ��Ա
	struct funds stan = {
			"Garlic",
			3024.72,
			"Lucky's Saving and Loan",
			9237.11
	};

	printf("stan has a total of $%.2f.\n",sum(stan));
	return 0;
}
double sum(struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);
}