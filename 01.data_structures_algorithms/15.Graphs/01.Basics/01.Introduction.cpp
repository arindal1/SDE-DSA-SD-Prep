// graphs_reference.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;

// ------------------ DSU ------------------
struct DSU {
    vector<int> p, sz;
    DSU(int n): p(n), sz(n,1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a==b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};

// ------------------ BFS (unweighted shortest path / levels) ------------------
vector<int> bfs_levels(int src, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0; q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

// ------------------ DFS (iterative example) ------------------
void dfs_iter(int src, const vector<vector<int>>& adj, vector<int>& vis) {
    int n = adj.size();
    stack<int> st;
    st.push(src);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v : adj[u]) if (!vis[v]) st.push(v);
    }
}

// ------------------ Dijkstra (non-negative weights) ------------------
vector<ll> dijkstra(int src, const vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<ll> dist(n, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    dist[src] = 0; pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// ------------------ Bellman-Ford (detect negative cycle) ------------------
pair<vector<ll>, bool> bellman_ford(int src, int n, const vector<tuple<int,int,ll>>& edges) {
    vector<ll> dist(n, INF); dist[src] = 0;
    for (int i = 0; i < n-1; ++i) {
        bool changed = false;
        for (auto &e : edges) {
            int u,v; ll w; tie(u,v,w) = e;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w; changed = true;
            }
        }
        if (!changed) break;
    }
    // check negative cycle
    bool neg_cycle = false;
    for (auto &e : edges) {
        int u,v; ll w; tie(u,v,w) = e;
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            neg_cycle = true; break;
        }
    }
    return {dist, neg_cycle};
}

// ------------------ Kruskal (MST) ------------------
ll kruskal(int n, vector<tuple<int,int,ll>>& edges) {
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return get<2>(a) < get<2>(b); });
    DSU dsu(n);
    ll total = 0;
    for (auto &e : edges) {
        int u,v; ll w; tie(u,v,w) = e;
        if (dsu.unite(u,v)) total += w;
    }
    return total;
}

// ------------------ Prim (MST) ------------------
ll prim(int n, const vector<vector<pair<int,ll>>>& adj) {
    vector<char> used(n,false);
    vector<ll> min_e(n, INF);
    min_e[0] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0,0});
    ll res = 0;
    while (!pq.empty()) {
        auto [w,u] = pq.top(); pq.pop();
        if (used[u]) continue;
        used[u] = true; res += w;
        for (auto [v,ew] : adj[u]) {
            if (!used[v] && ew < min_e[v]) {
                min_e[v] = ew; pq.push({ew, v});
            }
        }
    }
    return res;
}

// ------------------ Topological Sort (Kahn) ------------------
vector<int> topo_kahn(int n, const vector<vector<int>>& adj) {
    vector<int> indeg(n, 0), res;
    for (int u = 0; u < n; ++u) for (int v : adj[u]) indeg[v]++;
    queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    // If res.size() < n => cycle exists
    if (res.size() < (size_t)n) return {}; // empty -> cycle
    return res;
}

// ------------------ Cycle detection (directed) using DFS 3-color ------------------
bool dfs_cycle_dir(int u, const vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1; // visiting
    for (int v : adj[u]) {
        if (color[v] == 1) return true; // back edge
        if (color[v] == 0 && dfs_cycle_dir(v, adj, color)) return true;
    }
    color[u] = 2; // visited
    return false;
}
bool has_cycle_directed(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n,0);
    for (int i = 0; i < n; ++i) if (color[i] == 0 && dfs_cycle_dir(i, adj, color)) return true;
    return false;
}

// ------------------ Example main with small tests ------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Graph reference demo\n";

    // 1) Connected components demo
    {
        int n = 5;
        vector<vector<int>> g(n);
        vector<pair<int,int>> edges = {{0,1},{1,2},{3,4}};
        for (auto &e: edges) { g[e.first].push_back(e.second); g[e.second].push_back(e.first); }
        vector<int> vis(n,0);
        int comps = 0;
        for (int i = 0; i < n; ++i) if (!vis[i]) {
            ++comps;
            dfs_iter(i, g, vis);
        }
        cout << "Connected components: " << comps << "\n"; // expect 2
    }

    // 2) Dijkstra demo
    {
        int n = 4;
        vector<vector<pair<int,int>>> adj(n);
        adj[0].push_back({1,1});
        adj[1].push_back({2,2});
        adj[0].push_back({2,4});
        // undirected: add reverse edges if needed
        auto dist = dijkstra(0, adj);
        cout << "Dijkstra dist to node 2: " << (dist[2] == INF ? -1 : dist[2]) << "\n"; // expect 3
    }

    // 3) Kruskal demo
    {
        int n = 4;
        vector<tuple<int,int,ll>> edges = {{0,1,1},{1,2,2},{2,3,3},{0,3,10}};
        cout << "Kruskal MST weight: " << kruskal(n, edges) << "\n"; // expect 6
    }

    // 4) Topological demo (dag)
    {
        int n = 6;
        vector<vector<int>> dag(n);
        dag[5] = {2,0};
        dag[4] = {0,1};
        dag[2] = {3};
        dag[3] = {1};
        auto order = topo_kahn(n, dag);
        if (order.empty()) cout << "Topological sort: cycle detected\n";
        else { cout << "Topological order: "; for (int v : order) cout << v << ' '; cout << '\n'; }
    }

    // 5) Directed cycle demo
    {
        vector<vector<int>> adj = {{1},{2},{0}}; // 0->1->2->0
        cout << "Directed cycle? " << (has_cycle_directed(adj) ? "Yes" : "No") << '\n'; // expect Yes
    }

    return 0;
}
