/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

// O(NLogN) solution using binary search
int findSmallOrEqual(vector<int> &nums, int curr)
{
    int count = 0;

    for (auto it : nums)
        if (it <= curr)
            count++;

    return count;
}

int findDuplicate(vector<int> &nums)
{

    int low = 1, high = nums.size();
    int duplicate = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (findSmallOrEqual(nums, mid) > mid)
        {
            duplicate = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return duplicate;
}

int main()
{
    vector<int> nums{1, 3, 4, 2, 2};

    cout << findDuplicate(nums) << endl;

    return 0;
}