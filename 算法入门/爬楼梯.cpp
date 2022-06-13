#include <string>
#include <iostream>
using namespace std;

// idea：使用动态规划，第n阶楼梯最终的来源是第n-1阶台阶和弟n-2阶台阶
int climbStairs(int n)
{
    int a[n + 1];
    memset(a, 0, (n + 1) * sizeof(int));
    if (n == 1)
        a[1] = 1;
    if (n == 2)
        a[2] = 2;
    for (int i = 3; i < n + 1; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}