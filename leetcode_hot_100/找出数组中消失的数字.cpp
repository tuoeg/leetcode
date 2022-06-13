#include <vector>
using namespace std;

//常规思想:使用map进行统计，但是使用了O(n)的空间损耗
//特殊思想:可以在原数组的基础上，对存在的数对应数组下标的数值进行+n操作(巧妙之处，进行取余运算仍然可以回到原值),
//再次遍历数组，如果
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> ans;
    for (num : nums)
    {
        nums[num % n - 1] += n;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < n)
            ans.push_back(i + 1);
    }
    return ans;
}