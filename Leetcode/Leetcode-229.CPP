/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Follow-up: Could you solve the problem in linear time and in O(1) space?

Example 1:
Input: nums = [3,2,3]
Output: [3]
*/

#include <bits/stdc++.h>
using namespace std;
// vector<int> majorityElement(vector<int> &nums)
// {
//     vector<int> res;
//     set<int> s;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         int count = 0;

//         for (int j = 0; j < nums.size(); j++)
//         {
//             if (nums[i] == nums[j])
//                 count++;
//         }

//         if (count > nums.size() / 3)
//             s.insert(nums[i]);
//     }

//     for (auto it : s)
//         res.push_back(it);

//     return res;
// }

// vector<int> majorityElement(vector<int> &nums)
// {
//     vector<int> res;

//     sort(nums.begin(), nums.end());

//     int element = 0, count = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (element != nums[i])
//         {
//             if (count > nums.size() / 3)
//                 res.push_back(element);
//             element = nums[i];
//             count = 0;
//         }

//         count++;
//     }

//     if (count > nums.size() / 3)
//         res.push_back(element);
//     return res;
// }

// O(N) time with O(N) space time solution with unordered map

// O(N) time with O(N) space time solution with unordered map
// vector<int> majorityElement(vector<int> &nums)
// {
//     vector<int> res;
//     unordered_map<int, int> m;

//     for (int i = 0; i < nums.size(); i++)
//         m[nums[i]]++;

//     for (auto it : m)
//     {
//         if (it.second > nums.size() / 3)
//             res.push_back(it.first);
//     }

//     return res;
// }

// O(N) time with O(1) space solution using Boyer Moore Algorithm

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> res;

    int count1 = 0, count2 = 0, element1 = 0, element2 = 0;

    for (auto it : nums)
    {
        // First check for elements then increament count as it might happen that
        // the count of same element get split into two Ex. [2,1,1,3,1,4,5,6]
        if (it == element1)
            count1++;
        else if (it == element2)
            count2++;
        else if (count1 == 0)
        {
            element1 = it;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            element2 = it;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;

    for (auto it : nums)
        if (element1 == it)
            count1++;
        else if (element2 == it)
            count2++;

    if (count1 > nums.size() / 3)
        res.push_back(element1);
    if (count2 > nums.size() / 3)
        res.push_back(element2);

    return res;
}

int main()
{
    vector<int> nums{3, 2, 3};
    nums = majorityElement(nums);
    for (auto it : nums)
        cout << it << " ";

    return 0;
}