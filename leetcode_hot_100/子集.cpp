

//回溯法dfs遍历每一个组合
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> ans;
    bfs(nums, ans, 0);
}

void bfs(vector<int> &nums, vector<int> &ans; int index)
{
    if (ans.size())
        ret.push_back(ans);
    if (index == nums.size())
        return;
    for (int i = index; i < nums.size(); i++)
    {
        ans.push_back(nums[i]);
        bfs(nums, ans, ++index);
        ans.pop_back();
    }
}