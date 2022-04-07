#include <iostream>
#include <vector>
using namespace std;

//初始idea：不能使用双重遍历
//可以设置一个开始下标，如果下一个数大于开始数则计算利润，如果小于开始的那个数
//则替换开始下标
int maxProfit(vector<int> &prices)
{
    int begin_index = 0;
    int max_profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] > prices[begin_index])
            max_profit = max_profit > (prices[i] - prices[begin_index]) ? max_profit : (prices[i] - prices[begin_index]);
        if (prices[i] < prices[begin_index])
            begin_index = i;
    }
    return max_profit;
}