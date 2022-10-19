// Maxflow & MinCut
// index from 0
struct Edge {
  int a,b,cap,flow;
  Edge(int _a, int _b, int _cap, int _flow) : a(_a), b(_b), cap(_cap), flow(_flow) {}
};
struct MaxFlow {
  int n, s, t;
  vi d, ptr, q;
  vt<Edge> e;
  vvi g;
  MaxFlow(int _n) : n(_n), d(_n), ptr(_n), q(_n), g(_n) {
    e.clear();
    for (int i = 0; i < n; i++) {
      g[i].clear();
      ptr[i] = 0;
  }}
  void addEdge(int a, int b, int cap) {
    g[a].pb(sz(e));
    e.eb(a,b,cap,0);
    g[b].pb(sz(e));
    e.eb(b,a,0,0);
  }
  int getMaxFlow(int _s, int _t) {
    s = _s; t = _t;
    int flow = 0;
    while(1) {
      if (!bfs()) break;
      fill(all(ptr), 0);
      while (int pushed = dfs(s, inf)) flow += pushed;
    }
    return flow;
  }
private:
  bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    fill(all(d), -1);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
      int v = q[qh++];
      for (int i = 0; i < sz(g[v]); i++) {
        int id = g[v][i], to = e[id].b;
        if (d[to] == -1 && e[id].flow < e[id].cap) {
          q[qt++] = to;
          d[to] = d[v] + 1;
    }}}
    return d[t] != -1;
  }
  int dfs (int v, int flow) {
    if (!flow) return 0;
    if (v == t) return flow;
    for (; ptr[v] < sz(g[v]); ++ptr[v]) {
      int id = g[v][ptr[v]], to = e[id].b;
      if (d[to] != d[v] + 1) continue;
      int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
      if (pushed) {
        e[id].flow += pushed;
        e[id^1].flow -= pushed;
        return pushed;
    }}
    return 0;
  }
};
