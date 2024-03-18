#include <iostream>
using namespace std;
#include <stack>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        if (root == NULL)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *nod = st.top();
            st.pop();
            result.push_back(nod->val);
            if (nod->right != NULL)
            {
                st.push(nod->right);
            }
            if (nod->left != NULL)
            {
                st.push(nod->left);
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != NULL || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }

    TreeNode *CreateTree(vector<int> &nums)
    {
        if (nums.empty())
            return NULL;
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(nums[0]);
        TreeNode *cur = root;
        q.push(root);
        for (int i = 1; (!q.empty()) && (i < nums.size()); i++)
        {
            cur = q.front();
            q.pop();
            if (i < nums.size())
            {
                if (nums[i] == -1)
                {
                    cur->left = NULL;
                    i++;
                }
                else
                {
                    cur->left = new TreeNode(nums[i++]);
                    q.push(cur->left);
                }
            }
            if (i < nums.size())
            {
                if (nums[i] == -1)
                {
                    cur->right = NULL;
                    i++;
                }
                else
                {
                    cur->right = new TreeNode(nums[i]);
                    q.push(cur->right);
                }
            }
        }
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, -1, 2, 3};
    TreeNode *tree = s.CreateTree(v);
    s.inorderTraversal(tree);
    return 0;
}