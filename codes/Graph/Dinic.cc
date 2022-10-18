// Maximum flow & Minimum Cut
struct FlowEdge {
  int v, u;
  ll cap, flow = 0;
  FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};
struct Dinic {
  vt<FlowEdge> edges;
  vvi adj;
  int n, m = 0, s, t;
  vi level, ptr;
  queue<int> q;
  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }
  void add_edge(int v, int u, ll cap) {
    edges.eb(v, u, cap);
    edges.eb(u, v, 0);
    adj[v].pb(m);
    adj[u].pb(m + 1);
    m += 2;
  }
  bool bfs() {
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : adj[v]) {
        if (edges[id].cap - edges[id].flow < 1) continue;
        if (level[edges[id].u] != -1) continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }
  ll dfs(int v, ll pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    for (int& cid = ptr[v]; cid < sz(adj[v]); cid++) {
      int id = adj[v][cid], u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1) continue;
      ll tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0) continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }
  ll flow() {
    ll f = 0;
    while (1) {
      fill(all(level), -1);
      if (!bfs()) break;
      fill(all(ptr), 0);
      while (ll pushed = dfs(s, flow_inf)) f += pushed;
    }
    return f;
  }
};
