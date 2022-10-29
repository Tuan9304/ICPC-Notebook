// Tree diameter (weighted): farthest u->v
// Index from 0
// Return {length, path}
using ll = long long;
pair<ll, vi> get_diameter(const vt<vii>& g) {
  int n = sz(g);
  vector<ll> dist(n);
  vi parent(n);
  function<void(int, int, ll)> dfs = [&] (int u, int fu, ll cur_dist) {
    dist[u] = cur_dist;
    parent[u] = fu;
    for (auto [v, cost] : g[u]) if (v != fu) {
      dfs(v, u, cur_dist + cost);
    }
  };
  dfs(0, -1, 0);
  // r = furthest node from root
  int r = max_element(dist.begin(), dist.end()) - dist.begin();
  dfs(r, -1, 0);
  // r->s = longest path
  int s = max_element(dist.begin(), dist.end()) - dist.begin();
  vi path;
  for (int x = s; x >= 0; x = parent[x]) path.pb(x);
  return {dist[s], path};
}

