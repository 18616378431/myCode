#include <stdio.h>

void func1();
void func2();

int main()
{
    func1();
    func2();

    return 0;
}

void func1()
{
    int i,n = 0;
    float x = 1,y1 = 2.1 / 1.9,y2 = 1.9 / 2.1;
    
    for(i = 1;i < 22;i++)
    {
        x = x * y1;
    }

    printf("x = %f\n",x);

    while(x != 1.0)
    {
        x = x * y2;
        n++;
        printf("x = %f\n",x);
        printf("%d\n",n);

        if(n == 40)
        {
            break;
        }
    }

    printf("%d\n",n);
}

void func2()
{
    int m = 7,n = 4;
    float a = 38.4,b = 6.4,x;
    x = m / 2 + n * a / b + 1 / 2;

    printf("%f\n",x);
}