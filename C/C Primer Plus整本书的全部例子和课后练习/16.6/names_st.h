//�ַ������С
#define SLEN 32

//�ṹ����
struct names_st{
	char first[SLEN];
	char last[SLEN];
};

//���Ͷ���
typedef struct names_st NAMES;

//��������
void getName(NAMES * ps);
void showName(const NAMES * ps);