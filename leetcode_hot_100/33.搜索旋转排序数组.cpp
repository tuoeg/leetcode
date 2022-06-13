/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
//二分法搜索
// @lc code=start

//该题使用二分法比较的巧妙
//代码写复杂了，没有将条件中相同步骤提取出来，比如在两个条件中都判断了[5,1,2,3,4]和[5,6,7,8,1,2,3]这两种情况
//应该直接在if条件判断时就判断这两种情况

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            // middle左边有序
            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            // middle右边有序
            else
            {
                if (nums[mid] < target && target <= nums[n - 1])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
    }

    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int middle = (left + right) / 2;
            if (target == nums[middle])
                return middle;
            if (target > nums[middle])
            {
                if (nums[left] < nums[middle])
                    left = middle + 1;
                if (nums[left] > nums[middle] && nums[right] >= target)
                    left = middle + 1;
                if (nums[left] > nums[middle] && nums[right] < target)
                    right = middle - 1;
            }
            if (target < nums[middle])
            {
                if (nums[right] > nums[middle])
                    right = middle - 1;
                if (nums[right] < nums[middle] && nums[left] < target)
                    right = middle - 1;
                if (nums[right] < nums[middle] && nums[left] >= target)
                    left = middle + 1;
            }
        }
        return nums[left] == target ? left : -1;
    }
};
// @lc code=end
