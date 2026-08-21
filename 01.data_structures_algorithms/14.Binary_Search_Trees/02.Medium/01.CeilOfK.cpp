int findCeil(Node* root, int k) {
    if (!root)
        return -1;

    int ceil = -1;
    while (root) {
        if (root->val == k) {
            ceil = root->val;
            return ceil;
        }

        if (k > root->val) {
            root = root->right;
        } else {
            ceil = root->val;
            root = root->left;
        }
    }

    return ceil;
} 
