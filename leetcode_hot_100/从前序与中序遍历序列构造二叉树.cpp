
#include <iostream>
#include <vector>
using namespace std;
//二叉树构造
// idea：使用前序遍历数组切割中序遍历数组，将左右子树分隔开，
//单独只剩下一个数便可以创建node(遇到的问题，前序遍历中左右子树如何进行分隔)
//官方答案使用中序遍历中间结点求左右子树长度，并在前序子树数组中进行分隔
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int begin = 0;
    int end = inorder.size() - 1;
    return dfs(preorder, 0, inorder, begin, end);
}

TreeNode *dfs(vector<int> &preorder, int left, int right, vector<int> &inoreder, int begin, int end)
{
    if (left > right)
        return nullptr;
    //搜索index对应值所在的位置
    int index = left;
    int middle = -1;
    for (int i = begin; i <= end; i++)
    {
        if (inorder[i] == preorder[index])
            middle = i;
    }
    if (middle == -1)
        return nullptr;
    TreeNode *root = new TreeNode(inorder[middle]);
    root->left = dfs(preorder, left + 1, left + middle - begin, inorder, begin, middle - 1);
    // root->left = dfs(preorder, index; inoreder, begin, middle - 1);
    root->right = dfs(preorder, left + middle - begin + 1, inorder, middle + 1, end);
    return root;
}