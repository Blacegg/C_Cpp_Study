#include <iostream>
using namespace std;
#include <queue>

class Myqueue
{
private:
    deque<int> deq;

public:
    Myqueue() {}

    void pop(int value)
    {
        if (!deq.empty() && deq.front() == value)
        {
            deq.pop_front();
        }
    }

    void push(int value)
    {
        while (!deq.empty() && deq.back() < value)
        {
            deq.pop_back();
        }
        deq.push_back(value);
    }

    int front()
    {
        return deq.front();
    }

    int size()
    {
        return deq.size();
    }
};

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{

#if 1
    Myqueue m;
    vector<int> v;
    for (int i = 0; i < k; i++)
    {
        m.push(nums[i]);
    }
    v.push_back(m.front());
    for (int i = k; i < nums.size(); i++)
    {
        m.pop(nums[i - k]);
        m.push(nums[i]);
        v.push_back(m.front());
    }
    return v;
#else
    Myqueue que;
    vector<int> result;
    for (int i = 0; i < k; i++)
    { // 先将前k的元素放进队列
        que.push(nums[i]);
    }
    result.push_back(que.front()); // result 记录前k的元素的最大值
    for (int i = k; i < nums.size(); i++)
    {
        que.pop(nums[i - k]);          // 滑动窗口移除最前面元素
        que.push(nums[i]);             // 滑动窗口前加入最后面的元素
        result.push_back(que.front()); // 记录对应的最大值
    }
    return result;
#endif
}

int main()
{
    vector<int> v = {1};
    vector<int> k = maxSlidingWindow(v, 1);
    return 0;
}