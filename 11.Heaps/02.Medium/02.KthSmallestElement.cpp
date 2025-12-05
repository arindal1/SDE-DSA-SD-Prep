class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for (int num : nums) {
            maxHeap.push(num);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        return maxHeap.top();
    }
};