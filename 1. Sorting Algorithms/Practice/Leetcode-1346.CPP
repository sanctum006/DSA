/*
Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
*/

#include <bits/stdc++.h>
using namespace std;

// O(N^2) time solution using nested loop
// bool checkIfExist(vector<int> &nums)
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if ((nums[i] == 2 * nums[j]) || (2 * nums[i] == nums[j]))
//                 return true;
//         }
//     }

//     return false;
// }

// O(NLogN) solution using binary search
// bool binarySearch(vector<int> &nums, int index, int target)
// {
//     int start = index + 1, end = nums.size() - 1;

//     while (start <= end)
//     {
//         int mid = (start + end) / 2;

//         if (nums[mid] == target)
//             return true;
//         else if (nums[mid] > target)
//             end = mid - 1;
//         else
//             start = mid + 1;
//     }

//     return false;
// }

// bool checkIfExist(vector<int> &nums)
// {

//     sort(nums.begin(), nums.end());

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if ((nums[i] % 2 == 0) && (nums[i] < 0) && binarySearch(nums, i, nums[i] / 2))
//         {
//             return true;
//         }
//         else if (binarySearch(nums, i, nums[i] * 2))
//         {
//             return true;
//         }
//     }

//     return false;
// }

// O(N) solution using unordered map
bool checkIfExist(vector<int> &nums)
{
    unordered_map<int, int> m;

    for (auto it : nums)
    {
        if ((it % 2 == 0 && m.count(it / 2)) || (m.count(2 * it)))
            return true;
        m[it]++;
    }

    return false;
}

int main()
{
    vector<int> nums{10, 2, 5, 3};
    cout << checkIfExist(nums) << endl;

    return 0;
}