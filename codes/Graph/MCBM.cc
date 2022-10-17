// Max Cardinality Bipartite Matching (MCBM)
// Max Independent Set (V - MCBM)
// Min Vertex Cover (MCBM)
vi match, vis;
int Aug(int l) {
  if (vis[l]) return 0;
  vis[l] = 1;
  for (int j = 0; j < sz(AdjList[l]); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;
  }}
  return 0;
}
// inside int main()
  // build unweighted bipartite graph with directed edge left->right set
  int MCBM = 0;
  match.assign(V, -1);
  for (int l = 0; l < n; l++) {
    vis.assign(n, 0);
    MCBM += Aug(l);
  }
