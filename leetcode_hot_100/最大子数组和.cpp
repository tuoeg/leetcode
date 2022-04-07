#include <iostream>
#include <vector>
using namespace std;

//初阶idea 使用遍历算法，最优的连续数组一定从其中的某一个元素下标开始

//进阶idea 复杂度为O(n)，
int maxSubArray(vector<int> &nums)
{
    //定义连续子数组开始下标
    int index = 0;
    //全局最大和
    int globalSum = nums[0];
    //局部最大和
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] + sum < nums[i])
        {
            index = i;
            sum = nums[index];
        }
        sum = sum + nums[index];
        if (sum > globalSum)
            globalSum = sum;
    }
    return globalSum;
}