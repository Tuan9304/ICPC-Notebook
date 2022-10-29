// Find all cycles of length 3 (a.k.a. triangles)
// Complexity: O(N + M*sqrt(M))
// Index from 0
vt<tuple<int,int,int>> find_all_triangles(int n, vii edges) {
  uniq(edges);
  vi deg(n, 0);
  for (const auto& [u, v] : edges) {
    if (u == v) continue;
    ++deg[u], ++deg[v];
  }
  vvi adj(n);
  for (auto [u, v] : edges) {
    if (u == v) continue;
    if (deg[u] > deg[v] || (deg[u] == deg[v] && u > v)) swap(u, v);
    adj[u].pb(v);
  }
  // If it's too slow, remove vector res and compute answer directly
  vt<tuple<int,int,int>> res;
  vt<bool> good(n, 0);
  for (int i = 0; i < n; i++) {
    for (auto j : adj[i]) good[j] = 1;
    for (auto j : adj[i]) {
      for (auto k : adj[j]) {
        if (good[k]) res.eb(i, j, k);
      }
    }
    for (auto j : adj[i]) good[j] = 0;
  }
  return res;
}

