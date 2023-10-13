#include "../Include/speechManager.h"

SpeechManager::SpeechManager()
{
    this->initSpeech();
    this->creatSpeaker();
}

SpeechManager::~SpeechManager()
{
    cout << "析构了一个演讲管理类" << endl;
}

void SpeechManager::Show_Menu()
{
    cout << "**********************************************" << endl;
    cout << "************* 欢迎参加演讲比赛 ***************" << endl;
    cout << "*************  1.开始演讲比赛  ***************" << endl;
    cout << "*************  2.查看往届记录  ***************" << endl;
    cout << "*************  3.清空比赛记录  ***************" << endl;
    cout << "*************  0.退出比赛程序  ***************" << endl;
    cout << "**********************************************" << endl;
    cout << endl;
}

void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->victory.clear();
    this->m_Speaker.clear();
    this->m_Index = 1;
}

void SpeechManager::creatSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; i++)
    {
        speaker sp;
        sp.m_name = "选手" + nameSeed[i];
        sp.m_score[0] = 0;
        sp.m_score[1] = 0;
        this->v1.push_back(i + 10001);
        this->m_Speaker.insert(pair<int, speaker>(i + 10001, sp));
    }
}

void SpeechManager::startSpeech()
{
    this->speechDraw();
}

void SpeechManager::operator()(int val)
{
    cout << val << " ";
}

void SpeechManager::speechDraw()
{
    cout << "第 " << this->m_Index << " 轮比赛选手正在抽签" << endl;
    cout << "----------------------------------------" << endl;
    cout << "抽签演讲顺序如下：" << endl;
    if(this->m_Index==1)
    {
        random_shuffle(this->v1.begin(), this->v1.end());
        for_each(this->v1.begin(), this->v1.end(), SpeechManager());
        cout << endl;
    }
    else if(this->m_Index==2)
    {
        random_shuffle(this->v2.begin(), this->v2.end());
        for_each(this->v2.begin(), this->v2.end(), SpeechManager());
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
    system("pause");
    cout << endl;
}
