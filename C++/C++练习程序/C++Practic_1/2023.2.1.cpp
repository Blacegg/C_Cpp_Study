#include <iostream>
#include <string>
using namespace std;

/*½á¹¹Ìå°¸Àý2*/
struct Hero
{
    string name;
    int age;
    string gender;
};

void swap_hero(Hero *hero, int x)
{
    string tmp_name = (hero + x)->name;
    (hero + x)->name = (hero + x + 1)->name;
    (hero + x + 1)->name = tmp_name;

    int tmp_age = (hero + x)->age;
    (hero + x)->age = (hero + x + 1)->age;
    (hero + x + 1)->age = tmp_age;

    string tmp_gender = (hero + x)->gender;
    (hero + x)->gender = (hero + x + 1)->gender;
    (hero + x + 1)->gender = tmp_gender;
}

void Print(Hero *heroes, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "Hero name: " << heroes[i].name
             << "  age: " << heroes[i].age
             << "  gender: " << heroes[i].gender << endl;
    }
}

int main()
{
    /*½á¹¹Ìå°¸Àý2*/

    // Hero heroes[5];
    // string names[5] = {"Áõ±¸", "¹ØÓð", "ÕÅ·É", "ÕÔÔÆ", "õõ²õ"};
    // int ages[5] = {23, 22, 20, 21, 19};
    // string genders[5] = {"ÄÐ", "ÄÐ", "ÄÐ", "ÄÐ", "Å®"};

    // for(int i = 0; i < 5; i++)
    // {
    //     heroes[i].name = names[i];
    //     heroes[i].age = ages[i];
    //     heroes[i].gender = genders[i];
    // }

    // Hero heroes[5] =
    //     {
    //         {"Áõ±¸", 23, "ÄÐ"},
    //         {"¹ØÓð", 22, "ÄÐ"},
    //         {"ÕÅ·É", 20, "ÄÐ"},
    //         {"ÕÔÔÆ", 21, "ÄÐ"},
    //         {"õõ²õ", 19, "ÄÐ"}};

    // int len = sizeof(heroes) / sizeof(heroes[0]);
    // Print(heroes, len);
    // cout << endl;

    // for (int i = 0; i < len - 1; i++)
    // {
    //     for (int j = 0; j < len - i - 1; j++)
    //     {
    //         if (heroes[j].age > heroes[j + 1].age)
    //         {
    //             // swap_hero(heroes, j);

    //             Hero temp = heroes[j];
    //             heroes[j] = heroes[j + 1];
    //             heroes[j + 1] = temp;
    //         }
    //     }
    // }

    // Print(heroes, len);

    string a;
    cin >> a;
    cout << a << endl;
}
