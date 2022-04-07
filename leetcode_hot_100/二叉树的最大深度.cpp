#include <iostream>
using namespace std;

//基本idea:可以选用任意一种遍历方式，在递归跳出条件中判断最大的深度
int maxDepth(TreeNode *root)
{
    //返回最大深度
    return middle_order(root);
}

int middle_order(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    //可以使用max函数直接进行比较
    int num1 = middle_order(root->left) + 1;
    int num2 = middle_order(root->right) + 1;
    return num1 > num2 ? num1 : num2;
}
