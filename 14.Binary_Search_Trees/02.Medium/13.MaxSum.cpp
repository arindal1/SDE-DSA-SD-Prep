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


class NodeValue {
public:
    int minNode, maxNode, sum;
    bool isBST;

    NodeValue(int minN, int maxN, int s, bool bst) 
        : minNode(minN), maxNode(maxN), sum(s), isBST(bst) {}
};

class Solution {
private:
    int maxSum = 0;

    NodeValue helper(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.isBST && right.isBST && root->val > left.maxNode && root->val < right.minNode) {
            int currentSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);
            
            return NodeValue(
                min(root->val, left.minNode), 
                max(root->val, right.maxNode), 
                currentSum, 
                true
            );
        }

        return NodeValue(0, 0, 0, false);
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        helper(root);
        return maxSum;
    }
};