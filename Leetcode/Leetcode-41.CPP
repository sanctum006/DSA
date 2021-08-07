/*
Given an unsorted integer array nums, find the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:
Input: nums = [1,2,0]
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

// O(N^2) time solution using nested loop
int firstMissingPositive(vector<int> &nums)
{
    int max = INT_MAX;

    for (int i = 1; i < max; i++)
    {
        bool flag = true;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == i)
                flag = false;
        }

        if (flag)
            return i;
    }

    return -1;
}

// O(NLogN) solution using sorting
int firstMissingPositive(vector<int> &nums)
{

    sort(nums.begin(), nums.end());

    int ans = 1;
    int i = 0;

    while (i < nums.size())
    {
        if (nums[i] == ans)
            ans++;
        else if (nums[i] > ans)
            return ans;

        i++;
    }

    return ans;
}

// O(N) time and O(N) space solution using unordered map
int firstMissingPositive(vector<int> &nums)
{
    unordered_map<int, int> m;

    for (auto it : nums)
        m[it]++;

    for (int i = 1; i <= nums.size() + 1; i++)
        if (m.count(i) == 0)
            return i;

    return -1;
}

// O(N) time and O(1) space solution using
// Only works if the array is copied to another array with type long long int
int firstMissingPositive(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
    }

    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != i + 1)
            return i + 1;

    return nums.size() + 1;
}

int main()
{
    vector<int> nums{-10, 5, 4, 1, 3, 9};

    cout << firstMissingPositive(nums) << endl;

    return 0;
}