

//本人思想,先在矩阵中找到第一个字符匹配的几个位置
//然后进行深度遍历(多源深度遍历)
#include <vector>
using namespace std;
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<pair<int, int>> src;
        map<pair<int, int>, int> visit_nodes;
        //搜索多个源点
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                    src.push_back({i, j});
            }
        }
        //多源进行深度遍历
        for (auto root : src)
        {
            std::string ans_string;
            ans_string.push_back(board[root.first][root.second]);
            visit_nodes[root] = 1;
            if (dfs(board, root, visit_nodes, ans_string, word, 0))
                return true;
            visit_nodes[root] = 0;
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, pair<int, int> root, map<pair<int, int>, int> &visit_nodes, std::string &ans_string, std::string &word, int index)
    {
        if (ans_string == word)
            return true;
        //上下左右数组
        vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < direction.size(); i++)
        {
            //字符加入到ans_string
            int x = root.first + direction[i].first;
            int y = root.second + direction[i].second;
            if (x < 0 || x >= board.size())
                continue;
            if (y < 0 || y >= board[0].size())
                continue;
            //判断是否已经被访问
            if (visit_nodes[{x, y}] == 1)
                continue;
            visit_nodes[{x, y}] = 1;
            ++index;
            if (board[x][y] == word[index])
            {
                ans_string.push_back(board[x][y]);
                cout << ans_string;
                if (dfs(board, root, visit_nodes, ans_string, word, index))
                    return true;
                ans_string.pop_back();
            }
            else
            {
                index--;
                visit_nodes[{x, y}] = 0;
                continue;
            }
        }
        return false;
    }
};