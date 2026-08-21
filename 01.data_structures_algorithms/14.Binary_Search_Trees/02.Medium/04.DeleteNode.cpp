class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Node found

            // Case 1 & 2: 0 or 1 child
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;

            // Case 3: 2 children
            TreeNode* successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left)
            node = node->left;
        return node;
    }
};
