#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
};

//最初的idea 使用遍历访问二叉树，然后对比数据的对称性，该方法不太方便，占用内部过多
//便捷方法：直接使用两路前序遍历，或者使用两路层序遍历

//两路前序遍历
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return false;
    return preorder(root->left, root->right);
}

bool preorder(TreeNode *root1, TreeNode *root2)
{
    //同时为空，直接返回
    if (root1 == nullptr && root2 == nullptr)
        return true;
    //同时为空的情况已经处理，可以直接处理单个结点为空的情况
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->val != root2->val)
        return false;
    else
        return preorder(root1->left, root2->right) && preorder(root1->right, root2->left);
}

//两路层序遍历
bool isSymmetric(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root->left && root->right)
    {
        q.push(root->left);
        q.push(root->right);
    }
    while (!q.empty())
    {
        //判断结果
        TreeNode *left = q.front();
        q.pop();
        TreeNode *right = q.front();
        q.pop();
        if (left && right)
            return false;
        if (left || right)
            return false;
        if (left->val != right->val)
            return false;
        else
        {
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
    }
    return true;
}

//分开两边层序遍历
//这里的条件判断可以更加简化，判断同时为空跳过，单个为空的情况则直接false
bool isSymmetric(TreeNode *root)
{
    queue<TreeNode *> q;
    // if (root->left && root->right)
    // {
    q.push(root->left);
    q.push(root->right);
    // }
    while (!q.empty())
    {
        //判断结果
        TreeNode *left = q.front();
        q.pop();
        TreeNode *right = q.front();
        q.pop();
        if (left == nullptr && right == nullptr)
            continue;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        else
        {
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
    }
    return true;
}