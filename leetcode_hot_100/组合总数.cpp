#include <vector>

using namespace std;

//组合问题大部分还是使用回溯方法，不过对于避免重复，采用只访问当前结点之前的数据
//需要对回溯变量进行恢复，为了确保不产生重复的组合，访问过得index，不会再进行访问，只会访问后面的index
vector<vector<int>> ans;
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    // int sum = 0;
    vector<int> ret;
    for (int i = 0; i < candidates.size(); i++)
    {
        ret.push_back(candidates[i]);
        backtrack(candidates, target, i, candidates[i], ret);
        ret.pop_back();
    }
    return ans;
}

void backtrack(vector<int> &nums, int target, int index, int sum, vector<int> &ret)
{
    if (sum > target)
        return;
    if (sum == target)
    {
        ans.push_back(ret);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        ret.push_back(nums[i]);
        sum = sum + nums[i];
        backtrack(nums, target, i, sum, ret);
        sum = sum - nums[i];
        ret.pop_back();
    }
}