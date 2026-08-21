class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> deviceCounts;
        
        for (const string& row : bank) {
            int count = 0;
            for (char c : row) {
                if (c == '1')
                    count++;
            }
            if (count > 0)
                deviceCounts.push_back(count);
        }

        int totalBeams = 0;
        for (int i = 1; i < deviceCounts.size(); ++i) {
            totalBeams += deviceCounts[i - 1] * deviceCounts[i];
        }

        return totalBeams;
    }
};