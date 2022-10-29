// Tarjan for SCC and Edge Biconnected Componentes - O(n + m)
vi adj[N];
stack<int> st;
bool inSt[N];
int id[N], cmp[N];
int cnt, cmpCnt;
void clear() {
  memset(id, 0, sizeof id);
  cnt = cmpCnt = 0;
}
int tarjan(int n) {
  int low;
  id[n] = low = ++cnt;
  st.push(n), inSt[n] = 1;
  for(auto x : adj[n]) {
    if(id[x] && inSt[x]) low = min(low, id[x]);
    else if(!id[x]) {
      int lowx = tarjan(x);
      if(inSt[x]) low = min(low, lowx);
    }
  }
  if(low == id[n]) {
    while(st.size()) {
      int x = st.top();
      inSt[x] = 0;
      cmp[x] = cmpCnt;
      st.pop();
      if(x == n) break;
    }
    cmpCnt++;
  }
  return low;
}
