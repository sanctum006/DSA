#include <bits/stdc++.h>
using namespace std;

// O(N) solution using binary search
// vector<int> searchRange(vector<int> &nums, int target)
// {
//     int left = INT_MAX, right = INT_MIN;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == target)
//         {
//             left = min(left, i);
//             right = max(right, i);
//         }
//     }

//     if (left == INT_MAX)
//         left = -1;
//     if (right == INT_MIN)
//         right = -1;

//     return {left, right};
// }

// O(LogN) solution using binary search

int firstBS(vector<int> nums, int target)
{
    int start = 0, end = nums.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (nums[mid] > target)
            end = mid - 1;
        else if (nums[mid] < target)
            start = mid + 1;
    }

    return ans;
}

int lastBS(vector<int> nums, int target)
{
    int start = 0, end = nums.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
            end = mid - 1;
        else if (nums[mid] < target)
            start = mid + 1;
    }

    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return {firstBS(nums, target), lastBS(nums, target)};
}

int main()
{
    vector<int> nums{1, 2, 3, 3, 3, 4};
    auto res = searchRange(nums, 3);

    for (auto it : res)
        cout << it << " ";

    return 0;
}