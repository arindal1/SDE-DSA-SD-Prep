class NodeValue {
public:
    int minNode, maxNode, maxSize;

    NodeValue(int minN, int maxN, int size) 
        : minNode(minN), maxNode(maxN), maxSize(size) {}
};

class Solution {
private:
    NodeValue helper(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = helper(root->left);
        auto right = helper(root->right);

        if (left.maxNode < root->val && root->val < right.minNode) {
            return NodeValue(
                min(root->val, left.minNode), 
                max(root->val, right.maxNode), 
                left.maxSize + right.maxSize + 1
            );
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        return helper(root).maxSize;
    }
};