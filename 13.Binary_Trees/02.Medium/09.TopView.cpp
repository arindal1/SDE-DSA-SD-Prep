vector<int> topView(Node* root) {
    vector<int> res;
    if (!root)
        return res;

    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* n = p.first;
        int line = p.second;

        if (mpp.find(line) == mpp.end())
            mpp[line] = n->val;

        if (n->left)
            q.push({n->left, line - 1});
        if (n->right)
            q.push({n->right, line + 1});
    }

    for (auto it : mpp)
        res.push_back(it.second);

    return res;
}