class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        dfsHelper(0, visited, ans, adj);
        return ans;
    }
    
    void dfsHelper(int node, vector<bool>& vis, vector<int>& ans, vector<vector<int>>& adj) {
        vis[node] = true;
        ans.push_back(node);
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsHelper(it, vis, ans, adj);
            }
        }
    }
};