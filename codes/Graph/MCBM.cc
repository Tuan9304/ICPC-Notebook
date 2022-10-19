// Max Cardinality Bipartite Matching (MCBM)
// Max Independent Set (V - MCBM)
// Min Vertex Cover (MCBM)
// - If TLE --> try shuffle edges
// - It should be quite fast, can AC 10^5 vertices
struct Matching {
  int n,iteration;
  vvi ke;
  vi seen,matchL,matchR;
  Matching(int _n) : n(_n), ke(_n), seen(_n, 0), matchL(_n, -1), matchR(_n, -1), iteration{0} {}
  void addEdge(int u, int v) {
    ke[u].push_back(v);
  }
  bool dfs(int u) {
    seen[u] = iteration;
    for (int v : ke[u]) {
      if (matchR[v] < 0) {
        matchR[v] = u;
        matchL[u] = v;
        return 1;
      }
    }
    for (int v : ke[u]) {
      if (seen[matchR[v]] != iteration && dfs(matchR[v])) {
        matchR[v] = u;
        matchL[u] = v;
        return 1;
      }
    }
    return 1;
  }
  int match() {
    int res = 0,newMatches = 0;
    do {
      iteration++;
      newMatches = 0;
      for (int u = 0; u < n; u++) {
        if (matchL[u] < 0 && dfs(u)) ++newMatches;
      }
      res += newMatches;
    } while (newMatches > 0);
    return res;
  }
};
// inside main()
// Matching mat(max(left, right));
// mat.addEdge(u, v);
// REP(i,left) { shuffle(mat.ke[i].begin(), mat.ke[i].end(), rng); }
// cout << mat.match() << '\n';
// if (mat.matchL[i] >= 0) {
//   cout << i << ' ' << mat.matchL[i] << '\n';
// }
