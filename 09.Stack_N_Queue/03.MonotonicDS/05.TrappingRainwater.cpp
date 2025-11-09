int trap(vector<int>& height) {
    stack<int> st;
    int totalSum = 0, l = 0, r = height.size() - 1;
    int maxL = 0, maxR = 0;
    while (l <= r) {
        if (height[l] <= height[r]) {
            if (maxL >= height[l])
                totalSum += maxL - height[l];
            else
                maxL = height[l];
            l++;
        } else {
            if (maxR > height[r])
                totalSum += maxR - height[r];
            else
                maxR = height[r];
            r--;
        }
    }
    return totalSum;
}
