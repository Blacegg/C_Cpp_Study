#include "../Include/speechManager.h"

SpeechManager::SpeechManager()
{
    this->initSpeech();
    this->creatSpeaker();
    this->loadRecord();
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
        sp.m_name = ((string) "ѡ��") + nameSeed[i];
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
    cout << "���������ϣ�" << endl;
    system("pause");
    system("cls");
}

void SpeechManager::operator()(int val)
{
    cout << val << " ";
}

void SpeechManager::speechDraw()
{
    cout << "�� " << this->m_Index << " �ֱ���ѡ�����ڳ�ǩ" << endl;
    cout << "----------------------------------------" << endl;
    cout << "��ǩ�ݽ�˳�����£�" << endl;
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
    cout << "--------------�� " << this->m_Index << " �ֱ�����ʽ��ʼ--------------" << endl;
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
            cout << "�� " << this->m_Index << " �ֵ� " << (num++) / 6 << " �����������£�" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "��ţ�" << (*it).second
                     << "\t������" << this->m_Speaker[(*it).second].m_name
                     << "\t�÷֣�" << it->first << endl;
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
    cout << "--------------�� " << this->m_Index << " �ֱ�������--------------" << endl;
    system("pause");
}

void SpeechManager::showScore()
{
    cout << "�� " << this->m_Index << " �ֵ�ǰ����ѡ�����£�" << endl;
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
        cout << "�� " << count + 1 << " ����\t"
             << "��ţ�" << (*it)
             << "\t������" << this->m_Speaker[*it].m_name
             << "\t�÷֣�" << this->m_Speaker[*it].m_score[this->m_Index - 1] << endl;
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
    cout << "��¼�ѱ���" << endl;
    this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
    ifstream ifs;
    ifs.open("speech.csv", ios::in);

    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "�ļ������ڣ�" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ�գ�" << endl;
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
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < (this->m_Record.size()); i++)
        {
            cout << "�� " << i + 1 << " ��" << endl;
            cout << "�ھ���\t��ţ�" << this->m_Record[i][0] << "\t�÷֣�" << this->m_Record[i][1] << endl;
            cout << "�Ǿ���\t��ţ�" << this->m_Record[i][2] << "\t�÷֣�" << this->m_Record[i][3] << endl;
            cout << "�ھ���\t��ţ�" << this->m_Record[i][4] << "\t�÷֣�" << this->m_Record[i][5] << endl;
            cout << endl;
        }
    }

    system("pause");
    system("cls");
}

void SpeechManager::clearRecord()
{
    cout << "ȷ��������м�¼��" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();
        this->loadRecord();
        cout << "�ɹ�������м�¼��" << endl;
    }
    system("pause");
    system("cls");
}
