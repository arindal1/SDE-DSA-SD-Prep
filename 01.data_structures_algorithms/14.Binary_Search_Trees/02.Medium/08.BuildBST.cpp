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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST(preorder, i, INT_MAX);
    }

    TreeNode* buildBST(vector<int>& arr, int& i, int bound) {
        if (i == arr.size() || arr[i] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(arr[i++]);
        root->left = buildBST(arr, i, root->val);
        root->right = buildBST(arr, i, bound);

        return root;
    }
};