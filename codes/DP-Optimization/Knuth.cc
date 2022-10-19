// Optimize O(n^3) -> O(n^2)
// dp(i, j) = min[i <= k < j](dp(i, k) + dp(k + 1, j) + C(i, j))
// REQUIRE: opt(i, j - 1) <= opt(i, j) <= opt(i + 1, j)
int solve() {
  int N;
  ... // read N and input
  int dp[N][N], opt[N][N];
  auto C = [&](int i, int j) {
    ... // Implement cost function C.
  };
  for (int i = 0; i < N; i++) {
    opt[i][i] = i;
    ... // Initialize dp[i][i] according to the problem
  }
  for (int i = N-2; i >= 0; i--) {
    for (int j = i+1; j < N; j++) {
      int mn = inf, cost = C(i, j);
      for (int k = opt[i][j-1]; k <= min(j-1, opt[i+1][j]); k++) {
        if (mn >= dp[i][k] + dp[k+1][j] + cost) {
          opt[i][j] = k; 
          mn = dp[i][k] + dp[k+1][j] + cost; 
      }}
      dp[i][j] = mn; 
  }}
  cout << dp[0][N-1] << endl;
}
