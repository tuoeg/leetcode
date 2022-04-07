#include<iostream>
#include<vector>

using namespace std;



// 进行二分查找，当跳出while时，target与nums[middle]进行比较江能得到target下标
int searchInsert(vector<int>& nums, int target) {
    int begin=0;
    int end=nums.size()-1;
    int middle;
    while(begin<=end)
    {
        middle=begin+(end-begin)/2;
        if(nums[middle]>target)
        {
            end=middle-1;
        }
        else if(nums[middle]<target)
        {
            begin=middle+1;
        }
        else
        {
            return middle;
        }
    }
    //当没有对应的位置时
    if(target>nums[middle])
    {
        return middle+1;
    }
    return middle;
}