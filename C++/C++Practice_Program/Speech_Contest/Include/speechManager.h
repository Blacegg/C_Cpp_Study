#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "../Include/speaker.h"
#include <algorithm>

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
    ~SpeechManager();

    vector<int> v1;
    vector<int> v2;
    vector<int> victory;
    map<int, speaker> m_Speaker;

    int m_Index;
};
