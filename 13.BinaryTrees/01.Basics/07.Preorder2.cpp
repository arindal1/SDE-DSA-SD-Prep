class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        
        if(root == nullptr) {
            return preorder;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            root = st.top();
            st.pop();
            
            preorder.push_back(root->val);
            
            if(root->right != nullptr) {
                st.push(root->right);
            }
            
            if(root->left != nullptr) {
                st.push(root->left);
            }
        }
        
        return preorder;
    }
};
