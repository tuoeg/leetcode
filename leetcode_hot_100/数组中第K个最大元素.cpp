#include <iostream>
#include <queue>

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int ans = 0;
        priority_queue<int> q;
        for (auto i : nums)
        {
            q.push(i);
        }
        //出堆
        while (k > 0)
        {
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};