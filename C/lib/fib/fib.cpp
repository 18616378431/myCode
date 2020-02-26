#include <iostream>

using namespace std;

long long fib(long long n);

int main()
{
    for(int i = 1;i <= 50;i++)
    {
        cout << i << ":" << fib(i) << endl;
    }

    return 0;
}

long long fib(long long n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fib(n - 2) + fib(n - 1);
    }
    
}