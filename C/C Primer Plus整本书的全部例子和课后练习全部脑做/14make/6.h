#define LEN 40
typedef struct baseball{
	int ballNum;//球员号码
	char fn[LEN];//名
	char ln[LEN];//姓
	int stageNum;//上场次数
	int shotNum;//击中数
	int run_base_num;//走垒数
	int run_rbi;//跑点数
	float successAvg;//击球平均成功率
}BASEBALL;