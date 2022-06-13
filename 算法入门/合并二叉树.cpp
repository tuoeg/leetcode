#include <iostream>

using namespace std;

//idea:使用先序遍历同时访问链表，对比root1和root2相应位置,只要子节点为空
//该种方法在原来的root1上进行修改，需要考虑很多的因素，包括需要结点进行前瞻，不太适合解决该问题

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    TreeNode *merge = new TreeNode(root1->val + root2->val);
    merge->left = mergeTrees(root1->left, root2->left);
    merge->right = mergeTrees(root1->right, root2->right);
    return merge;
}

// TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
// {
//     preorder(root1, root2, nullptr);
//     return root1;
// }

// void preorder(TreeNode *root1, TreeNode *root2, TreeNode *present, )
// {
//     //cout<<root1->val;
//     if (root1 == nullptr || root2 == nullptr)
//     {
//         //cout<<root1->val;
//         return;
//     }
//     //同时非空
//     if (root1 != nullptr && root2 != nullptr)
//     {
//         //cout<<root1->val<<root2->val<<endl;
//         root1->val = root1->val + root2->val;
//         // preorder(root1->right,root2->right);
//         // preorder(root1->left,root2->left);
//     }
//     //base为空
//     if (root1 == nullptr && root2 != nullptr)
//     {
//         //新建结点
//         root1->left = root2->left;
//         //cout<<1111;
//         //preorder(root1->right,root2->right);
//         //return;
//     }
//     if (root1->right == nullptr && root2->right != nullptr)
//     {
//         root1->right = root2->right;
//         //cout<<2222;
//         //preorder(root1->left,root2->left);
//         //return;
//     }
//     //如何root2下面的结点为空，可以不用进行处理
//     preorder(root1->left, root2->left);
//     preorder(root1->right, root2->right);
// }