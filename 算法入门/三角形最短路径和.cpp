#include <iostream>
#include <vector>
using namespace std;

// idea:到达当前位置n，上一个位置可以是n-1，也可以是n,三角形两边只有一条路
//状态方程是f[i][j]=f[i-1][j-1]<f[i-1][j]?(f[i-1][j-1]+f[i][j]):(f[i-1][j]+f[i][j])

//可以再进行优化，可以将每一行的头尾方法for循环的之前进行处理
int minimumTotal(vector<vector<int>> &triangle)
{
    int row_min = 0;
    for (int i = 1; i < triangle.size(); i++)
    {
        // cout<<i<<" "<<triangle[i].size();
        for (int j = 0; j < triangle[i].size(); j++)
        {
            // cout<<1111111;
            //处理头尾特例
            if (j == 0 || j == triangle[i].size() - 1)
            {
                if (j == 0)
                {
                    triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
                    row_min = triangle[i][j];
                }
                else
                {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
                    row_min = row_min < triangle[i][j] ? row_min : triangle[i][j];
                }
                continue;
            }
            //处理中间结点
            triangle[i][j] = triangle[i - 1][j] < triangle[i - 1][j - 1] ? (triangle[i - 1][j] + triangle[i][j]) : (triangle[i - 1][j - 1] + triangle[i][j]);
            row_min = row_min < triangle[i][j] ? row_min : triangle[i][j];
        }
        cout << row_min;
    }
    if (triangle.size() == 1)
        return triangle[0][0];
    return row_min;
}