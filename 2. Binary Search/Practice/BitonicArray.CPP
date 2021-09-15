/*
Given a bitonic array find the maximum value of the array. An array is said to be bitonic if it has an
increasing sequence of integers followed immediately by a decreasing sequence of integers.

Example:
Input:
1 4 8 3 2
Output:
8
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

int main()
{
    vector<int> nums{1, 4, 8, 3, 2, 1, 0};
    cout << findMaxVal(nums) << endl;

    return 0;
}