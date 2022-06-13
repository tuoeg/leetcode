#include <iostream>
using namespace std;

// idea：使用后序遍历dfs进行
// void flatten(TreeNode *root)
// {
//     dfs(root);
// }
// TreeNode *dfs(TreeNode *root)
// {
//     if (root == nullptr)
//         return nullptr;
//     TreeNode *left = dfs(root->left);
//     TreeNode *right = dfs(root->right);
//     if (left != nullptr)
//         left->right = right;
//     else
//         root->right = right;
//     root->right = left;
//     return root;
// }

vector<TreeNode *> node_arr;
//使用前序遍历，使用vector存储对应的结点，并改变结点指向
void dfs(TreeNode *root)
{
    if (root == nullptr)
        return;
    node_arr.push_back(root);
    dfs(root->left);
    dfs(root->right);
}