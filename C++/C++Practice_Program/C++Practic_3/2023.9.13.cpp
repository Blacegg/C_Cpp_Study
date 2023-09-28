#include <iostream>
using namespace std;

template <class T>
void Show(T a);

template <class T>
class abc
{
public:
    T a;
    abc(T a)
    {
        this->a = a;
    }
    friend void Show<>(T a);
};

template <class T>
void Show(T a)
{
    cout << "类外全局函数实现!\t" << a << endl;
}

/*************************************************************************************/

int main()
{
    // Show(3);
    int arr[] = {1, 2, 3, 4, 5, 6};
    
    return 0;
}