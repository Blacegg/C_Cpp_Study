#include "../Include/speechManager.h"

SpeechManager::SpeechManager()
{
    cout << "������һ���ݽ�������" << endl;
}
SpeechManager::~SpeechManager()
{
    cout << "������һ���ݽ�������" << endl;
}

void SpeechManager::Show_Menu()
{
    cout << "**********************************************" << endl;
    cout << "************* ��ӭ�μ��ݽ����� ***************" << endl;
    cout << "*************  1.��ʼ�ݽ�����  ***************" << endl;
    cout << "*************  2.�鿴�����¼  ***************" << endl;
    cout << "*************  3.��ձ�����¼  ***************" << endl;
    cout << "*************  0.�˳���������  ***************" << endl;
    cout << "**********************************************" << endl;
    cout << endl;
}

void SpeechManager::exitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}
