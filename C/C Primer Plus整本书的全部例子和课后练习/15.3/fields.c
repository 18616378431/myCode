//�����ʹ��λ�ֶ�
#include<stdio.h>
//�Ƿ�͸�����Ƿ�ɼ�(1��͸����0͸��;1�ɼ���0���ɼ�)
#define	YES 1
#define NO 0
//�߿����ʽ
#define SOLID 0
#define DOTTED 1
#define DASHED 2
//��ԭɫ
#define RED 1
#define GREEN 2
#define BLUE 4
//�����ɫ
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)
//λ������ʹ�õĳ���
#define OPAQUE 0x1
#define FILL_BLUE 0x8
#define FILL_GREEN 0x4
#define FILL_RED 0x2
#define FILL_MASK 0xE
#define BORDER 0x100
#define BORDER_BLUE 0x800
#define BORDER_GREEN 0x400
#define BORDER_RED 0x200
#define BORDER_MASK 0xE00
#define B_SOLID 0
#define B_DOTTED 0x1000//0001 0000 0000 0000
#define B_DASHED 0x2000
#define STYLE_MASK 0x3000

const char * colors[8] = {"black","red","green","yellow","blue","magenta","cyan","white"};

struct box_props{
	unsigned int	  opaque:1;//�Ƿ�͸��
	unsigned int fille_color:3;//���ɫ
	unsigned int			:4;//����һ���ֽ�

	unsigned int show_border :1;//�Ƿ���ʾ�߿�
	unsigned int border_color:3;//�߿����ɫ
	unsigned int border_style:2;//�߿���
	unsigned int			 :2;//�ڶ����ֽ����ն�
		//�ṹ�干ռ��2�ֽڣ�16λ���հ�6λ��ʵ��ʹ��10λ
};

union Views{
	struct box_props st_view;
	unsigned int ui_view;
};

void show_setting(struct box_props * pb);
void show_setting1(unsigned short);
char * itobs(int n,char * ps);
void show_bstr(const char * str);

int main()
{	
	//����Views���󣬳�ʼ�����ϵĵ�һ��Ԫ��
	union Views box = {{YES,YELLOW,YES,GREEN,DASHED}};//�����ͳ�ʼ��λ�ֶ�
	char bin_str[8 * sizeof(unsigned int) + 1];

	printf("Oringinal box setting:\n");
	show_setting(&box.st_view);
	printf("\nBox setting using unsigned int view:\n");
	show_setting1(box.ui_view);
	
	show_bstr(itobs(box.ui_view,bin_str));
	//printf("Bits are \n%s.\n",itobs(box.ui_view,bin_str));

	box.ui_view &= ~FILL_MASK;//���������ɫ��λ��0
	box.ui_view |= (FILL_BLUE | FILL_GREEN);//�������ɫ
	box.ui_view ^= OPAQUE;//ת���Ƿ�͸����λ��
	box.ui_view |= BORDER_RED;//error
	box.ui_view &= ~STYLE_MASK;//�����ʽλ
	box.ui_view |= B_DOTTED;//����ʽ����Ϊ��

	puts("Modified box setting");
	show_setting(&box.st_view);
	puts("\nBox setting using unsigned int view:");
	show_setting1(box.ui_view);
	//printf("Bits are \n%s\n",itobs(box.ui_view,bin_str));
	show_bstr(itobs(box.ui_view,bin_str));
	return 0;
}
void show_setting(struct box_props * pb)
{
	printf("Box is %s.\n",pb->opaque == YES?"opaque":"transparent");
	printf("The file_color is %s.\n",colors[pb->fille_color]);
	printf("Border %s.\n",pb->show_border == YES?"shown":"not shown");
	printf("The border color is %s.\n",colors[pb->border_color]);
	printf("The border style is ");
	switch(pb->border_style)
	{
	case DASHED:
		puts("dashed");
		break;
	case SOLID:
		puts("solid");
		break;
	case DOTTED:
		puts("dotted");
		break;
	default:
		puts("Unknow type.");
		break;
	}
}
void show_setting1(unsigned short us)
{
	printf("Box is %s.\n",(us & OPAQUE) == OPAQUE?"opaque":"transparent");
	printf("The fill_color is %s.\n",colors[(us >> 1) & 07]);
	printf("Border %s.\n",(us & BORDER) == BORDER?"shown":"not shown");
	printf("Border style is ");
	switch((us & STYLE_MASK))
	{
	case B_SOLID:
		puts("solid");
		break;
	case B_DOTTED:
		puts("dotted");
		break;
	case B_DASHED:
		puts("dashed");
		break;
	default:
		puts("Unknow type!");
		break;
	}
	printf("The border color is %s.\n",colors[(us >> 9) & 07]);
}
char * itobs(int n,char * ps)
{
	int i;
	static int size = 8 * sizeof(unsigned int);

	for(i = size - 1;i >= 0;i--,n >>= 1)
	{
		ps[i] = (01 & n) + '0';
	}
	ps[size] = '\0';
	return ps;
}
void show_bstr(const char * str)
{
	int i = 0;
	
	printf("bits are ");
	while(str[i] != '\0')
	{
		putchar(str[i]);
		if(++i % 4 == 0)
		{
			putchar(' ');
		}
	}
	putchar('\n');
	putchar('\n');
}