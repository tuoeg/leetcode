

#include <vector>
using namespace std;
vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
{
    vector<int> ans;
    for (auto i : points)
    {
        int count = 0 for (auto j : rectangles)
        {
            if (inside(i, j))
                ans.push_back(count);
        }
    }
    return ans;
}

bool inside(vector<int> &rectangle, vector<int> &point)
{
    if (point[0] < rectangle[0] && point[1] < rectangle[1])
        return true;
    return false;
}