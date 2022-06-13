#include <iostream>
#include <queue>
using namespace std;

//二叉树层序遍历模板
//使用队列存储
vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == nullptr)
        return;
    q.push(root);
    vector<vector<int>> ans;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.top();
            q.pop();
            temp.push_back(node->val);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        ans.push_back(temp);
    }
    return ans;
}