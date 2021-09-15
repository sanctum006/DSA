/*
Given a bitonic array find the the target element.

Example:
Input:
-8 1 2 3 4 5 -2 -3
Output:
1
*/

#include <bits/stdc++.h>
using namespace std;

int findMaxVal(vector<int> nums)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            return nums[mid];
        if (nums[mid] > nums[mid + 1])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int findInAsc(vector<int> nums, int target, int low, int high)
{

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int findInDsc(vector<int> nums, int target, int low, int high)
{

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    vector<int> nums{-8, 1, 2, 3, 4, 5, -2, -3};
    int target = -4;
    int index = findMaxVal(nums);

    cout << max(findInAsc(nums, target, 0, index - 1), findInDsc(nums, target, index, nums.size() - 1)) << endl;

    return 0;
}