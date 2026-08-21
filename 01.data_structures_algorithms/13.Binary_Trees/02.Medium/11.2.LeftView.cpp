class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> res;
        if (!root)
            return res;
            
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int line = q.size();
            
            for (int i = 0; i < line; ++i) {
                Node* p = q.front();
                q.pop();
                
                if (i == 0) {
                    res.push_back(p->data);
                }
                
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        return res;
    }
};