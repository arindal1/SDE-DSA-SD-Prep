class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, n = bills.size();

        for (int i = 0; i < n; ++i) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                if (five) {
                    five--;
                    ten++;
                } else
                    return false;
            } else {
                if (five && ten) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};