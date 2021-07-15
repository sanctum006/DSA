/*Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
*/

#include <bits/stdc++.h>

using namespace std;

// O(N) Brute force solution
// vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

//         vector<int> result;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             int count = 0;

//             for (int j = 0; j < nums.size(); j++)
//             {
//                 if (nums[j] < nums[i])
//                     count++;
//             }

//             result.push_back(count);
//         }

//         return result;
//     }

// O(NLogN) solution using sorting and hashmap
// vector<int> smallerNumbersThanCurrent(vector<int> &nums)
// {
//     vector<int> arr(nums.begin(), nums.end());
//     sort(arr.begin(), arr.end());
//     unordered_map<int, int> m;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (m.count(arr[i]) == 0)
//             m[arr[i]] = i;
//     }

//     vector<int> result;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         result.push_back(m[nums[i]]);
//     }

//     return result;
// }

// O(N) time solution using a hashmap
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{

    int count[101] = {0};

    for (int i = 0; i < nums.size(); i++)
        count[nums[i]]++;

    for (int i = 1; i < 101; i++)
        count[i] += count[i - 1];

    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            ans.push_back(0);
        else
            ans.push_back(count[nums[i] - 1]);
    }

    return ans;
}

int main()
{
    vector<int> nums{8, 1, 2, 2, 3};
    vector<int> res = smallerNumbersThanCurrent(nums);

    for (int i = 0; i < res.size(); i++)
        cout << nums[i] << " ";

    return 0;
}