#include <iostream>
#include <vector>
using namespace std;

//使用额外数组进行求解

void rotate(vector<int> &nums, int k)
{
    //从未移位的位置开始，其下标为
    int begin_index = (nums.size() - k % nums.size()) % nums.size();
    vector<int> temp;
    int count = nums.size();
    while (count--)
    {
        temp.push_back(nums[begin_index]);
        begin_index++;
        if (begin_index == nums.size())
            begin_index = 0;
        //count--;
    }
    //將temp赋值给nums
    nums.assign(temp.begin(), temp.end());
}



//对数组进行原地翻转
void rotate(vector<int> nums,int k)
{
    //整体置换
    reserve(nums,0,nums.size()-1);
    //分段置换
    reserve(nums,0,k%nums.size()-1);
    reserve(nums,k%nums.size(),nums.size()-1);
}


//对子数组进行翻转
void reserve(vector<int> &nums,int begin,int end)
{
    while(begin<end)
    {
        //置换
        int temp=nums[begin];
        nums[begin]=nums[end];
        nums[end]=temp;
    }
}