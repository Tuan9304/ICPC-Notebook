// L[i] = level
// L[root] = -1
// LCA[0][root] = -1
const int MN = 100111;
int V, LCA[22][MN], L[MN];
ll Rmax[22][MN];
void initLCA () {
  for(int lg = 1; i <= 19;i ++) {
    for(int i = 0; i < V; i++) {
      if (LCA[lg - 1][i] == -1) continue;
      LCA[lg][i] = LCA[lg - 1][LCA[lg - 1][i]];
      Rmax[lg][i] = max (Rmax[lg - 1][LCA[lg - 1][i]], Rmax[lg - 1][i]);
    }
  }
}
ll query (ll a, ll b) {
  ll ret = 0;
  if (L[a] < L[b]) swap (a, b);
  for(int lg = 19; lg >= 0; lg--) {
    if (LCA[lg][a] != -1 && L[LCA[lg][a]] >= L[b]) {
      ret = max(ret, Rmax[lg][a]);
      a = LCA[lg][a];
    }
  }
  if (a == b) return ret;
  for(int lg = 19; lg >= 0; lg--) {
    if (LCA[lg][a] != LCA[lg][b]) {
      ret = max(ret, Rmax[lg][a]);
      ret = max(ret, Rmax[lg][b]);
      a = LCA[lg][a];
      b = LCA[lg][b];
    }
  }
  ret = max(ret, Rmax[0][a]);
  ret = max(ret, Rmax[0][b]);
  return ret;
}
