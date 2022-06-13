

// idea：使用后序dfs，并且函数返回pair<int,bool>,一个是结点value
//一个是搜索二叉树判断,后序遍历不成立，因为无法限制左侧结点最大值小于root,以及右侧结点最小值大于root
bool isValidBST(TreeNode *root)
{
    pair<int, bool> ans = dfs(root);
    return ans.second;
}

pair<int, bool> dfs(TreeNode *root)
{
    if (root == nullptr)
        return {0, true};
    pair<int, bool> left = dfs(root->left);
    pair<int, bool> right = dfs(root->right);
    if (!left.second || !right.second)
        return {0, false};
    // if (left.first < root->val && right > root->val)
    //     return {root->val, true};
    // else
    //     return {0, false};
    //左结点为空
    if (root->left == nullptr && root->right != nullptr && right.first > root->val)
    {
        return {root->val, true};
    }
    //右结点为空
    else if (root->right == nullptr && root->left != nullptr && left.first < root->val)
    {
        return {root->val, true};
    }
    //左右同时为空
    else if (root->right == nullptr && root->left == nullptr)
    {
        return {root->val, true};
    }
    else if (root->right != nullptr && root->left != nullptr && left.first < root->val && right.first > root->val)
    {
        return {root->val, true};
    }
    else
    {
        return {0, false};
    }
}

//官方idea：使用中序遍历或者递归限制当前结点的值的范围可以做到判断
// 1.中序遍历：对二叉搜索树进行中序遍历，当前结点的值一定大于左边子树
//使用栈进行遍历，不使用递归
bool dfs(TreeNode *root)
{
    stack<TreeNode *> s;
    long long min = LONG_LONG_MIN;
    while (!s.empty() || root != nullptr)
    {
        //左子树全部入栈
        while (root != nullptr)
        {
            // cout<<root->val;
            s.push(root);
            root = root->left;
        }
        //出栈
        TreeNode *node = s.top();
        s.pop();
        if (node->val <= min)
            return false;
        min = node->val;
        // s.push(node->right);
        root = node->right;
    }
    return true;
}
//用栈实现先序递归
