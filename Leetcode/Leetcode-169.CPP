#include <bits/stdc++.h>
using namespace std;

// O(N^2) solution choosing each element and counting its frequency

// int majorityElement(vector<int> &nums)
// {
//     int majCou = nums.size() / 2;

//     for (auto it : nums)
//     {
//         int count = 0;

//         for (int ele : nums)
//             if (ele == it)
//                 count += 1;

//         if (count > majCou)
//             return it;
//     }

//     return 0;
// }

// O(N) solution using hashmap
// int majorityElement(vector<int> &nums)
// {
//     unordered_map<int, int> m;

//     for (auto it : nums)
//         m[it]++;

//     int maxCount = 0, maxEle = 0;

//     for (auto it : m)
//     {
//         if (it.second > maxCount)
//         {
//             maxCount = it.second;
//             maxEle = it.first;
//         }
//     }

//     return maxEle;
// }

// O(N) with O(1) space
int majorityElement(vector<int> &nums)
{
    int count = 0, element = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            element = nums[i];
            count = 1;
        }
        else if (element == nums[i])
            count++;
        else
            count--;
    }
    return element;
}

int main()
{
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};

    cout << majorityElement(nums) << endl;

    return 0;
}