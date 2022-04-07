#include <iostream>

using namespace std;

string reverseWords(string s)
{
    int left = 0;
    int right = 0;
    s += ' ';
    //切割字符串
    while (right < s.length() - 1)
    {
        if (s[right] == ' ')
        {
            //调用反转函数
            reserve(s, left, right);
            left = right + 1;
        }
        right++;
    }
    return s.erase(s.length() - 1, 1);
}

void reserve(string &s, int left, int right)
{
    while (left < right)
    {
        swap(s[left++], s[right--]);
    }
}