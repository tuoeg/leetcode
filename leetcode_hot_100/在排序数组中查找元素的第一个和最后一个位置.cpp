#include <vector>

using namespace std;
//官方思想，两次二分查找直接定位begin和end下标

int binarysearch(vector<int> &nums, int target, bool lower)
{
    int left = 0;
    int right = nums.size();
    int ans = 0;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (nums[middle] > target || (lower && nums[middle] >= target))
        {
            left = middle - 1;
            ans = middle;
        }
        else
            right = middle + 1;
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int begin = binarysearch(nums, target, true);    //一直到target的左边界
    int end = binarysearch(nums, target, false) - 1; //一直到达比target大的那个下标
    if (begin <= end && end < nums.size() && nums[begin] == target && nums[end] == target)
        return {begin, end};
    return {-1, -1};
}
//先二分查找到target，然后进行左移右移  该方法不够简洁
vector<int> searchRange(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int target_index = -1;
    if (nums.size() == 0)
        return {-1, -1};
    // vector<int> ans;
    while (left < right)
    {
        int middle = (left + right) / 2;
        if (nums[middle] >= target)
            right = middle;
        if (nums[middle] < target)
            left = middle + 1;
    }
    if (nums[left] == target)
        target_index = left;
    // cout<<target_index;
    //在target_index周围展开
    if (target_index != -1)
    {
        int target_begin = target_index;
        int target_end = target_index;
        while (target_begin >= 0)
        {
            if (nums[target_begin] != target)
                break;
            target_begin--;
        }
        while (target_end <= nums.size() - 1)
        {
            if (nums[target_end] != target)
                break;
            target_end++;
        }
        return {target_begin + 1, target_end - 1};
    }
    return {-1, -1};
}