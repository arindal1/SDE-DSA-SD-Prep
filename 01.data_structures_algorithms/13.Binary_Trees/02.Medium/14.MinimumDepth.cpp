/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        return minD(root);
    }

private:
    int minD(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int leftS = minD(root->left);
        int rightS = minD(root->right);

        if (leftS && rightS)
            return min(leftS, rightS) + 1;

        return max(leftS, rightS) + 1;
    }
};