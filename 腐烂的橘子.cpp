#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// idea将所有腐烂的橘子入队列(多源广度优先遍历)
//在每一层遍历之后，判断新鲜橘子的个数，如果不再减少，返回-1
//新鲜橘子数目为0，返回遍历层数
int orangesRotting(vector<vector<int>> &grid)
{
    //将多源加入队列
    //将多源加入队列
    queue<pair<int, int>> q;
    int orangeNum = 0;
    int floorNum = 0;
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
                q.emplace(i, j);
        }
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
        floorNum = q.size();
        for (int i = 0; i < floorNum; i++)
        {
            std::pair<int, int> coordinate = q.front();
            q.pop();
            int m = coordinate.first;
            int n = coordinate.second;
            grid[m][n] = 2;
            //将上下左右的1加入到队列
            for (int j = 0; j < 4; j++)
            {
                int x = m + dx[j], y = n + dy[j];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1)
                    q.emplace(x, y);
            }
        }
        int temp = 0;
        //判断新鲜橘子数目
        for (int k = 0; k < grid.size(); k++)
        {
            for (int l = 0; l < grid[0].size(); l++)
            {
                if (grid[k][l] == 1)
                    temp++;
            }
        }
        //将上次和本次数量进行比较
        if (temp == orangeNum && orangeNum != 0)
        {
            // cout<<temp<<"#"<<orangeNum;
            return -1;
        }
        orangeNum = temp;
        count++;
    }
    cout << orangeNum;
    return count;
}
