#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>

class MyQueue
{
private:
    stack<int> instack;
    stack<int> outstack;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        instack.push(x);
    }

    int pop()
    {
        if (outstack.empty())
        {
            while (!instack.empty())
            {
                outstack.push(instack.top());
                instack.pop();
            }
        }
        int ret = outstack.top();
        outstack.pop();
        return ret;
    }

    int peek()
    {
        if (outstack.empty())
        {
            while (!instack.empty())
            {
                outstack.push(instack.top());
                instack.pop();
            }
        }
        return outstack.top();
    }

    bool empty()
    {
        if (instack.empty() && outstack.empty())
            return true;
        return false;
    }
};

class MyStack
{
private:
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        for (int i = 1; i < q.size(); i++)
        {
            q.push(q.front());
            q.pop();
        }
        int ret = q.front();
        q.pop();
        return ret;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        return q.empty();
    }
};

bool isValid(string s)
{
    if (s.size() == 0)
        return true;
    if ((s.size()) % 2 != 0)
        return false;
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty() || abs(c - st.top()) > 3)
                return false;
            st.pop();
        }
    }
    if (!st.empty())
        return false;
    return true;
}

string removeDuplicates(string s)
{
#if 0
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty() || st.top() != s[i])
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }
    }
    s.clear();
    while (!st.empty())
    {
        s += st.top();
        st.pop();
    }
    reverse(s.begin(), s.end());
    return s;
#else
    string result;
    for (char c : s)
    {
        if (result.empty() || result.back() != c)
        {
            result.push_back(c);
        }
        else
        {
            result.pop_back();
        }
    }
    return result;
#endif
}

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (string s : tokens)
    {
        if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'))
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (s[0])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(b - a);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(b / a);
                break;
            }
        }
        else
        {
            stringstream geek(s);
            int x;
            geek >> x;
            st.push(x);
        }
    }
    return st.top();
}

int main()
{
    vector<string> v = {"4", "13", "5", "/", "+"};
    evalRPN(v);
    return 0;
}