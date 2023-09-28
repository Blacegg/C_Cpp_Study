#include <iostream>
using namespace std;
#include <ctime>

void Bubble_Sort(int *arr, int size)
{

    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}

void Bubble_Sort2(int *arr, int size)
{

    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
            }
        }
    }
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}

int main()
{
    cout << "hello world" << endl;
    int arr[10] = {5, 8, 3, 4, 0, 9, 7, 1, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Bubble_Sort2(arr, size);
    /*产生随机数种子*/
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int random = rand() % 61 + 40;
        cout << random << "\t";
    }

    return 0;
}