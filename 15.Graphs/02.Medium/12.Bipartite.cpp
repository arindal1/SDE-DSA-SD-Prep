class Solution {
private:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = col;

        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if (dfs(it, !col, graph, color) == false)
                    return false;
            } else if (color[it] == col)
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                if (dfs(i, 0, graph, color) == false)
                    return false;
            }
        }
        return true;
    }
};