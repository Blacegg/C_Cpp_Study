#include<stdio.h>
#include<iostream>
using namespace std;
int f(int n)
{
    int i = 0;
    for (int k = 1; k <= n; k *= 2)
        ++i;
    for (int j = i / 2; j > 0; --j)
    {
        int v1 = (1 << (j - 1));
        int v2 = (1 << (i - j));
        bool flag1 = ((n & v1) != 0);
        bool flag2 = ((n & v2) != 0);
        if (flag1 != flag2)
        {
            n ^= v1;
            n ^= v2;
        }
    }
    return n;
}

int main()
{
    printf("%d\n", f(3456));
    return 0;
}