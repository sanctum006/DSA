/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity. 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

// O(LogN) solution using binary search
int search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;

        // If the left subarray is sorted
        if (nums[start] <= nums[mid])
        {
            // and element lies in left subarray
            if (nums[start] <= target && target <= nums[mid])
                end = mid - 1;
            // else search in right subarray
            else
                start = mid + 1;
        }
        else
        {
            if (nums[mid] <= target && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};

    cout << search(nums, 0);

    return 0;
}