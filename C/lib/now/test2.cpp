#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

int n = 300;

int a = 1;

int solve(int x)
{
    return x * (n - x);
}

void test()
{
    int a = 2;
    a += 1;
}

int main()
{
    int l = 1,r = n;
    int mid1,mid2;
    int t = 50;

    while(t--)
    {
        mid1 = (l + r) >> 1;
        mid2 = (mid1 + r) >> 1;

        if(solve(mid1) > solve(mid2))
        {
            r = mid2;
        }
        else
        {
            l = mid1;
        }
    }

    cout << l << endl;//-x ^ 2 + 300x的极大值

    /**
     * 基本类型没有析构函数,可以使用delete释放new[]分配的内存,不会产生内存泄漏,不建议使用
     */
    char * p = new char[100];

    delete [] p;

    test();
    cout << a << endl;

    int x = 10;
    x += x -= x - x;

    cout << x << endl;

    int c = 0,k;
    //第一次循环没有case匹配,执行default,其后没有break,继续乡下执行
    //第二次循环命中case 2,执行后遇到break,停止执行
    for(k = 1;k < 3;k++)
    {
        switch(k)
        {
            default:c += k;
            case 2:c++;
            break;
            case 4:c += 2;
            break;
        }
    }
    cout << c << endl;


    return 0;
}