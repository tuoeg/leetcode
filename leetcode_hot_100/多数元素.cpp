#include <iostream>

using namespace std;

// idea：由于数据占据了整个数组的一半以上，那么考虑到，可以模拟抵消的一个过程
//如果数据不相同则可以抵消，数据相同则可以进行相加
// Boyer-Moore 投票算法   众数与其他数值相抵消，将能够只剩下众数
int majorityElement(vector<int> &nums)
{
    int num = nums[0];
    int num_count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (num_count == 0)
        {
            num = nums[i];
            num_count++; //更换数据之后，记得递增数字
            continue;
        }
        if (nums[i] == num)
            num_count++;
        if (nums[i] != num)
        {
            num_count--;
        }
    }
    return num;
}