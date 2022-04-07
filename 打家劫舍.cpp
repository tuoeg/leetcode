#include <iostream>
#include <vector>
using namespace std;

// idea:访问数组中的第n个值，那么这第n个值可以从n-2和n-3访问过来，因为n-1不能访问，
//当得到了n-2和n-3的值那么n的值也能知道，n-2和n-3需要比较大小

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];
    if (nums.size() == 3)
        return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
    // if (nums.size() == 4)
    //     return nums[0] + nums[2] > nums[1] + nums[3]? nums[0] + nums[2] : nums[1]+nums[3];
    nums[1] = nums[0];
    nums[2] = nums[0] + nums[2];
    nums[3] = nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
    // nums[4]=nums[0] + nums[2] > nums[1] + nums[3]? nums[0] + nums[2] : nums[1]+nums[3];
    for (int i = 4; i < nums.size(); i++)
    {
        nums[i] = nums[i - 2] > nums[i - 3] ? nums[i - 2] + nums[i] : nums[i - 3] + nums[i];
    }
    return nums[nums.size() - 1];
}