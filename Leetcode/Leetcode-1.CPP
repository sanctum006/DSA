/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include <bits/stdc++.h>
using namespace std;

// O(N^2) solution using nested loops
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//             if (nums[i] + nums[j] == target)
//                 return {i, j};
//     }

//     return {};
// }

// O(N) time (two pass) and O(N) space using hashmap
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     unordered_map<int, int> m;

//     for (int i = 0; i < nums.size(); i++)
//         m[nums[i]] = i;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (m.count(target - nums[i]) != 0 && m[target - nums[i]] != i)
//             return {i, m[target - nums[i]]};
//     }

//     return {};
// }

// O(N) time and O(N) space single pass solution
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        if (m.count(target - nums[i]) != 0)
            return {i, m[target - nums[i]]};
        m[nums[i]] = i;
    }

    return {};
}

// Driver Function
int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    for (auto it : ans)
        cout << it << " ";

    return 0;
}