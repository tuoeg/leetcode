#include <iostream>
#include <vector>

using namespace std;
// 常规实现
int search(vector<int>& nums,int target){
    int begin=0;
    int end=nums.size()-1;
    int middle;
    while(begin<=end&&begin>=0&&end<=nums.size()-1)
    {
        middle=(end+begin)/2;
        if(nums[middle]<target)
        {
            begin=middle+1;
        }
        if(nums[middle]>target)
        {
            end=middle-1;
        }
        if(nums[middle]==target)
        {
            return middle;
        }
    }
    return -1;

}


/*  该题主要考察的是对于边界条件的考虑
1.对于middle值的计算，middle应该使用(begin+end)/2进行计算
2.对于begin和end是否会超出界限
3.可以使用递归来进行实现*/


//递归实现
int search(vector<int>& nums, int target) {
    int middle=(0+nums.size()-1)/2;
    return recursion(nums,0,middle,nums.size()-1,target);
}
int recursion(vector<int>&nums,int begin,int middle,int end,int target)
{
    if(begin>end||begin<0||end>nums.size()-1)
        return -1;
    if(target==nums[middle])
        return middle;
    if(nums[middle]<target)
    {
        return recursion(nums,middle+1,(middle+1+end)/2,end,target);
    }
    if(nums[middle]>target)
    {
        return recursion(nums,begin,(begin+middle-1)/2,middle-1,target);
    }
    return -1;
}



//二分查找优化算法
int binarySearch(vector<int> arr,int target)
{
    int begin=0;
    int end=arr.size()-1;
    while(begin<end)
    {
        if
    }
}