/**
 * Source: folklore
 * Description: Computes sums a[i,j] for all i<I, j<J, and increases single elements a[i,j].
 *  Requires that the elements to be updated are known in advance (call fakeUpdate() before init()).
 * Time: $O(\log^2 N)$. (Use persistent segment trees for $O(\log N)$.)
 */
struct FT2 {
  vvi ys; vt<FT> ft;
  FT2(int limx) : ys(limx) {}
  void fakeUpdate(int x, int y) {
	for (; x < sz(ys); x |= x + 1) ys[x].pb(y);
  }
  void init() {
	for (vi& v : ys) sort(all(v)), ft.eb(sz(v));
  }
  int ind(int x, int y) {
	return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
  void update(int x, int y, ll dif) {
	for (; x < sz(ys); x |= x + 1)
	  ft[x].update(ind(x, y), dif);
  }
  ll query(int x, int y) {
	ll sum = 0;
	for (; x; x &= x - 1)
	  sum += ft[x-1].query(ind(x-1, y));
	return sum;
  }
};
