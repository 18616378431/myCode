/**
 * printf函数实现 stdarg
 */
#include <stdio.h>
#include <stdarg.h>

int my_printf(char *format,...);
void error(char *format,...);

int main()
{
    int a = 10,b = 20;
    const char *x = "hello world";
    int args_num,args_num1;

    args_num1 = my_printf("a = %d,b = %d,x = %s\n%n",a,b,x,&args_num);

    printf("args_num = %d,args_num1 = %d\n",args_num,args_num1);

    error("%d%d\n",a,b);

    return 0;
}
//stdarg.h
int my_printf(char *format,...)
{
    va_list ap;
    int n;

    va_start(ap,format);
    n = vprintf(format,ap);
    va_end(ap);

    return n;
}

void error(char *format,...)
{
    va_list ap;
    va_start(ap,format);
    fprintf(stderr,format,ap);
    va_end(ap);
    fprintf(stderr,"\n");
}