#include <vector>

using namespace std;

//掌握括号的生成方法
//已经生成的括号中左括号数量一定要多于右括号
//左括号数目一定要少于n
vector<string> ans;
vector<string> generateParenthesis(int n)
{
    generate('', 0, 0, 2 * n);
}
void generate(string parents, int left, int right, int sum)
{
    if ((left + right == sum) && left == right)
    {
        ans.push_back(parents);
        return;
    }
    // if((left>sum/2)||(right+left>sum))
    //     return;
    if (left < (sum / 2))
    {
        parents = parents + '(';
        // cout<<parents;
        generate(parents, ++left, right, sum); //注意left++与++left的传参问题，left++传参下去会导致left没有改变
        parents = parents.substr(0, parents.length() - 1);
        left--;
    }
    if (left > right)
    {
        parents = parents + ')';
        generate(parents, left, ++right, sum);
        parents = parents.substr(0, parents.length() - 1);
        right--;
    }
}
}
