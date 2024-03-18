#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++)
    {
        if (nums[fast] != val)
        {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int main()
{
    vector<int> v = {3, 2, 2, 3};
    removeElement(v, 2);
    return 0;
}