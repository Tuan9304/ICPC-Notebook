// 0-based
struct Data {
  int time, u, par;
};
struct DSU {
  vi par;
  vt<Data> change;
  DSU(int n) : par(n + 5, -1) {}
  int getRoot(int x) {
    while (par[x] >= 0) x = par[x];
    return x;
  }
  bool join(int x, int y, int t) {
    x = getRoot(x);
    y = getRoot(y);
    if (x == y) return 0;
    if (par[x] < par[y]) swap(x, y); 
    change.pb({t, y, par[y]});
    par[y] += par[x];
    change.pb({t, x, par[x]});
    par[x] = y;
    return 1;
  }
  void rollback(int t) {
    while (!change.empty() && change.back().time > t) {
      par[change.back().u] = change.back().par;
      change.pop_back();
    }
  }
};
