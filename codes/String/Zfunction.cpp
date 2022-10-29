// Z-Function - O(n)
// z[i] = max prefix from i
vi zfunction(const string& s){
  vi z (sz(s));
  for (int i = 1, l = 0, r = 0, n = sz(s); i < n; i++) {
    if (i <= r) z[i] = min(z[i-l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
