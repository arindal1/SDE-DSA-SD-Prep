/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if (root == nullptr)
            return res;
        if (!isLeaf(root))
            res.push_back(root->data);
            
        boundLeft(root, res);
        leaves(root, res);
        boundRight(root, res);
        return res;
    }

private:
    bool isLeaf(Node* root) {
        if (root->left == nullptr && root->right == nullptr)
            return true;
        else return false;
    }
    
    void boundLeft(Node* root, vector<int> &res) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur))
                res.push_back(cur->data);
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    
    void boundRight(Node* root, vector<int> &res) {
        Node* cur = root->right;
        vector<int> temp;
        while (cur) {
            if (!isLeaf(cur))
                temp.push_back(cur->data);
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }
    
    void leaves(Node* root, vector<int> &res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
            
        if (root->left)
            leaves(root->left, res);
        if (root->right)
            leaves(root->right, res);
    }
};