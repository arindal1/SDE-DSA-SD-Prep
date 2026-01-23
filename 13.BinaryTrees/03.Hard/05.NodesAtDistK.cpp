/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root)
            return {};

        unordered_map<TreeNode*, TreeNode*> parentMap;
        findParentMap(root, parentMap);

        return findNodes(target, parentMap, k);
    }

    void findParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> findNodes(TreeNode* &target, unordered_map<TreeNode*, TreeNode*>& parentMap, int k) {
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        int steps = 0;

        while(!q.empty()) {
            int line = q.size();

            if (steps++ == k)
                break;

            for (int i = 0; i < line; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (parentMap.count(node) && (vis.find(parentMap[node]) == vis.end())) {
                    vis.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
                if (node->left && (vis.find(node->left) == vis.end())) {
                    vis.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && (vis.find(node->right) == vis.end())) {
                    vis.insert(node->right);
                    q.push(node->right);
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};