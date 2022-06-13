/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int row = 0; row < n / 2; row++)
        {
            for (int col = 0; col < (n + 1) / 2; col++)
            {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][n - row - 1];
                matrix[col][n - row - 1] = matrix[n - row - 1][n - col - 1];
                matrix[n - row - 1][n - col - 1] = matrix[n - row - 1][n - col - 1];
                matrix[n - row - 1][n - col - 1] = temp;
            }
        }
    }
};
// @lc code=end
