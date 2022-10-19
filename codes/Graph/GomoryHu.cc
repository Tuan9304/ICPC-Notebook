// - When i -> j is not connected, answer[i][j] = INF
// - Used together with MaxFlowDinic.h
/*
 * Find min cut between every pair of vertices using N max_flow call (instead of N^2)
 * Not tested with directed graph
 * Index start from 0
 */
const int MN = /* n_max */;
struct GomoryHu {
  int ok[MN],cap[MN][MN],answer[MN][MN],parent[MN],n;
  MaxFlow flow;
  GomoryHu(int _n) : n(_n), flow(_n) {
    for(int i = 0; i < n; ++i) ok[i] = parent[i] = 0;
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        cap[i][j] = 0, answer[i][j] = inf;
  }
  void addEdge(int u, int v, int c) {
    cap[u][v] += c;
  }
  void calc() {
    for(int i = 1; i <= n-1; ++i) {
      flow = MaxFlow(n);
      for(int u = 0; u < n; u++) {
        for(int v = 0; v < n; v++) {
          if (cap[u][v]) flow.addEdge(u, v, cap[u][v]);
      }}
      int f = flow.getMaxFlow(i, parent[i]);
      bfs(i);
      for(int j = i + 1; j < n; ++j) {
        if (ok[j] && parent[j]==parent[i]) parent[j]=i;
      }
      answer[i][parent[i]] = answer[parent[i]][i] = f;
      for(int j = 0; j < i; ++j)
        answer[i][j]=answer[j][i]=min(f,answer[parent[i]][j]);
  }}
  void bfs(int start) {
    memset(ok,0,sizeof ok);
    queue<int> qu;
    qu.push(start);
    while (!qu.empty()) {
      int u=qu.front(); qu.pop();
      for(int xid = 0; xid < sz(flow.g[u]); ++xid) {
        int id = flow.g[u][xid], v = flow.e[id].b, fl = flow.e[id].flow, c = flow.e[id].cap;
        if (!ok[v] && fl < c) {
          ok[v] = 1;
          qu.push(v);
  }}}}
};
//   g.calc()
//   --> g.answer[i][j] = min cut i-j
