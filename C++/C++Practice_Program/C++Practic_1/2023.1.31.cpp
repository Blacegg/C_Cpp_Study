#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*冒泡排序*/
void swap_arr(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                int temp = *(a + j + 1);
                *(a + j + 1) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}

int main()
{
#if 0
    /*常量指针——可以修改指向，但不可修改数值*/
    int a = 10, b = 20;
    const int *p = &a;
    cout << "*p=" << *p << endl;
    p = &b;
    cout << "*p=" << *p << endl;
#endif

#if 0
    /*封装一个函数，利用冒泡排序，实现对整型数组的升序排序
    例如数组：int arr[10] = {4,3,6,9,1,2,10,8,7,5}*/

    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    swap_arr(arr, size_arr);
    for (int i = 0; i < size_arr; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
#endif

#if 1
    /*结构体案例1*/

    /*随机数种子*/
    srand((unsigned int)time(NULL));

    struct student
    {
        string name;
        int score;
    };

    struct teacher
    {
        string name;
        student stus[5];
    };

    teacher teas[3];
    string num = "ABCDE";
    for (int i = 0; i < 3; i++)
    {
        teas[i].name = "teacher_";
        teas[i].name += num[i];

        for (int j = 0; j < 5; j++)
        {
            teas[i].stus[j].name = "student_";
            teas[i].stus[j].name += num[j];

            int random = rand() % 61 + 40;
            teas[i].stus[j].score = random;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "老师" << i + 1 << "的姓名:" << teas[i].name << endl;

        for (int j = 0; j < 5; j++)
        {
            cout << "\t老师" << i + 1 << "的第" << j + 1 << "个学生姓名：" << teas[i].stus[j].name
                 << " 成绩：" << teas[i].stus[j].score << endl;
        }
    }
#endif
}