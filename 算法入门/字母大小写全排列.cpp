#include <iostream>
#include <vector>
using namespace std;

vector<string> letterCasePermutation(string s)
{
    vector<string> result;
    std::string temp;
    backtracking(s, temp, result, 0);
    return result;
}

// idea:此处任然使用回溯方法，如果是字母则变换大小写进行递归，同时原字符也进行递归
//此处的字符加上整型结果仍然为字符型

// void backtracking(string &s, string &temp, vector<string> &result, int index)
// {
//     //长度满足则return
//     if (temp.size() == s.length())
//     {
//         result.push_back(temp);
//         return;
//     }
//     //如果是小写则变换大写
//     //进行两次转换，一次不变换大小写，一次变换大小写
//     char a;
//     if (s[index] - '0' >= 0 && s[index] - '0' <= 9)
//     {
//         temp.push_back(s[index]);
//         backtracking(s, temp, result, index + 1);
//         temp.pop_back();
//     }
//     else
//     {
//         for (int i = 0; i < 2; i++)
//         {
//             if (i == 0)
//             {
//                 if (s[index] - 'A' >= 0 && s[index] - 'A' <= 26)
//                     a = s[index] + 32;
//                 if (s[index] - 'a' >= 0 && s[index] - 'a' <= 26)
//                     a = s[index] - 32;
//             }
//             a = s[index];
//             temp.push_back(a);
//             backtracking(s, temp, result, index + 1);
//             temp.pop_back();
//         }
//     }
// }

void backtracking(string &s, string &temp, vector<string> &result, int index)
{
    //长度满足则return
    if (temp.size() == s.length())
    {
        result.push_back(temp);
        return;
    }
    //如果是小写则变换大写
    //进行两次转换，一次不变换大小写，一次变换大小写
    char a;

    if (s[index] - 'A' >= 0 && s[index] - 'A' <= 26)
    {
        a = s[index] + 32;
        temp.push_back(a);
        backtracking(s, temp, result, index + 1);
        temp.pop_back();
    }
    if (s[index] - 'a' >= 0 && s[index] - 'a' <= 26)
    {
        a = s[index] - 32;
        temp.push_back(a);
        backtracking(s, temp, result, index + 1);
        temp.pop_back();
    }
    temp.push_back(s[index]);
    backtracking(s, temp, result, index + 1);
    temp.pop_back();
}