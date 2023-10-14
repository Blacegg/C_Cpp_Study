#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "../Include/speaker.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>

class SpeechManager
{
public:
    SpeechManager();
    void Show_Menu();
    void exitSystem();
    void initSpeech();
    void creatSpeaker();
    void startSpeech();
    void speechDraw();
    void operator()(int val);
    void speechContest();
    void showScore();
    void saveRecord();
    void loadRecord();
    void showRecord();
    void clearRecord();
    ~SpeechManager();

    vector<int> v1;
    vector<int> v2;
    vector<int> victory;
    map<int, speaker> m_Speaker;
    map<int, vector<string>> m_Record;

    int m_Index;
    bool fileIsEmpty;
};
