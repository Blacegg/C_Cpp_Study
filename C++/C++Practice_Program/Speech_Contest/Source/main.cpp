#include <iostream>
#include "../Include/speechManager.h"
using namespace std;

int main()
{
    SpeechManager sm;

    int choice = 0;
    while (true)
    {
        sm.Show_Menu();
        cout << "ÇëÊäÈëÄãµÄÑ¡Ôñ£º" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            sm.exitSystem();
            break;
        default:
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}