#include <iostream>

using namespace std;

//刚开始的想法是找出不重复的子串，然后判断是否符合要求
//之后想到其实这里就是一个连续子串的问题，只需要线性的前移，维护一个最长子串变量
class Solution
{
public:
    int findSubstringInWraproundString(string p)
    {
        int max_length = 1;
        int temp_len = 1;
        int temp_max = 1;
        //维护一个单个字符重复数组
        int word[26] = {0};
        word[p[0] - 'a'] = 1;
        for (int i = 1; i < p.length(); i++)
        {
            // temp_len++;
            if (temp_max <= word[p[i] - 'a'])
                continue;
            temp_len++;
            if (p[i] == p[i - 1] + 1 || (p[i - 1] == 'z' && p[i] == 'a'))
            {
                temp_max = word[p[i - 1] - 'a'] + temp_len;
                cout << temp_max;
                // temp_max = temp_max + temp_len;
                max_length = max_length - word[p[i]];
                word[p[i] - 'a'] = temp_max;
                max_length = max_length + temp_len;
            }
            else
            {
                if (word[p[i] - 'a'] == 0)
                {
                    word[p[i] - 'a'] = 1;
                    max_length++;
                    temp_len = 1;
                    temp_max = 1;
                }
            }
        }
        return max_length;
    }
};

//官方思想是无序在中间状态记载最大值，重复连续子串其实可以被替代，只要子数组末尾数字一样，并且连续长度大于之前的状态则更新
//在dp数组求出之后将dp求和将是最大值
class Solution
{
public:
    int findSubstringInWraproundString(string p)
    {
        vector<int> dp(26);
        int k = 0;
        for (int i = 0; i < p.length(); ++i)
        {
            if (i && (p[i] - p[i - 1] + 26) % 26 == 1)
            { // 字符之差为 1 或 -25
                ++k;
            }
            else
            {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
