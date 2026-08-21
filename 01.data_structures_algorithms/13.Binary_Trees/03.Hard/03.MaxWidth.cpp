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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int maxWidth = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int line = q.size();
            long long minInd = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < line; ++i) {
                long long curInd = q.front().second - minInd;
                TreeNode* p = q.front().first;
                q.pop();

                if (i == 0)
                    first = curInd;
                if (i == line - 1)
                    last = curInd;

                if (p->left)
                    q.push({p->left, 2 * curInd + 1});
                if (p->right)
                    q.push({p->right, 2 * curInd + 2});
            }
            maxWidth = max(maxWidth, (int)(last - first + 1));
        }
        return maxWidth;
    }
};