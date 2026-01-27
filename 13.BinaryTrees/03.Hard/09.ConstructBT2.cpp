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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())
            return nullptr;
        map<int, int> mpp;

        for (int i = 0; i < inorder.size(); ++i) {
            mpp[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int poStart, int poEnd, map<int, int> &mpp) {
        if (inStart > inEnd || poStart > poEnd)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[poEnd]);
        int indRoot = mpp[postorder[poEnd]];
        int numLeft = indRoot - inStart;

        root->left = build(inorder, inStart, indRoot - 1, postorder, poStart, numLeft + poStart - 1, mpp);
        root->right = build(inorder, indRoot + 1, inEnd, postorder, poStart + numLeft, poEnd - 1, mpp);

        return root;
    }
};