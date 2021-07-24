/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
*/

#include <bits/stdc++.h>
using namespace std;

// O(M + N) time and O(M + N) space solution using merge sort
// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
// {
//     vector<int> nums;

//     int i = 0, j = 0;

//     while (i < nums1.size() && j < nums2.size())
//     {
//         if (nums1[i] < nums2[j])
//             nums.push_back(nums1[i++]);
//         else
//             nums.push_back(nums2[j++]);
//     }

//     while (i < nums1.size())
//     {
//         nums.push_back(nums1[i++]);
//     }

//     while (j < nums2.size())
//     {
//         nums.push_back(nums2[j++]);
//     }

//     if (nums.size() % 2 == 0)
//         return double(nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;

//     return nums[(nums1.size() + nums2.size()) / 2];
// }

// O(M + N) time and O(1) space solution using merge sort
// double oddCount(vector<int> &nums1, vector<int> &nums2)
// {
//     int i = 0, j = 0;
//     int count = 0;

//     while (i < nums1.size() && j < nums2.size())
//     {
//         if (nums1[i] < nums2[j])
//         {
//             if (count == ((nums1.size() + nums2.size()) / 2))
//                 return nums1[i];
//             i++;
//             count++;
//         }
//         else
//         {
//             if (count == ((nums1.size() + nums2.size()) / 2))
//                 return nums2[j];
//             j++;
//             count++;
//         }
//     }

//     while (i < nums1.size())
//     {
//         if (count == ((nums1.size() + nums2.size()) / 2))
//             return nums1[i];
//         i++;
//         count++;
//     }

//     while (j < nums2.size())
//     {
//         if (count == ((nums1.size() + nums2.size()) / 2))
//             return nums2[j];
//         j++;
//         count++;
//     }

//     return 0;
// }

// double evenCount(vector<int> &nums1, vector<int> &nums2)
// {
//     int i = 0, j = 0;
//     int count = 0;
//     int element1 = 0, element2 = 0;

//     while (i < nums1.size() && j < nums2.size())
//     {
//         if (nums1[i] < nums2[j])
//         {
//             if (count == (nums1.size() + nums2.size()) / 2)
//                 element1 = nums1[i];
//             if (count == (nums1.size() + nums2.size()) / 2 - 1)
//                 element2 = nums1[i];
//             i++;
//             count++;
//         }
//         else
//         {
//             if (count == (nums1.size() + nums2.size()) / 2)
//                 element1 = nums2[j];
//             if (count == (nums1.size() + nums2.size()) / 2 - 1)
//                 element2 = nums2[j];
//             j++;
//             count++;
//         }
//     }

//     while (i < nums1.size())
//     {
//         if (count == (nums1.size() + nums2.size()) / 2)
//             element1 = nums1[i];
//         if (count == (nums1.size() + nums2.size()) / 2 - 1)
//             element2 = nums1[i];
//         i++;
//         count++;
//     }

//     while (j < nums2.size())
//     {
//         if (count == (nums1.size() + nums2.size()) / 2)
//             element1 = nums2[j];
//         if (count == (nums1.size() + nums2.size()) / 2 - 1)
//             element2 = nums2[j];
//         j++;
//         count++;
//     }

//     return (double(element1 + element2) / 2);
// }

// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
// {
//     double ans;

//     if ((nums1.size() + nums2.size()) & 1)
//         ans = oddCount(nums1, nums2);
//     else
//         ans = evenCount(nums1, nums2);

//     return ans;
// }

// O(log(min(m + n))) time and O(1) space solution using binary search
// In the approach we find the partition for array 1 and array 2 such that all the elements
// of merged array are on left side of partition of array 1 and array 2.
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size(), n2 = nums2.size();
    int low = 0, high = nums1.size();

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n1 + n2) % 2)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return 0.0;
}

int main()
{
    vector<int> nums1{1, 3};
    vector<int> nums2{2};

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}