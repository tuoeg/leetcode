class Solution
{
public:
    //使用广度优先遍历，同时记得在找到一个'1'结点时便将该结点加入到队列，并标记为0，在出栈时再标记容易造成重复入栈
    int numIslands(vector<vector<char>> &grid)
    {
        int island_nums = 0;
        // for (int i = 0; i < grid.size(); i++)
        // {
        //     for (int j = 0; j < grid[0].size(); j++)
        //     {
        //         if (grid[i][j] == '1')
        //         {
        //             bfs(grid, i, j);
        //             island_nums++;
        //         }
        //     }
        // }
        for (int i = 0; i < grid.size() * grid[0].size(); i++)
        {
            int x = i / grid[0].size();
            int y = i % grid[0].size();
            if (grid[x][y] == '1')
            {
                bfs(grid, x, y);
                island_nums++;
            }
            // cout<<x<<" "<<y<<endl;
        }
        return island_nums;
    }

    void bfs(vector<vector<char>> &grid, int x, int y)
    {
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        // new queue
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = '0';
        while (!q.empty())
        {
            pair<int, int> node = q.front();
            int x = node.first;
            int y = node.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                if (0 <= x + dx[i] && x + dx[i] < grid.size() && 0 <= y + dy[i] && y + dy[i] < grid[0].size() && grid[x + dx[i]][y + dy[i]] == '1')
                {
                    q.push({x + dx[i], y + dy[i]});
                    grid[x + dx[i]][y + dy[i]] = '0';
                }
            }
        }
    }
};