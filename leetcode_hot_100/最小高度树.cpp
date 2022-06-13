#include <vector>
#include <queue>
#include <map>
using namespace std;

// idea：还是遍历整个结点，将遍历过得结点加入到hashmap,将关联的结点
//加入到待访问队列，并维护一个最小高度结点数组
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    bool signal = true;
    int min_height = 0;
    vector<int> min_node;
    for (int i = 0; i < n; i++)
    {
        // i加入队列
        queue<int> q;
        q.push(i);
        //访问hash
        map<int, int> visit_map;
        int min_temp = 0;
        while (!q.empty())
        {
            for (int j = 0; j < q.size(); j++)
            {
                //加入访问数组
                int root = q.;
                visit_map[i] = 1;
                //查询相连接未访问数组
                vector<int> not_visit_node = find_not_visit_node(root, edges, visit_map);
                //全部入队列
                for (auto i : not_visit_node)
                {
                    q.push(i);
                }
            }
            min_temp++;
        }
        if (signal)
        {
            min_height = min_temp;
            signal = false;
        }
        if (min_temp < min_height)
        {
            //先清空之前的结点
            min_node.clear();
            min_height = min_temp;
            min_node.push_back(i);
        }
        if (min_temp == min_height)
            min_node.push_back(i);
    }
    return min_node;
}
vector<int> find_not_visit_node(int node, vector<vector<int>> &edges, map<int, int> &visit_map)
{
    vector<int> not_visit_node;
    for (auto i : edges)
    {
        if (node == edges[0] || node == edges[1])
        {
            // node已经加入到了visit数组，不用再判断node对应edges[0]/edges[1]
            if (visit_map.find(edges[0]) == visit_map.end())
                not_visit_node.push_back(edges[0]);
            if (visit_map.find(edges[1]) == visit_map.end())
                not_visit_node.push_back(edges[1]);
        }
    }
    return not_visit_node;
}