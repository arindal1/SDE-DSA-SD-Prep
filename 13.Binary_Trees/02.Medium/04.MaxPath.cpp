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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        path(root, maxi);
        return maxi;
    }

    int path(TreeNode* root, int &maxi) {
        if (root == nullptr)
            return 0;

        int leftS = max(0, path(root->left, maxi));
        int rightS = max(0, path(root->right, maxi));

        maxi = max(maxi, root->val + leftS + rightS);

        return root->val + max(leftS, rightS);
    }
};