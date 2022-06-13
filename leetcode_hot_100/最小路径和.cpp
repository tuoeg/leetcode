#include <vector>

using namespace std;

//典型的动态规划
int minPathSum(vector<vector<int>> &grid)
{
    //先初始化左、上两条边界
    for (int i = 1; i < grid[0].size(); i++)
        grid[0][i] = grid[0][i] + grid[0][i - 1];
    for (int i = 1; i < grid.size(); i++)
        grid[i][0] = grid[i][0] + grid[i - 1][0];
    for (int i = 1; i < grid.size(); i++)
    {
        for (int j = 1; j < grid[0].size(); j++)
        {
            // cout<<grid[i - 1][j]<<grid[i][j - 1];
            grid[i][j] = grid[i - 1][j] <= grid[i][j - 1] ? (grid[i - 1][j] + grid[i][j]) : (grid[i][j - 1] + grid[i][j]);
        }
    }
    return grid[grid.size() - 1][grid[0].size() - 1];
}