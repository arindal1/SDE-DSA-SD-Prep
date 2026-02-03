class Solution {
public:
    int findMin(TreeNode* root) {
        if (!root) return -1; // or throw error
        
        while (root->left != nullptr) {
            root = root->left;
        }
        return root->val;
    }

    int findMax(TreeNode* root) {
        if (!root) return -1; // or throw error
        
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->val;
    }
};
