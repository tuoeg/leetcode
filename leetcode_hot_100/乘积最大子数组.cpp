class Solution
{
public:
    //前缀积解法
    int maxProduct(vector<int> &nums)
    {
        int Max = nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = dp[i - 1] * nums[i];
        }
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i; j >= 0; j--)
            {
                        }
            dp[]
        }
        return Max;
    }
};