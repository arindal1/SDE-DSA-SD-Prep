class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ds;

        combination(0, candidates, target, ds, res);
        return res;
    }

    void combination(int ind, vector<int> &arr, int target, vector<int> &ds, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i-1])
                continue;
            if (arr[i] > target) 
                break;
            
            ds.push_back(arr[i]);
            combination(i + 1, arr, target - arr[i], ds, res);
            ds.pop_back();
        }
    }
};