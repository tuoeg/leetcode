#include <iostream>
#include <vector>
using namespace std;

//初始想法借助访问矩阵，最后的想法是将访问过得位置的值改成0，之后便不能再进行访问
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    //定义访问标记矩阵
    //vector<vector<int>> access_matix(grid.size(), vector<int>(grid[0].size(), 0));
    //访问所有的结点
    int max = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] != 0)
            {
                int maxArea = 0;
                search(i, j, maxArea, grid);
                //cout<<maxArea;
                max = max > maxArea ? max : maxArea;
            }
        }
    }
    return max;
}

//此处的递归上下左右可以直接使用for循环遍历，减少代码量
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
for (int index = 0; index != 4; ++index)
{
    int next_i = cur_i + di[index], next_j = cur_j + dj[index];
}
//递归函数
void search(int i, int j, int &maxArea, vector<vector<int>> &grid)
{
    //上下左右深度递归
    grid[i][j] = 0;
    maxArea = maxArea + 1;
    //向上递归
    if (i - 1 >= 0 && grid[i - 1][j] != 0)
        search(i - 1, j, maxArea, grid);
    //向下递归
    if (i + 1 < grid.size() && grid[i + 1][j] != 0)
        search(i + 1, j, maxArea, grid);
    //向左递归
    if (j - 1 >= 0 && grid[i][j - 1] != 0)
        search(i, j - 1, maxArea, grid);
    //向右递归
    if (j + 1 < grid[0].size() && grid[i][j + 1] != 0)
        search(i, j + 1, maxArea, grid);
}
