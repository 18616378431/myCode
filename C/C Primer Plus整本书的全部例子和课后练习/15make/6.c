#include<stdio.h>
//字体属性，左右
#define LEFT 0
#define CENTER 1
#define RIGHT 2
//开关
#define ON 1
#define OFF 0
//ID掩码
#define ID_MASK 0xFF				//1111 1111
//SIZE掩码
#define SIZE_MASK 0xFF00			//1111 1111 0000 0000
//Alignment掩码
#define ALIGN_MASK 0x30000			//0011 0000 0000 0000 0000
//Bold掩码
#define BOLD_MASK 0x100000			//0001 0000 0000 0000 0000 0000
//Italic掩码
#define ITALIC_MASK 0x1000000		//0001 0000 0000 0000 0000 0000 0000
//Underline掩码
#define UNDERLINE_MASK 0x10000000	//0001 0000 0000 0000 0000 0000 0000 0000

typedef struct fontArgument{
	unsigned int font_id  :		8;	//字体ID
	unsigned int font_size:		7;	//字体大小
	unsigned int		  :		1;	//空白位
	unsigned int alignment:		2;	//字体属性，左或右
	unsigned int		  :		2;	//空白位
	unsigned int font_bold:		1;	//加粗
	unsigned int		  :		3;	//空白位
	unsigned int font_italic:	1;	//斜体
	unsigned int			:	3;	//空白位
	unsigned int font_underline:1;	//下划线
	unsigned int		  :		3;	//空白位
} FONT;

union view{
	FONT st_view;
	unsigned int ui_view;
};

char *arr[5] = {"left","center","right","off","on"};

void showSetting(FONT *f);
char menu();
//位字段
void fontId(FONT *f);//f
void fontSize(FONT *f);//s
void fontAlignment(FONT *f);//a
void fontBold(FONT *f);//b
void fontItalic(FONT *f);//i
void fontUnderline(FONT *f);//u
//操作整数的位
void bitId(unsigned int * pti);//id
void bitSize(unsigned int * pti);//size
void bitAlign(unsigned int * pti);//alignment
void bitBold(unsigned int * pti);//bold
void bitItalic(unsigned int * pti);//italic
void bitUnderline(unsigned int * pti);//underline
void itobs(unsigned int n);
void show_binstr(char * str);
void delMore();

