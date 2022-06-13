class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int Max = nums[0];
        int Min = nums[nums.size() - 1];
        int begin = 0;
        int end;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > Max)
            {
                Max = nums[i];
            }
            else
                end = i;
            if (nums[nums.size() - 1 - i] < Min)
                Min = nums[i];
            else
                begin = nums.size() - 1 - i;
        }
        return end - begin + 1;
    }
};