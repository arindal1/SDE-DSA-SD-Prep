class Solution {
public:
    vector<int> kthSmallest(TreeNode* root, int k) {
        if (!root || k <= 0) return {-1, -1};

        int res1 = -1, res2 = -1;
        int k1 = k, k2 = k;

        kmin(root, k1, res1);
        kmax(root, k2, res2);

        return {res1, res2};
    }

private:
    void kmin(TreeNode* root, int& k, int& res) {
        if (!root || k == 0) return;

        kmin(root->left, k, res);

        if (--k == 0) {
            res = root->val;
            return;
        }

        kmin(root->right, k, res);
    }

    void kmax(TreeNode* root, int& k, int& res) {
        if (!root || k == 0) return;

        kmax(root->right, k, res);

        if (--k == 0) {
            res = root->val;
            return;
        }

        kmax(root->left, k, res);
    }
};