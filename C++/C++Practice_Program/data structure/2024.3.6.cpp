#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool isHappy(int n)
{
    bool ret = true;
    unordered_set<int> record;
    int sum = 0;
    record.insert(n);

    while (n != 1)
    {
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        if (record.find(sum) == record.end())
        {
            record.insert(sum);
        }
        else
        {
            ret = false;
            break;
        }
        n = sum;
        sum = 0;
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

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        auto other = mp.find(target - nums[i]);
        if (other != mp.end())
        {
            return {other->second, i};
        }
        mp.insert(pair<int, int>(nums[i], i));
    }
    return {};
}

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> unmp;
    for (int num1 : nums1)
    {
        for (int num2 : nums2)
        {
            unmp[num1 + num2]++;
        }
    }
    int count = 0;
    for (int num3 : nums3)
    {
        for (int num4 : nums4)
        {
            auto it = unmp.find(0 - (num3 + num4));
            if (it != unmp.end())
            {
                count += it->second;
            }
        }
    }
    return count;
}

bool canConstruct(string ransomNote, string magazine)
{
#if 0
    unordered_map<char, int> mp;
    for (char a : ransomNote)
    {
        mp[a]++;
    }
    for (char b : magazine)
    {
        if (mp.find(b) != mp.end())
        {
            mp[b]--;
        }
    }
    for (pair<char, int> p : mp)
    {
        if (p.second > 0)
            return false;
    }
    return true;
#else
    int arr[26] = {0};
    for (char a : ransomNote)
    {
        arr[a - 'a']++;
    }
    for (char b : magazine)
    {
        arr[b - 'a']--;
    }
    for (int a : arr)
    {
        if (a > 0)
            return false;
    }
    return true;

#endif
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> v;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum > 0)
                right--;
            else if (sum < 0)
                left++;
            else
            {
                v.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                left++;
                right--;
            }
        }
    }
    return v;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > target && nums[i] >= 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] + nums[i] > target && nums[j] + nums[i] >= 0)
                break;
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                long sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else
                {
                    ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
    }
    return ret;
}

int main()
{
    // vector<int> v1 = {1, 2};
    // vector<int> v2 = {-2, -1};
    // vector<int> v3 = {-1, 2};
    // vector<int> v4 = {0, 2};
    // cout << fourSumCount(v1, v2, v3, v4) << endl;
    // string a = "ab";
    // string b = "aab";
    // cout << canConstruct(a, b) << endl;

    vector<int> v = {2, 2, 2, 2, 2};
    fourSum(v, 8);
    return 0;
}