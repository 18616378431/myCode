/**
 * varargs printf函数实现
 */ 
#include <stdio.h>
#include <varargs.h>

// void error(va_alist) va_dcl;
// int my_printf(va_alist) va_dcl;

int mian()
{
    return 0;
}

// void error(va_alist) va_dcl
// {
//     va_list ap;
//     char *format;

//     va_start(ap);
//     format = va_arg(ap,char *);
//     vfprintf(stderr,format,ap);
//     va_end(ap);
// }

// int my_printf(va_alist) va_dcl
// {
//     va_list ap;
//     char *format;
//     int n;

//     va_start(ap);
//     format = va_arg(ap,char *);
//     n = vprintf(format,ap);
//     va_end(ap);

//     return n;
// }