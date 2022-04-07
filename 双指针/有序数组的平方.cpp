#include<iostream>
#include<vector>
#include<math>

using namespace std;



// 思路：使用双指针进行遍历，负数最大的在左侧，正数最大的在右侧
vector<int> sortedSquares(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    vector<int> result;
    //vector<int> temp(nums.size());
    int count=nums.size()-1;
    while(left<=right)//当左右指针相遇时跳出循环
    {
        if(pow(nums[left],2)>pow(nums[right],2))
        {
            result[count--]=pow(nums[left++],2);
        }
        else
        {
            result[count--]=pow(nums[right--],2);
        }
    }
    return result;
}