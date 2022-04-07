#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s);
bool match(char c1, char c2);
int main()
{
    isValid("{[]}");
}
// idea：使用一个单调栈进行操作
//该简单题花费了太多时间，1.在于遍历字符串的界限
// 2.在于栈为空不能对访问top，必须添加元素，并continue跳过
// 3.访问字符串中字符不用做出转换
// 4.在栈顶元素和s[index]比较之后，如果不同则需要进行push
bool isValid(string s)
{
    stack<char> st;
    int index = 0;
    st.push(s[0]);
    // cout<<s.length();
    while (index < s.length() - 1)
    {
        index++;
        //对字符进行匹配
        if (st.empty())
        {
            st.push(s[index]);
            continue;
        }
        if (match(s[index], st.top()))
        {
            st.pop();
            // index++;
        }
        else
            st.push(s[index]);
    }
    // cout<<st.top();
    if (st.empty())
        return true;
    return false;
}

bool match(char c1, char c2)
{
    if (c1 == ')' && c2 == '(')
        return true;
    if (c1 == ']' && c2 == '[')
        return true;
    if (c1 == '}' && c2 == '{')
        return true;
    return false;
}