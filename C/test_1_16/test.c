#include<stdio.h>
extern int Add(int x, int y);

int main()
{
    int a = 10 ,b = 20;
    int sum = 0;
    sum = Add(a,b);
    printf("sum = %d\n",sum);
    printf("hh");
    return 0;
}
