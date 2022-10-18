// All even degrees vertices -> Euler cycle
// Exactly two odd degrees vertices -> Euler path
list<int> cyc;
void EulerTour(list<int>::iterator i, int u) {
  for (int j = 0; j < sz(AdjList[u]); j++) {
    ii v = AdjList[u][j];
    if (v.second) {
      v.second = 0;
      for (int k = 0; k < sz(AdjList[v.first]); k++) {
        ii uu = AdjList[v.first][k];
        if (uu.first == u && uu.second) {
          uu.second = 0;
          break; 
      }}
      EulerTour(cyc.insert(i, u), v.first);
}}}
// inside int main()
  cyc.clear();
  EulerTour(cyc.begin(), start);
