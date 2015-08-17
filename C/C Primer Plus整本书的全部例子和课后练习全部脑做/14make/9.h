#define BOOL int
#define true 1
#define false 0
#define LEN 40
#define SIZE 12

typedef struct seat{
	int code;//座位编号
	BOOL isSale;//是否已经被预定的标记
	char fn[LEN];//姓
	char ln[LEN];//名
}SEAT;

void createFile(void);
int setFileName(int fnum);
int getInfo(SEAT * st);
char menu(int fnum);
void opera(SEAT * seat1,int fnum);
void emptyNum(SEAT * st);
void emptyList(SEAT * st);
void showAlpha(SEAT * st);
void assign(SEAT * st);
void delSeat(SEAT * st);
void editSeat(SEAT * st);
void saveInfo(SEAT st[],int size);
void delMore(void);

char file_name[LEN];