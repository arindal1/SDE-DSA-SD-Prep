class Solution {
    multiset<long long> low, high;
    long long sumLow = 0;
    int k_minus_1;

    void add(int x) {
        low.insert(x);
        sumLow += x;
        if (low.size() > k_minus_1) {
            long long val = *low.rbegin();
            sumLow -= val;
            high.insert(val);
            low.erase(prev(low.end()));
        }
    }

    void remove(int x) {
        auto it = low.find(x);
        if (it != low.end()) {
            sumLow -= x;
            low.erase(it);
            if (low.size() < k_minus_1 && !high.empty()) {
                long long val = *high.begin();
                sumLow += val;
                low.insert(val);
                high.erase(high.begin());
            }
        } else {
            high.erase(high.find(x));
        }
    }

public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        k_minus_1 = k - 1;
        sumLow = 0;
        low.clear();
        high.clear();
        
        for (int i = 1; i <= dist + 1; ++i) {
            add(nums[i]);
        }
        
        long long minCost = nums[0] + sumLow;
        
        for (int i = 1; i + dist + 1 < n; ++i) {
            remove(nums[i]);
            add(nums[i + dist + 1]);
            minCost = min(minCost, nums[0] + sumLow);
        }
        
        return minCost;
    }
};