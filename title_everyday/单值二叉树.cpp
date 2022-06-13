bool isUnivalTree(TreeNode *root)
{
    int value = root->val;
    dfs(root, value);
}

bool dfs(TreeNode *root, int value)
{
    if (root == nullptr)
        return true;
    if (root->val != value)
        return false;
    return dfs(root->left) && dfs(root->right);
}