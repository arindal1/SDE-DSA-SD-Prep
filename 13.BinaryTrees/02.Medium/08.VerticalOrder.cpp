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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto q = todo.front();
            todo.pop();

            TreeNode* p = q.first;
            int x = q.second.first;
            int y = q.second.second;

            nodes[x][y].insert(p->val);

            if (p->left)
                todo.push({p->left, {x - 1, y + 1}});
            if (p->right)
                todo.push({p->right, {x + 1, y + 1}});
        }

        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};