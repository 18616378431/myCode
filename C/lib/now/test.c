#include <stdio.h>

#define SUM(x) 3 * x * x + 1

// 3 * 5 + 8 * 5 + 8 + 1

int main()
{
    int i;

    for(i = 0;i < 3;i++)
    {
        switch(i)
        {
            case 0:printf("%d",i);
            case 2:printf("%d",i);
            default:printf("%d",i);
        }
    }

    printf("\n");

    int x = 0,s = 0;

    while(!x != 0)
        s += ++x;
    
    printf("%d\n",s);

    int m = 5,n = 8;

    printf("%d\n",SUM(m + n));

    return 0;
}