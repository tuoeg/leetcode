#include <vector>
using namespace std;

vector<int> intersection(vector<vector<int>> &nums)
{
    //使用数组存储
    int arr[1001] = {0};
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            arr[nums[i][j]]++;
        }
    }
    for (int i = 0; i <= 1001; i++)
    {
        if (arr[i] == nums.size())
            ans.push_back(i);
    }
    return ans;
}