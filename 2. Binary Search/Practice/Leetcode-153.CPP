#include <bits/stdc++.h>
using namespace std;

// O(N) solution using linear search
// int findMin(vector<int> nums)
// {
//     int ans = 0;
//     int min_ele = INT_MAX;

//     for (int i = 0; i < nums.size(); i++)
//         if (nums[i] < min_ele)
//         {
//             min_ele = nums[i];
//             ans = i;
//         }

//     return ans;
// }

// O(LogN) solution using binary search
int findMin(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    int n = nums.size();

    while (start <= end)
    {
        // This statement is to return the smallest from the subarray as there might be any case for which
        // the correct mid gets slipped Ex. [4,5,6,7,0,1,2]

        if (nums[start] <= nums[end])
            return nums[start];

        int mid = start + (end - start) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (nums[prev] >= nums[mid] && nums[mid] <= nums[next])
            return nums[mid];
        else if (nums[start] <= nums[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> nums{2, 3, 4, 5, 1};

    cout << findMin(nums) << endl;

    return 0;
}