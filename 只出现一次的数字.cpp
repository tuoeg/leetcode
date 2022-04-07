#include <iostream>

using namespace std;

// idea:使用异或运算，数值与自身异或，结果为0
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}