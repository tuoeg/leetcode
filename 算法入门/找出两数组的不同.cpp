#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> ans;
    vector<int> ans1;
    vector<int> ans2;
    bool exist = false;
    for (int i = 0; i < nums1.size(); i++)
    {
        exist = false;
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
                exist = true;
        }
        if (!exist && exist(nums1, nums[i]))
            ans1.push_back(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        exist = false;
        for (int j = 0; j < nums1.size(); j++)
        {
            if (nums2[i] == nums1[j])
                exist = true;
        }
        if (!exist && exist(nums2, nums[i]))
            ans2.push_back(nums2[i]);
    }
    ans.push_back(ans1);
    ans.push_back(ans2);
    return ans;
}

bool exist(vector<int> &nums, int value)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == value)
            return false;
    }
    return true;
}