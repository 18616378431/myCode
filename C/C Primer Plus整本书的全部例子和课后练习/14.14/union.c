//联合练习,结构和联合的结合,汽车信息
#include<stdio.h>
#define OWNER 12
#define LEASE 40
//拥有者信息
struct owner{
	char socsecurity[OWNER];
};

//租赁公司信息
struct leasecompany{
	char name[LEASE];
	char headquarters[LEASE];
};
//联合
union data{
	struct owner ownercar;
	struct leasecompany leasecar;
};
//汽车信息
struct car_data{
	char make[LEASE];
	int status;//状态，0私有，1租赁
	union data ownerinfo;
};

int main()
{
	struct car_data flits;
	struct owner a = {"WJK"};
	puts("输入汽车的状态:0私有、1租赁");
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
