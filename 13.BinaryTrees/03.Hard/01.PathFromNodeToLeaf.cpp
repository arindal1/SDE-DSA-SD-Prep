#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool findPath(TreeNode* root, int k, vector<int>& path) {
    if (!root)
        return false;

    path.push_back(root->val);

    if (root->val == k)
        return true;

    if (findPath(root->left, k, path) || 
        findPath(root->right, k, path))
        return true;

    path.pop_back(); // backtrack
    return false;
}



// Main function to run the code
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int targetLeafValue = 7;
    vector<int> path;
    findPath(root, targetLeafValue, path);

    // Print the path
    cout << "Path from root to node with value ";
    cout << targetLeafValue << ": ";

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;
}
