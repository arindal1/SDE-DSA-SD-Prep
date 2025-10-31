class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subset;
        vector<int> ds;
        printSubset(0, ds, subset, nums);
        return subset;
    }

    void printSubset(int ind, vector<int> &ds, vector<vector<int>> &res, vector<int> nums) {
        if (ind == nums.size()) {
            res.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        printSubset(ind + 1, ds, res, nums);
        ds.pop_back();
        printSubset(ind + 1, ds, res, nums);
    }
};