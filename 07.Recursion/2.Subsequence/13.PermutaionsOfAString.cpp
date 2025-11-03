class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        permutations(0, nums, res);
        return res;
    }

    void permutations(int ind, vector<int> &nums, vector<vector<int>> &res) {
        if (ind == nums.size()) {
            vector<int> ds;
            for (int i = 0; i < nums.size(); i++) {
                ds.push_back(nums[i]);
            }
            res.push_back(ds);
            return;
        }

        for (int i = ind; i < nums.size(); i++) {
            swap(i, ind, nums);
            permutations(ind + 1, nums, res);
            swap(i, ind, nums);
        }
    }

    void swap(int i, int j, vector<int> &nums) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};