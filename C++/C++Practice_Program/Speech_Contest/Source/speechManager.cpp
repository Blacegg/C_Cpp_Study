#include "../Include/speechManager.h"

SpeechManager::SpeechManager()
{
    this->initSpeech();
    this->creatSpeaker();
    this->loadRecord();
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
    this->m_Record.clear();
    this->m_Index = 1;
}

void SpeechManager::creatSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; i++)
    {
        speaker sp;
        sp.m_name = ((string) "选手") + nameSeed[i];
        sp.m_score[0] = 0;
        sp.m_score[1] = 0;
        this->v1.push_back(i + 10001);
        this->m_Speaker.insert(pair<int, speaker>(i + 10001, sp));
    }
}

void SpeechManager::startSpeech()
{
    this->speechDraw();
    this->speechContest();
    this->showScore();
    this->m_Index++;
    this->speechDraw();
    this->speechContest();
    this->showScore();
    this->saveRecord();
    this->loadRecord();
    cout << "本届比赛完毕！" << endl;
    system("pause");
    system("cls");
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
    if (this->m_Index == 1)
    {
        random_shuffle(this->v1.begin(), this->v1.end());
        for_each(this->v1.begin(), this->v1.end(), SpeechManager());
        cout << endl;
    }
    else if (this->m_Index == 2)
    {
        random_shuffle(this->v2.begin(), this->v2.end());
        for_each(this->v2.begin(), this->v2.end(), SpeechManager());
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
    system("pause");
    cout << endl;
}

void SpeechManager::speechContest()
{
    cout << "--------------第 " << this->m_Index << " 轮比赛正式开始--------------" << endl;
    multimap<double, int, greater<double>> groupScore;
    deque<double> d;
    vector<int> v_temp;
    if (this->m_Index == 1)
    {
        v_temp = v1;
    }
    else if (this->m_Index == 2)
    {
        v_temp = v2;
    }
    int num = 1;
    for (vector<int>::iterator it = v_temp.begin(); it != v_temp.end(); it++)
    {

        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.0f;
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        double average_score = accumulate(d.begin(), d.end(), 0) / ((double)d.size());
        groupScore.insert(make_pair(average_score, (*it)));
        this->m_Speaker[*it].m_score[this->m_Index - 1] = average_score;
        if ((num++) % 6 == 0)
        {
            cout << "第 " << this->m_Index << " 轮第 " << (num++) / 6 << " 组比赛结果如下：" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "编号：" << (*it).second
                     << "\t姓名：" << this->m_Speaker[(*it).second].m_name
                     << "\t得分：" << it->first << endl;
            }

            int count = 0;

            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 (it != groupScore.end()) && (count < 3); it++, count++)
            {
                if (this->m_Index == 1)
                {
                    this->v2.push_back(it->second);
                }
                else if (this->m_Index == 2)
                {
                    this->victory.push_back(it->second);
                }
            }
            groupScore.clear();
            cout << endl;
        }
    }
    cout << "--------------第 " << this->m_Index << " 轮比赛结束--------------" << endl;
    system("pause");
}

void SpeechManager::showScore()
{
    cout << "第 " << this->m_Index << " 轮的前三名选手如下：" << endl;
    vector<int> v_temp;
    if (this->m_Index == 1)
    {
        v_temp = this->v2;
    }
    else if (this->m_Index == 2)
    {
        v_temp = this->victory;
    }
    int count = 0;
    for (vector<int>::iterator it = v_temp.begin(); it != v_temp.end(); it++, count++)
    {
        cout << "第 " << count + 1 << " 名：\t"
             << "编号：" << (*it)
             << "\t姓名：" << this->m_Speaker[*it].m_name
             << "\t得分：" << this->m_Speaker[*it].m_score[this->m_Index - 1] << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);
    for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
    {
        ofs << (*it) << ","
            << this->m_Speaker[*it].m_score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "记录已保存" << endl;
    this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
    ifstream ifs;
    ifs.open("speech.csv", ios::in);

    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空！" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    this->fileIsEmpty = false;
    ifs.putback(ch);

    string data;
    int index = 0;
    while (ifs >> data)
    {
        vector<string> v;
        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1)
            {
                break;
            }
            v.push_back(data.substr(start, pos - start));
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
}

void SpeechManager::showRecord()
{
    if (this->fileIsEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < (this->m_Record.size()); i++)
        {
            cout << "第 " << i + 1 << " 届" << endl;
            cout << "冠军：\t编号：" << this->m_Record[i][0] << "\t得分：" << this->m_Record[i][1] << endl;
            cout << "亚军：\t编号：" << this->m_Record[i][2] << "\t得分：" << this->m_Record[i][3] << endl;
            cout << "冠军：\t编号：" << this->m_Record[i][4] << "\t得分：" << this->m_Record[i][5] << endl;
            cout << endl;
        }
    }

    system("pause");
    system("cls");
}

void SpeechManager::clearRecord()
{
    cout << "确认清空所有记录？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        this->loadRecord();
        cout << "成功清空所有记录！" << endl;
    }
    system("pause");
    system("cls");
}
