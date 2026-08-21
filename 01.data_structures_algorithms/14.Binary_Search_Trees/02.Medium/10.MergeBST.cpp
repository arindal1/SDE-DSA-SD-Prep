class Solution {
public:
    void inorderTraversal(Node* root, vector<int>& arr) {
        if (!root) return;
        inorderTraversal(root->left, arr);
        arr.push_back(root->data);
        inorderTraversal(root->right, arr);
    }

    vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) merged.push_back(arr1[i++]);
            else merged.push_back(arr2[j++]);
        }
        while (i < arr1.size()) merged.push_back(arr1[i++]);
        while (j < arr2.size()) merged.push_back(arr2[j++]);
        return merged;
    }

    vector<int> mergeBSTs(Node* root1, Node* root2) {
        vector<int> arr1, arr2;
        inorderTraversal(root1, arr1);
        inorderTraversal(root2, arr2);
        return mergeArrays(arr1, arr2);
    }
};