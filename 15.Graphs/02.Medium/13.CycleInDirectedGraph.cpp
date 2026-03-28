class Solution {
  private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path) {
        vis[node] = 1;
        path[node] = 1;
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, path))
                    return true;
            } 
            else if (path[it]) {
                return true;
            }
        }
        
        path[node] = 0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, path))
                    return true;
            }
        }
        
        return false;
    }
};