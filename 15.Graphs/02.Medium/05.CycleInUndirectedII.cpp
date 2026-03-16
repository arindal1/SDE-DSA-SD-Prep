#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool detectDFS(int node, int parent, vector<int> &vis, const vector<vector<int>> &adj) {
        vis[node] = 1;

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (detectDFS(neighbor, node, vis, adj))
                    return true;
            } else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }

public:
    bool isCycle(int V, const vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detectDFS(i, -1, vis, adj))
                    return true;
            }
        }

        return false;
    }
};
