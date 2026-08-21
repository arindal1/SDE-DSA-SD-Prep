// Improved BFS-based cycle detection for undirected graph
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool detectBFS(int src, const vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int,int>> q;
        vis[src] = 1;
        q.push({src, -1});

        while (!q.empty()) {
            auto [node, parent] = q.front(); q.pop();
            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    // visited and not the parent -> cycle
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, const vector<vector<int>>& edges) {
        // build adjacency list
        vector<vector<int>> adj(V);
        for (const auto &e : edges) {
            if (e.size() < 2) continue; // defensive
            int u = e[0], v = e[1];
            // If input is 1-indexed, convert with u--, v--
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                if (detectBFS(i, adj, vis)) return true;
            }
        }
        return false;
    }
};