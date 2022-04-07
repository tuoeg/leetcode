#include <vector>
#include <iostream>
using namespace std;

//对于改题，没有相处解决方法
//使用回溯法模板，遍历原始数组，以每一个原始数组值
//下标开始，对其后数据进行深度递归
// 模板：
// void backtracking(参数)
// {
//     if (终止条件)
//     {
//         存放结果
//         return;
//     }
//     for (选择：本层集合中元素(树中结点孩子的数量就是集合的大小)){
//         处理结点
//         backtracking(路径，选择列表)；//递归
//         回溯，撤销处理结果
//     }
// }
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> result;
    vector<int> temp;
    backtrack(n, k, 1, result, temp);
    return result;
}

void backtrack(int n, int k, int startIndex, vector<vector<int>> &result, vector<int> &temp)
{
    //可以加入剪枝函数，如果temp长度加上剩余数组长度<k可以跳过
    if (temp.size() == k)
    {
        result.push_back(temp);
        return;
    }
    for (int i = startIndex; i <= n; i++)
    {
        temp.push_back(i);
        backtrack(n, k, i + 1, result, temp);
        temp.pop_back();
    }
}

// 官方算法模板
vector<int> temp;
void dfs(int cur, int n)
{
    // 记录合法的答案
    if (temp.size() == k)
    {
        ans.push_back(temp);
        return;
    }
    // cur == n + 1 的时候结束递归
    if (cur == n + 1)
    {
        return;
    }
    // 考虑选择当前位置
    temp.push_back(cur);
    dfs(cur + 1, n, k);
    temp.pop_back();
    // 考虑不选择当前位置
    dfs(cur + 1, n, k); //此处就是for循环遍历，直接访问一个index
}