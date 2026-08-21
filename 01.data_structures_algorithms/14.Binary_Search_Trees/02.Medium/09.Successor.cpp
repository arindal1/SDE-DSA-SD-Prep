    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pred = nullptr;
        Node* succ = nullptr;
        Node* node = root;
    
        while (node) {
            if (key < node->data) {
                succ = node;
                node = node->left;
            } else if (key > node->data) {
                pred = node;
                node = node->right;
            } else {
                // found exact node
                if (node->left) {
                    Node* t = node->left;
                    while (t->right) t = t->right;
                    pred = t;
                }
                if (node->right) {
                    Node* t = node->right;
                    while (t->left) t = t->left;
                    succ = t;
                }
                break;
            }
        }
        return {pred, succ};
    }