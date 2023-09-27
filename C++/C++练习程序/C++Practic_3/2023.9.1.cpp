#include <iostream>
using namespace std;

class animal
{
public:
    virtual void speak(void)
    {
        cout << "animal speaking" << endl;
    }
};

class cat : public animal
{
public:
    void speak(void)
    {
        cout << "cat speaking" << endl;
    }
};

void do_speak(animal &animal)
{
    animal.speak();
}

void do_speak2(cat &cat)
{
    cat.speak();
}
int main()
{
    cat smallcat;
    animal smallanimal;
    do_speak(smallcat);
    do_speak(smallanimal);
    int a = 10;
    cout << "a = " << a << endl;
    // do_speak2(smallanimal);
    return 0;
}