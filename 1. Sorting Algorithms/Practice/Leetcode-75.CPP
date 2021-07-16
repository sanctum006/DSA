/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

#include <bits/stdc++.h>
using namespace std;

// O(N) Solution with two passes
// void sortColors(vector<int> &nums)
// {
//     int arr[] = {0, 0, 0};

//     for (auto it : nums)
//         arr[it]++;

//     nums.clear();

//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < arr[i]; j++)
//             nums.push_back(i);
//     }
// }

// O(N) Solution with single passes

/*
Approach - We take three variables low = 0, mid = 0, high = size_of_array - 1. We assume that all the elements between nums[0...low-1]] = 0 and
nums[low ... mid ... high] = 1 and nums[high+1 ...] = 2. 
*/
void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        switch (nums[mid])
        {
            // For case 0 we increament both mid and low as for both on same position, it will get stuck in a infinite loop and if both are at
            // different positions it wont make a differece as all the inbetween elements are 1 so nums[mid] will become 1.
        case 0:
            swap(nums[mid++], nums[low++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(nums[mid], nums[high--]);
            break;
        }
    }
}

int main()
{

    vector<int> nums{2, 0, 2, 1, 1, 0};
    sortColors(nums);

    for (auto it : nums)
        cout << it << " ";

    return 0;
}