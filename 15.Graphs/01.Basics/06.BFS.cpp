#include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int V, vector<vector<int>>& adj, int start) {
    vector<bool> visited(V, false);
    vector<int> result;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return result;
}
