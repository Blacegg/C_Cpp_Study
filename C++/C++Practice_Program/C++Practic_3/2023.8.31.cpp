#include <iostream>
using namespace std;

class father
{
public:
    int a;

protected:
    int b;

private:
    int c;
};

class son1 : public father
{
public:
    int son_a;
};

class son2 : protected father
{
public:
    int son_b;
};

class son3 : private father
{
public:
    int son_c;
};

class animal
{
public:
    int age;
};

int main()
{
    return 0;
}