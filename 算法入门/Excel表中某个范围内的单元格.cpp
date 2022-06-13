#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> split(string s);
//先对字符进行切割，并进行遍历

vector<string> cellsInRange(string s)
{
    vector<string> temp = split(s);
    // cout << temp.size();
    vector<string> ans;
    //对字符进行遍历
    char begin_char = temp[0][0];
    int begin_inter = int(temp[0][1, temp[0].length() - 1]);
    char end_char = temp[1][0];
    int end_inter = (temp[1][1, temp[0].length() - 1]);
    for (; begin_char <= end_char; begin_char++) //可以直接使用字符作为头尾进行遍历
    {
        for (int i = begin_inter; i <= end_inter; i++)
        {
            // cout << i;
            ans.push_back(begin_char + to_string(i - 1)); //可以直接将数字转成字符，并减去ascii的基准
        }
    }
    return ans;
}
vector<string> split(string s)
{
    int pos = s.find(':', 0); //从index下标0开始
    if (pos == s.npos)
        return vector<string>{};
    vector<string> ans;
    string temp = s.substr(0, pos); //取出子串
    ans.emplace_back(temp);
    ans.emplace_back(s.substr(pos + 1));
    return ans;
}

int main()
{
    string s = "K1:L2";
    cellsInRange(s);
}