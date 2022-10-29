// Booth's Algorithm - Find the lexicographically least rotation of a string in O(n)
// rotation: abc|de -> de|abc
string least_rotation(string s) {
  s += s;
  vi f(sz(s), -1);
  int k = 0;
  for (int j = 1; j < sz(s); j++) {
    int i = f[j - k - 1];
    while (i != -1 && s[j] != s[k + i + 1]) {
      if (s[j] < s[k + i + 1]) k = j - i - 1;
      i = f[i];
    }
    if (s[j] != s[k + i + 1]) {
      if (s[j] < s[k]) k = j;
      f[j - k] = -1;
    } else f[j - k] = i + 1;
  }
  return s.substr(k, sz(s) / 2);
}
