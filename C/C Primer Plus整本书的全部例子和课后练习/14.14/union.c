//������ϰ,�ṹ�����ϵĽ��,������Ϣ
#include<stdio.h>
#define OWNER 12
#define LEASE 40
//ӵ������Ϣ
struct owner{
	char socsecurity[OWNER];
};

//���޹�˾��Ϣ
struct leasecompany{
	char name[LEASE];
	char headquarters[LEASE];
};
//����
union data{
	struct owner ownercar;
	struct leasecompany leasecar;
};
//������Ϣ
struct car_data{
	char make[LEASE];
	int status;//״̬��0˽�У�1����
	union data ownerinfo;
};

int main()
{
	struct car_data flits;
	struct owner a = {"WJK"};
	puts("����������״̬:0˽�С�1����");
	scanf("%d",&flits.status);
	if(flits.status == 0)
	{
		flits.ownerinfo.ownercar.socsecurity;
	}
	else if(flits.status == 1)
	{
		flits.ownerinfo.leasecar.name;
		printf("Lease company is %s.\n",flits.ownerinfo.leasecar.name);
	}
	return 0;
}
