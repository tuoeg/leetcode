class Solution
{
public:
    map<char, string> digit = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    //不能再类中赋值map,类似map['2']={"abc"};
    vector<string> ans;
    vector<string> letterCombinations(string digits)
    {
        //常规方法将会造成时间复杂度相对较高
        //这里可以使用递归来解决排列组合问题
        //递归跳出条件为字符串输出字符长度到达字符长度
        //先用hash_map存储数值
        //回溯法=dfs+参数回退
        get_value("", digits, -1);
        return ans;
    }
    void get_value(string parents, string &children, int index)
    {
        if (children.length() == 0)
            return;
        if (index == children.length() - 1)
        {
            // cout<<"jieshu";
            ans.push_back(parents);
            return;
        }
        //遍历子节点
        index++; //同一层的结点index相同，使用后应该--；
        //多源结点遍历
        for (int i = 0; i < digit[children[index]].length(); i++)
        {
            //拼接父节点
            // cout<<digit[children[index]].length();
            parents = parents + digit[children[index]][i];
            // cout<<parents;
            get_value(parents, children, index);
            parents = parents.substr(0, parents.length() - 1); //同一层的parents结点在添加了字符之后，使用完之后应该回退
                                                               //使用substr()函数截取字符
        }
        index--;
    }
};