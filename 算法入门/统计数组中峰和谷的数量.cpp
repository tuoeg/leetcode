
#include <iostream>
#include <vector>
using namespace std;

//简单方法，可以在向右遍历的同时将右值找出，可以减少一次循环
int countHillValley(vector<int> &nums)
{
    int count = 0; //记录峰值
    //遍历每一个数
    for (int i = 0; i < nums.size(); i++)
    {
        int left = 101;
        //查询左值
        int index = i;
        while (index)
        {
            index--;
            if (nums[index] != nums[i])
            {
                left = nums[index];
                break;
            }
        }
        if (left == 101)
            continue;
        // cout<<index<<'+'<<i;
        //查询右值
        int right = 102;
        index = i;
        while (index < nums.size() - 1)
        {
            index++;
            if (nums[index] != nums[i])
            {
                right = nums[index];
                break;
            }
            if (nums[index] == nums[i])
                i++;
        }
        if (right == 102)
            continue;
        // cout<<index<<'+'<<i;
        // cout<<index;
        if (nums[i] < right && nums[i] < left)
            count++;
        if (nums[i] > right && nums[i] > left)
            count++;
    }
    return count;
}

int countHillValley(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i + 1 < n; i++)
        if (nums[i] != nums[i + 1])
        {
            int L = -1, R = nums[i + 1];
            for (int j = i - 1; j >= 0; j--)
                if (nums[i] != nums[j])
                {
                    L = nums[j];
                    break;
                }
            if (L > 0 && L < nums[i] && R < nums[i])
                ans++;
            else if (L > 0 && L > nums[i] && R > nums[i])
                ans++;
        }
    return ans;
}