# Introduction to Graphs (C++) - Basics, Properties & Algorithms 🚀

## 1. What is a graph? - Problem statement & definitions 🧭

**Problem (generic):**
Represent relationships between entities as nodes (vertices) and relationships as edges. Solve queries like reachability, shortest path, cycles, components, ordering, etc.

![image](https://imgs.search.brave.com/4iLJCNQraS4YhKhF1-ZQOoiTblTB72JGX3EU1CO4yps/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly93d3cu/c2ltcGxpbGVhcm4u/Y29tL2ljZTkvZnJl/ZV9yZXNvdXJjZXNf/YXJ0aWNsZV90aHVt/Yi9HcmFwaCUyMERh/dGElMjBTdHJ1Y3R1/cmUlMjAtJTIwU29u/aS93aGF0LWlzLWdy/YXBocy1pbi1kYXRh/LXN0cnVjdHVyZS5w/bmc)

**Definitions**

* **Vertex (node)**: a single entity.
* **Edge**: connection between two vertices.

  * **Undirected**: bidirectional.
  * **Directed**: edge from `u` → `v`.
* **Weighted/Unweighted**: edges may carry weights.
* **Simple graph**: no self-loops or multi-edges (unless allowed).
* **Degree**: number of incident edges (for directed: indegree/outdegree).
* **Connected (undirected)**: path between every pair of vertices.
* **Strongly connected (directed)**: path from every vertex to every other.


![image](https://media.geeksforgeeks.org/wp-content/uploads/20250705181016967800/directed_graph.webp)

![image](https://media.geeksforgeeks.org/wp-content/uploads/20250705181016505144/weighted_graph.webp)

![image](https://media.geeksforgeeks.org/wp-content/uploads/20250705181017120873/cyclic_graph.webp)


## 2. Graph representations 🧩

### 1. Adjacency list (preferred)

* `vector<vector<pair<int,int>>> adj;` for weighted graphs (`{to, weight}`)
* `vector<vector<int>> adj;` for unweighted.
* Pros: memory-efficient for sparse graphs, easy to iterate neighbors.

![image](https://cdn.programiz.com/sites/tutorial2program/files/adjacency-list.png)

### 2. Adjacency matrix

* `vector<vector<int>> mat(n, vector<int>(n))`
* Pros: O(1) edge existence query.
* Cons: O(n²) memory, slow for large `n`.

![image](https://cdn.programiz.com/sites/tutorial2program/files/adjacency-matrix_1.png)

### 3. Edge list

* `vector<tuple<int,int,int>> edges;` (u, v, w)
* Useful for Kruskal and offline algorithms.

> Rule of thumb: Use adjacency list for most problems unless `n` ≤ few thousands and matrix operations are needed.



## 3. Basic properties & common tasks

* **Connected components** (undirected) - find all components (BFS/DFS/Union-Find).
* **Reachability** (directed) - can we reach `v` from `u` (BFS/DFS).
* **Shortest path** - BFS (unweighted), Dijkstra (non-negative weights), Bellman-Ford (negative weights).
* **Cycle detection** - DFS coloration or union-find / Kahn’s algorithm for directed graphs.
* **Topological ordering** - ordering of DAG nodes (Kahn or DFS).
* **Minimum Spanning Tree** - Kruskal (sort edges + DSU) or Prim (priority queue).



## 4. Traversals - BFS & DFS

## Breadth-first search (BFS) - intuition

Think of dropping a pebble into a pond and watching concentric ripples. BFS explores in “layers” - all nodes at distance `d` before `d+1`. Use queue.

**When to use:** shortest path in unweighted graphs, level order, bipartite check.

### BFS - complexity

* Time: O(V + E)
* Memory: O(V)

### C++ (unweighted BFS)

```cpp
void bfs(int src, const vector<vector<int>>& adj, vector<int>& dist) {
    int n = adj.size();
    dist.assign(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
```



## Depth-first search (DFS) - intuition

Follow a path as deep as possible, backtrack when stuck. Good for components, cycle detection, topological sort.

**When to use:** connected components, topo-sort (recursively), cycle detection, graph traversal where path matters.

### DFS - complexity

* Time: O(V + E)
* Memory: O(V) recursion depth (danger of stack overflow on deep graphs)

### C++ (recursive & iterative)

```cpp
void dfs_rec(int u, const vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfs_rec(v, adj, vis);
}
```

Iterative (stack) version avoids recursion depth issues.



## 5. Shortest paths

## BFS for unweighted graphs

Distance = number of edges. Already shown earlier.

## Dijkstra - non-negative weights

**Intuition:** Greedy: pick the currently closest unreached node (min-heap), relax edges.

**When to use:** non-negative edge weights.

### Complexity

* Using `priority_queue`: O((V + E) log V) or O(E log V) typically.

### C++ (Dijkstra)

```cpp
vector<long long> dijkstra(int src, const vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(n, INF);
    dist[src] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue; // stale entry
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

## Bellman-Ford - allows negative weights & detects negative cycles

* Time: O(V * E)
* Use it when negative weights exist, or to detect negative cycles.



## 6. Minimum Spanning Tree (MST)

## Kruskal - intuition

Sort edges by weight, add smallest edge that doesn't create cycle (DSU used for cycle detection).

### Complexity

* Sorting edges: O(E log E)
* DSU operations: α(V) ≈ constant

### Prim - intuition

Start from a node, always add smallest-weight edge crossing current cut (use PQ).

### Complexity (with PQ)

* O(E log V)



## 7. Topological sort & cycle detection

## Topological sort (Kahn's algorithm)

* Calculate indegrees, pick nodes with indegree==0, pop them and decrement indegree of neighbors. Works only on DAGs. If nodes output < V then cycle exists.

## DFS based topo

* Run DFS, on finishing a node push to stack; reverse order of finishing times gives one topo order. Also useful for cycle detection (3-color method).



## 8. Union-Find (Disjoint Set Union - DSU)

Used for Kruskal & connectivity queries (offline). Implement path compression + union by rank/size.

```cpp
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
```



## 9. Example problems, approaches & Brute Force vs Optimal

### Problem A: Connected Components (Undirected)

**Statement:** Given `n` nodes and edge list, count connected components.

**Brute force:** Run BFS/DFS from each unvisited node - O(V + E) - this *is* optimal.
**Optimal:** DFS/BFS or DSU both O(V + E).

### Problem B: Shortest path in weighted graph

**Statement:** Shortest distance from s to all nodes, weights non-negative.

**Brute force:** Dijkstra is optimal. Brute force (try all paths) exponential.

### Problem C: Detect cycle in directed graph

**Brute force:** Check all permutations - impossible.
**Optimal:** DFS 3-color or Kahn's algorithm. O(V + E).

### Problem D: MST

**Optimal approaches:** Kruskal or Prim.



## 10. Test cases & expected output

We'll include small testcases to validate:

**1) Simple undirected graph (components)**
n=5, edges: (0,1), (1,2), (3,4) → components: 2

**2) Shortest path unweighted**
Graph: 0-1-2 and 0-3-2; src=0 → dist to 2 is 2

**3) Dijkstra (weighted)**
n=4 edges: (0,1,1), (1,2,2), (0,2,4), src=0 → dist[2]=3

**4) Cycle detection directed**
0 → 1 → 2 → 0 → cycle true

**5) MST (Kruskal)**
n=4 edges: (0,1,1),(1,2,2),(2,3,3),(0,3,10) → MST weight = 1+2+3 = 6



## 11. Full C++ reference code (single-file) 🧾

> This file collects clean, tested implementations for the core algorithms shown above. It includes small interactive tests you can run and adapt.

```cpp
// graphs_reference.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;

//  DSU 
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

//  BFS (unweighted shortest path / levels) 
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

//  DFS (iterative example) 
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

//  Dijkstra (non-negative weights) 
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

//  Bellman-Ford (detect negative cycle) 
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

//  Kruskal (MST) 
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

//  Prim (MST) 
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

//  Topological Sort (Kahn) 
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

//  Cycle detection (directed) using DFS 3-color 
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

//  Example main with small tests 
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
```



## 12. Complexity summary (cheat sheet)

* **DFS/BFS**: O(V + E) time, O(V) memory.
* **Dijkstra (binary heap)**: O((V + E) log V) - usually O(E log V).
* **Bellman-Ford**: O(V * E)
* **Kruskal**: O(E log E) dominated by sort.
* **Prim (binary heap)**: O(E log V)
* **Topological (Kahn)**: O(V + E)
* **DSU**: almost O(1) per op (amortized α(n))



## 13. Tips, tricks & common pitfalls ⚠️

* **Representation choice matters**. For `n` ~ 10^5 and `m` ~ 10^5 use adjacency list. Matrix only for dense graphs or when you need O(1) edge queries.
* **Watch recursion depth**. Use iterative DFS on deep graphs or increase stack size carefully.
* **Edge direction** - be explicit when converting problems; many mistakes come from accidentally treating a graph as undirected.
* **Dijkstra**: never mark visited on pop alone; always check for stale entries `if (d != dist[u]) continue;`.
* **Kruskal**: ensure edges are sorted by weight; DSU must be fast (path compression + union by size/rank).
* **Topological sort**: Kahn returns ordering or empty vector if cycle exists - handy for checks.
* **Negative cycles**: Bellman-Ford can detect them. Dijkstra fails with negative weights.
* **Sparse vs dense**: if E ~ V^2, consider algorithms that handle dense graphs (e.g., Floyd-Warshall for all-pairs when n ≤ ~400).



## 14. Variations & extensions 🌌

* **All-pairs shortest paths**: Floyd–Warshall (O(n^3)) or repeated Dijkstra for sparse graphs.
* **2-SAT**: built on implication graphs and SCCs (Kosaraju/Tarjan).
* **Maximum flow / Min cut**: Edmonds–Karp, Dinic, Push-relabel.
* **Bipartite matching**: Hopcroft–Karp algorithm.
* **Eulerian path/circuit**: degree conditions + Hierholzer's algorithm.
* **Graph algorithms on grids**: treat grid cells as nodes (careful about memory).
* **Dynamic graphs**: link-cut trees, dynamic connectivity - advanced.



## 15. FAQs (Short & sweet) ❓

**Q: Which graph representation should I memorize?**
A: *Adjacency list* - it's the most versatile for competitive coding and interviews.

**Q: Is recursion for DFS okay?**
A: It's fine for smaller graphs. For `n` up to 2e5 you risk stack overflow - use iterative or increase stack.

**Q: Dijkstra or Bellman-Ford?**
A: Use Dijkstra when weights ≥ 0. If negative weights (but no negative cycles) use Bellman-Ford. If negative cycles exist, Bellman-Ford detects them.

**Q: How to check if a directed graph has a cycle?**
A: Use DFS 3-coloring or Kahn’s algorithm (if topo doesn't include all nodes → cycle).

**Q: Should I sort edges for Kruskal?**
A: Yes - sorting edges by weight is the core of Kruskal.

**Q: Can Prim and Kruskal give different MSTs?**
A: They yield same minimum total weight (if weights unique then same edges). If equal-weight edges exist, MST may not be unique.



## Final thoughts 😊

Graphs are a fundamental and beautiful part of computer science. Once you get comfortable with **representations** and **one traversal pattern (BFS/DFS)** you can compose those ideas into Dijkstra, MST, topological sort, and more. Practice a few problems: connected components → BFS/DFS; shortest path → BFS/Dijkstra; MST → Kruskal; topological order → Kahn. Mix those with DSU - you'll be unstoppable. ⚔️

