/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
*/

#include <bits/stdc++.h>
using namespace std;

// O(N^2) solution using inset sort like technique

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    int index = 0;
    for (int i = 0; i < arr2.size(); ++i)
    {
        for (int j = index; j < arr1.size(); ++j)
        {
            if (arr2[i] == arr1[j]) // find element in arr2
            {
                swap(arr1[j], arr1[index]); // put it at right place
                index++;
            }
        }
    }

    // sort rest elements
    sort(arr1.begin() + index, arr1.end());

    return arr1;
}

// O(N) solution
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    int maxEle = *max_element(arr1.begin(), arr1.end());
    vector<int> count(maxEle + 1);

    for (auto it : arr1)
        count[it]++;

    vector<int> res;

    for (int i = 0; i < arr2.size(); i++)
    {
        while (count[arr2[i]] > 0)
        {
            res.push_back(arr2[i]);
            count[arr2[i]]--;
        }
    }

    for (int i = 0; i < count.size(); i++)
        while (count[i] > 0)
        {
            res.push_back(i);
            count[i]--;
        }

    return res;
}

int main()
{
    // Not called

    return 0;
}