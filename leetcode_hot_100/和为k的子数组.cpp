class Solution
{
public:
    //直接使用回溯法，先排序进行剪枝
    int subarraySum(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, index, sum, k);
    }
    void dfs(vector<int> &nums, int index, int sum, int k)
    {
        if (sum > k || index == nums.size())
            return;
        for (int i = index; i < nums.size(); i++)
        {
            //回溯模板条件放在此处
            if (sum == k)
            {
                count++;
                return;
            }
            sum = sum + nums[i];
            dfs(nums, ++i, sum, k);
            sum = sum - nums[i];
        }
    }
    //该题的子数组尽然是连续子数组，可以采用前缀和，并使用map存储之前的前缀和以及相同前缀和出现次数
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> temp;
        int count = 0;
        int pre = 0;
        temp[0] = 1;
        for (auto i : nums)
        {
            pre += i;
            if (temp.find(pre - k) != temp.end())
                count += temp[pre - k];
            temp[pre]++;
        }
        return count;
    }
};