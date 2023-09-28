#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

struct People
{
    string name;
    int age;
    int sex;
    string Phone;
    string Address;
};

struct Contact
{
    People people[MAX];
    int num;
};

void menu(void);
void Contact_Init(Contact *contact);
void Add_People(Contact *contact);
void Print_Contact(Contact *contact);
void Delect_People(Contact *contact);
void Find_People(Contact *contact);
void Revise_People(Contact *contact);
void Empty_Contact(Contact *contact);