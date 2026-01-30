class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> dist;

        for (auto& p : points) {
            int d = p[0] * p[0] + p[1] * p[1];
            dist.push({d, p});

            if (dist.size() > k)
                dist.pop();
        }

        vector<vector<int>> res;
        while (!dist.empty()) {
            res.push_back(dist.top().second);
            dist.pop();
        }
        return res;
    }
};