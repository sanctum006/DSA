#include <bits/stdc++.h>
using namespace std;

vector<int> findMinAndMax(vector<int> nums)
{
    int minEle = 0, maxEle = 0;

    if (nums.size() == 1)
        return {nums[0], nums[0]};

    minEle = min(nums[0], nums[1]);
    maxEle = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++)
    {
        minEle = min(minEle, nums[i]);
        maxEle = max(maxEle, nums[i]);
    }

    return {minEle, maxEle};
}

int main()
{
    vector<int> nums{5, 3, 6, 9, 1, 4};
    vector<int> res = findMinAndMax(nums);

    for (auto it : res)
        cout << it << " ";

    return 0;
}