#include <stdio.h>

int main()
{
    int a[10],i;

    // for(i = 0;i <= 10;i++)
    // {
    //     a[i] = 0;
    // }

    printf("%p,%p,%p\n",&a[10],&i,a);

    return 0;
}
