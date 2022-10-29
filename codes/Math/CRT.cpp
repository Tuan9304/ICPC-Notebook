// return 1:
//   M = LCM(n,m); 0 <= x < M
//   x % n = a, x % m = b
// 0 if no solution
template<typename T>
bool linearCongruences(const vt<T> &a,const vt<T> &b,const vt<T> &m,T &x,T &M) {
  int n = sz(a);
  x = 0; M = 1;
  for (int i = 0; i < n; i++) {
    T a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];
    T y, t, g = extgcd<T>(a_, m_, y, t);
    if (b_ % g) return 0;
    b_ /= g; m_ /= g;
    x += M * (y * b_ % m_);
    M *= m_;
  }
  x = (x + M) % M;
  return 1;
}
