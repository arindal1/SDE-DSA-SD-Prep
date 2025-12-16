#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    static bool comp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

    double fractionKnap(int W, Item arr[], int n) {
        sort(arr, arr + n, comp);

        int curWeight = 0;
        double finalValue = 0.0;

        for (int i = 0; i < n; ++i) {
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalValue += arr[i].value;
            } else {
                int remain = W - curWeight;
                finalValue += ((double)arr[i].value / arr[i].weight) * remain;
                break;
            }
        }

        return finalValue;
    }
};

int main() {
    int n = 3, weight = 50;
    Item arr[n] = {{100,20},{60,10},{120,30}};
    Solution obj;

    double ans = obj.fractionKnap(weight, arr, n);
    cout << fixed << setprecision(2);
    cout << "The maximum value is: " << ans << endl;

    return 0;
}