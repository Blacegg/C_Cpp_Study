#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

class Solution1
{
public:
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int> &in1, const pair<int, int> &in2)
        {
            return in1.second > in2.second;
        }
    };

    vector<int> heapsort(vector<int> &nums)
    {
        priority_queue<int, vector<int>> pque(nums.begin(), nums.end());
        // priority_queue<int, vector<int>> pque;
        // for (int a : nums)
        // {
        //     pque.push(a);
        // }
        int size = pque.size();
        vector<int> result(size);
        for (int i = 0; i < size; i++)
        {
            result[i] = pque.top();
            pque.pop();
        }
        return result;
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> unmp;
        for (int i = 0; i < nums.size(); i++)
        {
            unmp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pque;
        for (unordered_map<int, int>::iterator it = unmp.begin(); it != unmp.end(); it++)
        {
            pque.push(*it);
            if (pque.size() > k)
            {
                pque.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pque.top().first;
            pque.pop();
        }
        return result;
    }
};

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : value(0), left(NULL), right(NULL) {}
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
#if 0
        vector<int> v;
        if (root == NULL)
        {
            return {};
        }
        v.push_back(root->value);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        v.insert(v.end(), left.begin(), left.end());
        v.insert(v.end(), right.begin(), right.end());
        return v;
#else
        vector<int> v;

        return v;

#endif
    }
};

int main()
{
    vector<int> v = {49, 38, 65, 97, 76, 13, 27, 49};
    Solution s;
    // s.topKFrequent(v, 2);
    //v = s.heapsort(v);
    return 0;
}