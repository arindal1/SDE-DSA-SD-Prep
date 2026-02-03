/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
            
        int left = root->left ? root->left->data : 0;
        int right = root->right ? root->right->data : 0;
            
        return ((root->data == left + right) && isSumProperty(root->left) && isSumProperty(root->right));
    }
};