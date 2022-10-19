deque<ii> st;
ll calc(ii x, ll y) {
  return x.F * y + x.S;
}
bool ck(ii x, ii y, ii z) {
  return ll(y.S - x.S) * (y.F - z.F) <= ll(z.S - y.S) * (x.F - y.F); // for max: >=
}
// inside main()
  // lines must be sorted inc/dec by A (Ax + B)
  // FOR EACH QUERY
    while(sz(st) > 1 && calc(st.front(), x) >= calc(st[1], x)) st.pop_front(); // for max: <=
    dp[i] = ... + calc(st.front(), x);
    ii t = mp(Ai, Bi);
    while(sz(st) > 1 && ck(t, st.back(), st[sz(st) - 2])) st.pop_back();
    st.pb(t);
