void checkChild (TreeNode* root) {
    if (!root)
        return;

    int child = 0;
    if (root->left)
        child += root->left->val;
    if (root->right)
        child += root->right->val;

    if (child > root->val)
        root->val = child;
    else {
        if (root->left)
            root->left->val = root->val;
        else if (root->right)
            root->right->val = root->val;
    }

    checkChild(root->left);
    checkChild(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->val;
    if (root->right)
        tot += root->right->val;

    if (root->right || root->left)
        root->val = tot;
}