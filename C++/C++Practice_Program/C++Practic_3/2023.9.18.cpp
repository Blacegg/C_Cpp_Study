#include <iostream>
using namespace std;
#include <deque>
#include <vector>
#include <string>

void PrintDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// - deque<T> deqT;           // 默认构造形式
// - deque(beg, end);         // 构造函数将[beg, end)区间中的元素拷贝给本身。
// - deque(n, elem);          // 构造函数将n个elem拷贝给本身。
// - deque(const deque &deq); // 拷贝构造函数

void test1()
{
    deque<int> deqT1;

    for (int i = 0; i < 10; i++)
    {
        deqT1.push_front(i);
    }
    cout << "deqT1:" << endl;
    PrintDeque(deqT1);

    // deque<int> deqT2(deqT1.begin(), deqT1.end());
    // cout << "deqT2:" << endl;
    // PrintDeque(deqT2);

    deque<int> deqT2(deqT1.end(), deqT1.begin());
    cout << "deqT2:" << endl;
    PrintDeque(deqT2);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int process(int *cur, int index, int flag, vector<vector<int>> &dp)
{
    if (dp[index][flag] != -1)
    {
        return dp[index][flag];
    }

    if (cur[2 * index + 1] == -1 && cur[2 * index + 2] == -1)
    {
        dp[index][flag] = flag == 1 ? cur[index] : 0;
    }
    else
    {
        int l = 0, r = 0;
        // 这里报错，当两个if单独运行时，不会报错
        // 当两个if同时运行时，就会报错：AddressSanitizer: heap-use-after-free on address
        if (cur[2 * index] != -1)
        {
            l = process(cur, 2 * index + 1, 0, dp);
            if (flag == 0)
            {
                l = max(l, process(cur, 2 * index + 1, 1, dp));
            }
        }
        if (cur[2 * index + 2] != -1)
        {
            r = process(cur, 2 * index + 2, 0, dp);
            if (flag == 0)
            {
                r = max(r, process(cur, 2 * index + 2, 1, dp));
            }
        }
        dp[index][flag] = flag == 1 ? l + r + cur[index] : l + r;
    }
    return dp[index][flag];
}

// int rob(TreeNode *root)
// {
//     vector<vector<int>> dp(20, vector<int>(2, -1));
//     int c1 = process(root, 0, 0, dp);
//     int c2 = process(root, 0, 1, dp);
//     return max(c1, c2);
// }

void test2()
{
    TreeNode T4(4);
    TreeNode T5(5);
    TreeNode T2(2, &T4, &T5);
    TreeNode T6(6);
    TreeNode T7(7);
    TreeNode T3(3, &T6, &T7);
    TreeNode T1(1, &T2, &T3);
    // int a = rob(&T1);
    // cout << a << endl;
}
// #define null -1
// void test3()
// {
//     int arr[] = {79, 99, 77, null, null, null, 69, null, 60, 53, null, 73, 11, null, null, null, 62, 27, 62, null, null, 98, 50, null, null, 90, 48, 82, null, null, null, 55, 64, null, null, 73, 56, 6, 47, null, 93, null, null, 75, 44, 30, 82, null, null, null, null, null, null, 57, 36, 89, 42, null, null, 76, 10, null, null, null, null, null, 32, 4, 18, null, null, 1, 7, null, null, 42, 64, null, null, 39, 76, null, null, 6, null, 66, 8, 96, 91, 38, 38, null, null, null, null, 74, 42, null, null, null, 10, 40, 5, null, null, null, null, 28, 8, 24, 47, null, null, null, 17, 36, 50, 19, 63, 33, 89, null, null, null, null, null, null, null, null, 94, 72, null, null, 79, 25, null, null, 51, null, 70, 84, 43, null, 64, 35, null, null, null, null, 40, 78, null, null, 35, 42, 98, 96, null, null, 82, 26, null, null, null, null, 48, 91, null, null, 35, 93, 86, 42, null, null, null, null, 0, 61, null, null, 67, null, 53, 48, null, null, 82, 30, null, 97, null, null, null, 1, null, null};
//     vector<vector<int>> dp(20000, vector<int>(2, -1));
//         int c1 = process(arr, 0, 0, dp);
//         int c2 = process(arr, 0, 1, dp);
//         cout << max(c1, c2) << endl;
// }

// - deque.empty();     // 判断容器是否为空
// - deque.size();      // 返回容器中元素的个数
// - deque.resize(num); // 重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
//                      // 如果容器变短，则末尾超出容器长度的元素被删除。
// - deque.resize(num, elem); // 重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
//                            // 如果容器变短，则末尾超出容器长度的元素被删除。

void test4()
{
    deque<int> d1;
    bool isempty = d1.empty();
    cout << isempty << endl;

    for (int i = 0; i < 10; i++)
    {
        d1.push_front(i);
    }
    isempty = d1.empty();
    cout << isempty << endl;
    // cout << (string)((isempty == true) ? "d1为空" : "d1不为空") << endl;
    PrintDeque(d1);

    int dsize = d1.size();
    cout << "长度为" << dsize << endl;

    d1.resize(15);
    PrintDeque(d1);
    dsize = d1.size();
    cout << "长度为：" << dsize << endl;

    d1.resize(18, 6);
    PrintDeque(d1);
    dsize = d1.size();
    cout << "长度为：" << dsize << endl;
}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}