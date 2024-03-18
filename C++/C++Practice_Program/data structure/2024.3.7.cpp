#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void reverseString(vector<char> &s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left++ < right--)
    {
        swap(s[left], s[right]);
    }
}

string reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i += (2 * k))
    {
        if (i + k < s.size())
            reverse(s.begin() + i, s.begin() + i + k);
        else
            reverse(s.begin() + i, s.end());
    }
    return s;
}

string replaceStr(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            s.replace(i, 1, "number");
        }
    }
    return s;
}

string removeExtraSpace(string s)
{
#if 0
    int fast = 0;
    int slow = 0;
    for (; fast < s.size(); fast++)
    {
        if (s[fast] != ' ')
        {
            // if (slow != 0)
            {
                while (fast < s.size() && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                }
                s[slow++] = ' ';
            }
        }
    }
    s.resize(slow - 1);
#else
    int slow = 0; // 整体思想参考https://programmercarl.com/0027.移除元素.html
    for (int i = 0; i < s.size(); ++i)
    { //
        if (s[i] != ' ')
        { // 遇到非空格就处理，即删除所有空格。
            if (slow != 0)
                s[slow++] = ' '; // 手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
            while (i < s.size() && s[i] != ' ')
            { // 补上该单词，遇到空格说明单词结束。
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow); // slow的大小即为去除多余空格后的大小。
#endif

    return s;
}

string swapword(string s, int begin, int end)
{
    while (begin < end)
    {
        swap(s[begin], s[end]);
        begin++;
        end--;
    }
    return s;
}

string reverseWords(string s)
{
    s = removeExtraSpace(s);
    s = swapword(s, 0, s.size() - 1);
    for (int i = 0, j = 0; i <= s.size(); ++i)
    {
        if ((s[i] == ' ') || (i == s.size()))
        {
            s = swapword(s, j, i - 1);
            j = i + 1;
        }
    }
    return s;
}

string halfswap(string s, int n)
{
    s = swapword(s, 0, s.size() - 1);
    s = swapword(s, 0, n - 1);
    s = swapword(s, n, s.size() - 1);
    return s;
}

vector<int> getNext(string s)
{
#if 0
    vector<int> v(s.size(), 0);
    for (int i = 0; i < s.size(); i++)
    {

        for (int j = 0; j < i; j++)
        {
            int left = 0;
            int right = i - 1 - j;
            while ((left < right) && s[left] == s[right] && right < i)
            {
                left++;
                right++;
            }
            if (right == i)
                v[i] = j + 1;
        }
    }
    return v;
#else
    vector<int> v(s.size(), 0);
    int j = 0;
    for (int i = 2; i < s.size(); i++)
    {

        while (s[i - 1] != s[j])
        {
            if (j == 0)
                break;
            j = v[j];
        }
        if (s[i - 1] == s[j])
        {
            j++;
        }
        v[i] = j;
    }
    return v;
#endif
}

int strStr(string haystack, string needle)
{
    int j = 0;
    int i = 0;
    vector<int> next = getNext(needle);
    for (; i < haystack.size() && j < needle.size(); i++)
    {
        if (haystack[i] == needle[j])
        {
            j++;
        }
        else
        {
            if (j != 0)
                i--;
            j = next[j];
        }
    }
    if (j == needle.size())
        return i - j;
    return -1;
}

bool repeatedSubstringPattern(string s)
{
    string t = s + s;
    t.erase(t.begin(), t.begin() + 1);
    t.erase(t.end() - 1, t.end());
    int a = strStr(t, s);
    if (a >= 0)
        return true;
    return false;
}

int main()
{
    vector<int> v;
    string l = "aabaacaabaaf";
    string s = "aabaaf";
    // v = getNext(s);
    cout << strStr(l, s) << endl;
    return 0;
}
