#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using vt = vector<T>;
using vi = vt<int>;
using vvi = vt<vi>;
using ii = pair<int, int>;
using vii = vt<ii>;
template<typename T> using mipq = priority_queue<T, vt<T>, greater<T>>; template<typename T> using mapq = priority_queue<T>;
#define sqr(x) ((x)*(x))
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define debug(x) cerr << #x << " -> " << x << '\n'
#define F first
#define S second
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int inf=1e9+7;
const ll infll = 1e18 + 10;
template <typename T> T fgcd(T a, T b) {while(b) swap(b, a %= b); return a;}
ll fpow(ll a, ll b) {ll o = 1; for(;b;b >>= 1) {if(b & 1) o = o * a;a = a * a;} return o;}
ll fpow(ll a, ll b, const ll &m) {ll o = 1; a %= m; for(;b;b >>= 1) {if(b & 1) o = o * a % m;a = a * a % m;} return o;}
int flog(const int &x) {return 31 - __builtin_clz(x);}
ll flog(const ll &x) {return 63 - __builtin_clzll(x);}
template<class T> void uniq(vt<T> &a) {sort(all(a));a.resize(unique(all(a)) - a.begin());}
void setIO(string name) {
  cin.tie(0)->sync_with_stdio(0);
  // if(fopen((name+".txt").c_str(), "r")) freopen((name+".txt").c_str(), "r", stdin);
}
signed main() {
  setIO("");
}
