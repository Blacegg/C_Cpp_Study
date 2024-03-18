#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <unordered_set>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *CreatList(int *arr, int size)
{
    ListNode *head = NULL;
    for (int i = size - 1; i >= 0; i--)
    {
        head = new ListNode(arr[i], head);
    }
    return head;
}

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};

bool isAnagram(string s, string t)
{
    bool ret = true;
    int record[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        record[s[i] - 'a']++;
    }
    for (int j = 0; j < t.size(); j++)
    {
        record[t[j] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (record[i])
            ret = false;
    }
    return ret;
}

vector<int> array_to_vector(int *arr, int size)
{
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        v.push_back(arr[i]);
    }
    return v;
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> s(nums1.begin(), nums1.end());
    unordered_set<int> t;

    for (int num : nums2)
    {
        if (s.find(num) != s.end())
            t.insert(num);
    }

    return vector<int>(t.begin(), t.end());
}

int main()
{
    int arr[] = {1, 2, 2, 1};
    int arr2[] = {2, 2};
    vector<int> v1 = array_to_vector(arr, sizeof(arr) / sizeof(arr[0]));
    vector<int> v2 = array_to_vector(arr2, sizeof(arr2) / sizeof(arr2[0]));
    vector<int> v = intersection(v1, v2);
    return 0;
}