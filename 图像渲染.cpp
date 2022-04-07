#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//idea
//使用广度优先遍历，此处需要想想如何存储矩阵中的坐标
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    //使用队列实现广度优先遍历
    queue<int> q;
    int visit[image[0].size() * image.size()];
    memset(visit, 0, sizeof(int) * image[0].size() * image.size());
    int cols = image[0].size();
    int rows = image.size();
    //将初试位置加入到队列
    q.push(cols * sr + sc);
    visit[cols * sr + sc] = 1;
    //cout<<cols * sr + sc;
    int init_color = image[sr][sc];
    while (!q.empty())
    {
        //出队列
        int index = q.front();
        q.pop();
        int row = index / cols;
        int col = index - row * cols;
        //cout<<col<<row;
        image[row][col] = newColor;
        //向上下左右各个方向扩张
        if (row - 1 >= 0 && image[row - 1][col] == init_color && visit[(row - 1) * cols + col] == 0)
        {
            q.push((row - 1) * cols + col);
            visit[(row - 1) * cols + col] = 1;
            //cout<<111;
        }
        if (row + 1 < rows && image[row + 1][col] == init_color && visit[(row + 1) * cols + col] == 0)
        {
            q.push((row + 1) * cols + col);
            visit[(row + 1) * cols + col] = 1;
            //cout<<222;
        }
        if (col - 1 >= 0 && image[row][col - 1] == init_color && visit[row * cols + col - 1] == 0)
        {
            q.push(row * cols + col - 1);
            visit[row * cols + col] = 1;
            //cout<<333;
        }
        if (col + 1 < cols && image[row][col + 1] == init_color && visit[row * cols + col + 1] == 0)
        {
            //cout<<row * cols + col + 1+1;
            q.push(row * cols + col + 1);
            visit[row * cols + col + 1] = 1;
            //cout<<444;
        }
    }
    // for(int i=0;i<image[0].size()*image.size();i++)
    //     cout<<i<<visit[i];
    return image;
}