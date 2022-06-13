#include <iostream>
#include <vector>
using namespace std;

//该题常规思路无法解决，不能算出所有数的回文串

// idea:使用一半长度的回文串进行操作，并且计算数字位数的长度对应有多少个回文数字，并且设计回文恢复算法(分为奇偶进行计算)
vector<long long> kthPalindrome(vector<int> &queries, int intLength)
{
    vector<long long> ans;
    //数组一半的长度
    int middle_len = (intLength + 1) >> 1;
    // cout<<middle_len;
    //回文最大个数
    long long max_palindrome = 9 * pow(10, middle_len - 1);
    cout << max_palindrome;
    for (int i = 0; i < queries.size(); i++)
    {
        // cout<<ret[queries[i] - 1];
        if (queries[i] > max_palindrome)
            ans.push_back(-1);
        else
            ans.push_back(construct_oalindrome(1 * pow(10, middle_len - 1) + queries[i] - 1, intLength));
    }
    return ans;
}
//构造回文
// odd_or_even  //奇数为-1，偶数为0
long long construct_oalindrome(long long value, int len)
{
    // cout<<value<<" ";
    long long initial_value = value;
    long long sum = 0;
    int left = 0;
    int right = 0;
    //基数先处理末尾
    if (len % 2 != 0)
    {
        int num = value % 10;
        value = value / 10;
        sum = sum + num * pow(10, ((len + 1) >> 1) - 1);
        left = (len + 1) >> 1;
        right = ((len + 1) >> 1) - 1;
        // cout<<left<<right;
    }
    else
    {
        left = (len + 1) >> 1;
        right = (len + 1) >> 1;
    }
    while (value)
    {
        int num = value % 10;
        value = value / 10;
        right--;
        sum = sum + num * pow(10, left) + num * pow(10, right);
        left++;

        // cout<<sum<<" "<<value<<" ";
    }
    return sum;
}