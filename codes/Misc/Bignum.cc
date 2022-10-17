const int BASE = 10000;
void fix(vi &a) {
  a.pb(0);
  for (int i = 0; i < sz(a) - 1; ++i) {
    a[i + 1] += a[i] / BASE;
    a[i] %= BASE;
    if (a[i] < 0) {
      a[i] += BASE;
      a[i + 1]--;
    }
  }
  while (sz(a) >= 2 && a.back() == 0) a.pop_back();
}
vi operator*(const vi &a, const vi &b) {
  vi c(sz(a) + sz(b) + 1);
  for (int i = 0; i < sz(a); ++i)
    for (int j = 0; j < sz(b); ++j) {
      c[i + j] += a[i] * b[j];
      c[i + j + 1] += c[i + j] / BASE;
      c[i + j] %= BASE;
  }
  return fix(c), c;
}
vi to_vi(int x) { // x < Base
  assert(x < BASE);
  return vi(1, x);
}
vi operator+(vi a, const vi &b) {
  a.resize(max(sz(a), sz(b)));
  for (int i = 0; i < sz(b); ++i) a[i] += b[i];
  return fix(a), a;
}
vi operator-(vi a, const vi &b) {
  for (int i = 0; i < sz(b); ++i) a[i] -= b[i];
  return fix(a), a;
}
vi operator*(vi a, int x) { // x < BASE
  assert(x < BASE);
  for (int i = 0; i < sz(a); ++i) a[i] *= x;
  return fix(a), a;
}
bool operator<(const vi &a, const vi &b) {
  if (sz(a) != sz(b)) return sz(a) < sz(b);
  for (int i = sz(a) - 1; i >= 0; i--)
    if (a[i] != b[i]) return a[i] < b[i];
  return false;
}
vi operator/(vi a, int x) { // x < BASE
  assert(x < BASE);
  for (int i = sz(a) - 1, r = 0; i >= 0; --i, r %= x) {
    r = r * BASE + a[i];
    a[i] = r / x;
  }
  return fix(a), a;
}
int operator%(const vi &a, int x) { //x < BASE
  int r = 0;
  for (int i = sz(a) - 1; i >= 0; --i)
    r = (r * BASE + a[i]) % x;
  return r;
}
istream &operator>>(istream &cin, vi &a) {
  string s; cin >> s;
  a.assign(s.size() / 4 + 1, 0);
  for (int i = 0; i < sz(s); ++i) {
    int x = (sz(s) - 1 - i) / 4; // <- log10(BASE)=4
    a[x] = a[x] * 10 + (s[i] - '0');
  }
  return fix(a), cin;
}
ostream &operator<<(ostream &cout, const vi &a) {
  cout << a.back();
  for (int i = sz(a) - 2; i >= 0; i--)
    cout << setfill('0') << setw(4) << a[i];
  return cout;
}
// vi a, b; cin >> a >> b;
// a = to_vi(x)
// a + b; a * b; a / x; a % x;
// if(a < b) cout << '-' << b - a; 
// else cout << a - b