int main()
{	
	union view font = {{1,12,RIGHT,OFF,OFF,OFF}};//初始化联合的第一个成员，结构体
	FONT * pf = &font.st_view;
	char ch;
	//init
	/*font.st_view.font_id = 1;
	font.st_view.font_size = 12;
	font.st_view.alignment = LEFT;
	font.st_view.font_bold = OFF;
	font.st_view.font_italic = OFF;
	font.st_view.font_underline = OFF;*/
	showSetting(pf);
	while((ch = menu()) != 'q')
	{
		puts("Enter your mode:");
		puts("f)bit field mode\tb)bit mode");
		switch(ch)
		{
		case 'f':
			ch = getchar();
			delMore();
			switch(ch)
			{
			case 'f':fontId(pf);break;
			case 'b':bitId(&font.ui_view);break;
			} 
			break;
		case 's':
			ch = getchar();
			delMore();
			switch(ch)
			{
			case 'f':fontSize(pf);break;
			case 'b':bitSize(&font.ui_view);break;
			} 
			break;
		case 'a':
			ch = getchar();
			delMore();
			switch(ch)
			{
			case 'f':fontAlignment(pf);break;
			case 'b':bitAlign(&font.ui_view);break;
			}  
			break;
		case 'b':
			ch = getchar();
			delMore();
			switch(ch)
			{
			case 'f':fontBold(pf);break;
			case 'b':bitBold(&font.ui_view);break;
			} 
			break;
		case 'i':
			ch = getchar();
			delMore();
			switch(ch)
			{
			case 'f':fontItalic(pf);break;
			case 'b':bitItalic(&font.ui_view);break;
			} 
			break;
		case 'u':
			ch = getchar();
			delMore();
			switch(ch)
			{
			case 'f':fontUnderline(pf);break;
			case 'b':bitUnderline(&font.ui_view);break;
			}  
			break;
		default:
			puts("Error input,Please type in an character such as f s a b i u or q:");
			break;
		}
		showSetting(pf);
	}
	itobs(font.ui_view);
	return 0;
}
char menu()
{
	char ch;
	
	puts("======================================================");
	puts("f)change font\ts)change size\ta)change alignment");
	puts("b)toggle bold\ti)toggle italic\tu)toggle underline");
	puts("q)quit");
	puts("======================================================");
	ch = getchar();
	delMore();
	return ch;
}
//位字段
void fontId(FONT *f)//f
{
	unsigned int id;
	puts("Enter font id:");
	scanf("%u",&id);
	if(id > 255)
		id -= 255;
	delMore();
	f->font_id = id;
}
void fontSize(FONT *f)//s
{
	unsigned int size;

	printf("Enter font size(0 - 127):");
	scanf("%u",&size);
	if(size > 127)
		size -= 127;
	delMore();
	f->font_size = size;
}
void fontAlignment(FONT *f)//a
{
	char ch;
	
	puts("Select alignment:");
	puts("l)left\tc)cener\tr)right");
	switch(ch = getchar())
	{
	case 'l':
		f->alignment = LEFT;
		break;
	case 'c':
		f->alignment = CENTER;
		break;
	case 'r':
		f->alignment = RIGHT;
		break;
	default:
		puts("Error input,please type in an character such as l c or r:");
		break;
	}
	delMore();
}
void fontBold(FONT *f)//b
{
	f->font_bold ^= 1;
}
void fontItalic(FONT *f)//i
{
	f->font_italic ^= 1;
}
void fontUnderline(FONT *f)//u
{
	f->font_underline ^= 1;
}
void showSetting(FONT *f)
{
	puts("ID\tSIZE\tALIGNMENT\tB\tI\tU");
	printf("%u\t%u\t%s\t\t%s\t%s\t%s\n",f->font_id,f->font_size,
		arr[f->alignment],arr[f->font_bold + 3],arr[f->font_italic + 3],arr[f->font_underline + 3]);
}
//位模式
void bitId(unsigned int * pti)//id
{
	int id;

	puts("Enter font id:");
	scanf("%d",&id);
	delMore();
	if(id > 255)
		id -= 255;
	*pti = *pti & (~ID_MASK) | id;
}
void bitSize(unsigned int * pti)//s
{
	int size;

	puts("Enter font size:");
	scanf("%d",&size);
	delMore();
	if(size > 127)
		size -= 127;
	*pti = *pti & ~SIZE_MASK | (size << 8);
}
void bitAlign(unsigned int * pti)//a
{
	char ch;
	
	*pti &= ~ALIGN_MASK;
	puts("Select alignment:");
	puts("l)left\tc)center\tr)right");
	ch = getchar();
	delMore();
	switch(ch)
	{
	case 'l':
		*pti |= (LEFT << 16);
		break;
	case 'c':
		*pti |= CENTER << 16;
		break;
	case 'r':
		*pti |= RIGHT << 16;
		break;
	default:
		puts("Error input,please type in an character such as l c or r:");
		break;
	}
}
void bitBold(unsigned int * pti)//Bold
{
	*pti ^= BOLD_MASK;
}
void bitItalic(unsigned int * pti)//Italic
{
	*pti ^= ITALIC_MASK;
}
void bitUnderline(unsigned int * pti)//underline
{
	*pti ^= UNDERLINE_MASK;
}
//show
void itobs(unsigned int n)
{
	char bin_str[8 * sizeof(unsigned int) + 1];
	int i;
	static int size = 8 * sizeof(unsigned int);

	for(i = size - 1;i >= 0;i--,n >>= 1)
	{
		bin_str[i] = (01 & n) + '0';
	}
	bin_str[size] = '\0';
	show_binstr(bin_str);
}
//清除多余字符
void delMore()
{
	while(getchar() != '\n')
		continue;
}
void show_binstr(char * str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		putchar(str[i]);
		if(++i % 4 == 0 && str[i] != '\0')
		{
			putchar(' ');
		}
	}
	putchar('\n');
}