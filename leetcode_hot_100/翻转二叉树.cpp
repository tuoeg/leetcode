#include <iostream>
using namespace std;

// idea直接使用二路递归，翻转二叉树
TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return nullptr;
    TreeNode *left = invertTree(root->right);
    TreeNode *right = invertTree(root->left);
    root->left = left;
    root->right = right;
    return root;
}