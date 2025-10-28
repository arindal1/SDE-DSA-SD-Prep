class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;

        combination(0, candidates, target, ds, res);
        return res;
    }

    void combination(int ind, vector<int> arr, int target, vector<int> &ds, vector<vector<int>> &res) {
        if (ind == arr.size()) {
            if (target == 0) {
                res.push_back(ds);
            }
            return;
        }

        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            combination(ind, arr, target - arr[ind], ds, res);
            ds.pop_back();
        }

        combination(ind + 1, arr, target, ds, res);
    }
};