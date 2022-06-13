#include <iostream>
using namespace std;

//常规思想会造成O(n*n*n)的时间复杂度
// a+b+c=0的表达式，可以进行调整成b+c=-a,将数组进行排序之后，可以使用
//双指针优化时间复杂度
//对于防止重复，b=nums[index+1](nums[index]为a的值)，不会漏掉响应的结果，
//因为a已经遍历过那些位置
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ret;
    //排序nums
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        // b进行赋值
        int left = i + 1;
        int right = nums.size() - 1;
        int a = -nums[i];
        while (left < right)
        {
            // cout<<111;
            //  b重复跳过
            if (left > (i + 1) && (nums[left] == nums[left - 1]))
            {
                left++;
                continue;
            }
            // //过小直接退出
            // if (left == (i + 1) && ((nums[left] + nums[right])<a))
            // {
            //     break;
            // }
            if (nums[left] + nums[right] == a)
            {
                ret.push_back({-a, nums[left], nums[right]});
                left++;
            }
            else if (nums[left] + nums[right] > a)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return ret;
}
