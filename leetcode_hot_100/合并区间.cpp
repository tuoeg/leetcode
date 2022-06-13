#include <vector>
using namespace std;

bool cmp(int a[], int b[])
{
    if (a[0] > b[0])
        return true;
    return false;
}
//先对区间进行排序，从最小区间进行遍历，如何相邻区间没有交集，那么前一个区间可以加入到结果集合
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    //升序
    sort(intervals.begin(), intervals.end(), cmp);
    //对数组进行合并
    int begin = 0, end = 0;
    for (auto arr : intervals)
    {
        //进行赋值
        if (begin == end && begin == 0)
        {
            begin = arr[0];
            end = arr[1];
            continue;
        }
        //合并区间
        if (arr[0] <= end)
            end = arr[1];
        else
        {
            ans.push_back({begin, end});
            begin = 0;
            end = 0;
        }
    }
    return ans;
}