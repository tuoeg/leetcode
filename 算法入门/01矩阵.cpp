#include <iostream>
#include <vector>
using namespace std;

//idea 创建结果矩阵，访问矩阵中每一个1，使用广度优先遍历
//去寻找0值结点，队列中暂存的结点一旦是0，这将是一个最近的距离
//同时加入访问数组来标记结点是否已经被访问(每一次重新遍历都需要重置)
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    //创建结果数组
    vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
    //遍历矩阵中的1
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                //创建访问数组
                int access_matix[mat.size() * mat[0].size()];
            }
        }
    }
}

int