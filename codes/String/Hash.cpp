void hbuild(char a[], int n, ll H[]) {
  for (int i = 1; i <= n; i++)
    H[i] = (H[i - 1] * M[1] + a[i]) % BASE;
}
ll hash_range(ll H[], int L, int R) {
  return (H[R] - H[L - 1] * M[R - L + 1] + 1LL * inf * inf) % inf;
}
// main
M[0] = 1;
M[1] = 2309;
for (int i = 2; i < N; i++)
  M[i] = M[i - 1] * M[1] % BASE;
