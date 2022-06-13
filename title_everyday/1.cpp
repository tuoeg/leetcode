#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //使用二分查找从1-max进行查找最小速度
    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());
        int min = 1;
        int max = piles[piles.size() - 1];
        cout << min << max;
        while (min < max)
        {
            // cout << min << " " << max << endl;
            int middle = (max + min) / 2;
            int time_nums = speed_time(piles, middle);
            if (time_nums <= h)
                max = middle;
            else
                min = middle + 1;
        }
        return min;
    }
    int speed_time(vector<int> &piles, int v)
    {
        int time_nums;
        for (auto i : piles)
        {
            if (i % v != 0)
                time_nums += i / v + 1;
            else
                time_nums += i / v;
        }
        // cout<<time_nums;
        return time_nums;
    }
};

int main()
{
    Solution a;
    vector<int> b{3, 6, 7, 11};
    cout << a.minEatingSpeed(b, 8);
}