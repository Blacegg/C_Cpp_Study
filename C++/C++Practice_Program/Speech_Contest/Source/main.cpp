#include <iostream>
#include <ctime>
#include "../Include/speechManager.h"
using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    SpeechManager sm;

    int choice = 0;
    while (true)
    {
        sm.Show_Menu();
        cout << "���������ѡ��" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            sm.startSpeech();
            break;
        case 2:
            sm.showRecord();
            break;
        case 3:
            sm.clearRecord();
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