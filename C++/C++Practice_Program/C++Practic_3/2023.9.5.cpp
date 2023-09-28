/***********************************************************************
 * @file 2023.9.5.cpp
 * @brief
 * @author your name (you@domain.com)
 * @version 0.1
 * @date 2023-09-05
 ***********************************************************************/
#include <iostream>
using namespace std;

class people
{
public:
    virtual void speak(people &people)
    {
        cout << "people speak" << endl;
    }
};

class man : public people
{
public:
    void speak(man &man)
    {
        cout << "man speak" << endl;
    }
};

void do_speak(people &people)
{
    people.speak(people);
}
/***********************************************************************
 * @brief
 * @param  a:
 * @param  b:
 * @return int:
 ***********************************************************************/
int add(int a, int b)
{
    return a + b;
}
int main()
{
    people p;
    man m;
    do_speak(m);
    return 0;
}