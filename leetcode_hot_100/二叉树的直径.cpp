#include <iostream>
using namespace std;

//深度递归访问层级    因为题目存在一个特例，路径可以不过根节点
//那么就得维护一个全局的最大层级max
int diameterOfBinaryTree(TreeNode *root)
{
    // int ret=layers(root->left) + layers(root->right);
    // cout<<layers(root->right);
    int ret = layers(root);
    return max - 1;
}

int layers(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = layers(root->left);
    int right = layers(root->right);
    if (left >= right)
    {
        max = max < (left + 1 + right) ? (left + 1 + right) : max;
        // cout<<max;
        return left + 1;
    }
    else
    {
        max = max < (right + 1 + left) ? (right + 1 + left) : max;
        return right + 1;
    }
}