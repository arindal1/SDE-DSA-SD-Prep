class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        if (!root)
            return -1;

        int floor = -1;
        while (root) {
            if (root->data == x) {
                floor = root->data;
                return floor;
            }
    
            if (x < root->data) {
                root = root->left;
            } else {
                floor = root->data;
                root = root->right;
            }
        }
    
        return floor;
    }
};