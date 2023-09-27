#include <stdio.h>

int arr[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
int arr1[3] = {10, 22, 34};
void test(int *arr)
{
    printf("%d\n", arr[0]);
}
void test(int *arr, int a)
{
    printf("%d\n", arr[1]);
}

char a = 0x31;
int main()
{
    // test(arr1, 3);
    //  printf("%d\n", &arr);
    //  printf("%d\n", (&arr) + 1);
    char a = 5;
    char b = 126;
    char c = a + b;
    printf("%c\n", c);

    return 0;
}