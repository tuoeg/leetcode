class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        //如何两点x坐标相等，k斜率不存在
        if (poinst[0][0] == points[1][0])
        {
            if (points[2][0] == points[1][0])
                return false;
            else
                return true;
        }
        return points[2][1] - points[0][1] == (points[0][1] - points[1][1]) / (points[0][0] - points[1][0])(points[2][0] - points[1][0]) ? false : true;
    }
};