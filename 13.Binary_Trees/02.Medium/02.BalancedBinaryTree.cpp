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
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftS = dfs(root->left);
        if (leftS == -1)
            return -1;
        int rightS = dfs(root->right);
        if (rightS == -1)
            return -1;

        if (abs(leftS - rightS) > 1)
            return -1;
        return max(leftS, rightS) + 1;
    }
};