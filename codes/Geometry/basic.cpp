#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;
const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;
typedef long double type;
// for big coordinates change to long long
bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }
int sign(type x) { return ge(x, 0) - le(x, 0); }
struct point {
  type x, y;
  point() : x(0), y(0) {}
  point(type x, type y) : x(x), y(y) {}
  point operator-() { return point(-x, -y); }
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(type k) { return point(k * x, k * y); }
  point operator/(type k) { return point(x / k, y / k); }
  // inner product
  type operator*(point p) { return x * p.x + y * p.y; }
  // cross product
  type operator%(point p) { return x * p.y - y * p.x; }
  bool operator==(const point &p) const { return x == p.x and y == p.y; }
  bool operator!=(const point &p) const { return x != p.x or y != p.y; }
  bool operator<(const point &p) const {
    return (x < p.x) or (x == p.x and y < p.y);
  }
  // 0 => same direction
  // 1 => p is on the left
  //-1 => p is on the right
  int dir(point o, point p) {
    type x = (*this - o) % (p - o);
    return ge(x, 0) - le(x, 0);
  }
  bool on_seg(point p, point q) {
    if (this->dir(p, q)) return 0;
    return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) &&
           ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
  }
  ld abs() { return sqrt(x * x + y * y); }
  type abs2() { return x * x + y * y; }
  ld dist(point q) { return (*this - q).abs(); }
  type dist2(point q) { return (*this - q).abs2(); }
  ld arg() { return atan2l(y, x); }
  // Project point on vector y
  point project(point y) { return y * ((*this * y) / (y * y)); }
  // Project point on line generated by points x and y
  point project(point x, point y) { return x + (*this - x).project(y - x); }
  ld dist_line(point x, point y) { return dist(project(x, y)); }
  ld dist_seg(point x, point y) {
    return project(x, y).on_seg(x, y) ? dist_line(x, y) : min(dist(x), dist(y));
  }
  point rotate(ld sin, ld cos) {
    return point(cos * x - sin * y, sin * x + cos * y);
  }
  point rotate(ld a) { return rotate(sin(a), cos(a)); }
  // rotate around the argument of vector p
  point rotate(point p) { return rotate(p.y / p.abs(), p.x / p.abs()); }
};
int direction(point o, point p, point q) { return p.dir(o, q); }
point rotate_ccw90(point p) { return point(-p.y, p.x); }
point rotate_cw90(point p) { return point(p.y, -p.x); }
// for reading purposes avoid using * and % operators, use the functions below:
type dot(point p, point q) { return p.x * q.x + p.y * q.y; }
type cross(point p, point q) { return p.x * q.y - p.y * q.x; }
// double area
type area_2(point a, point b, point c) {
  return cross(a, b) + cross(b, c) + cross(c, a);
}
int angle_less(const point &a1, const point &b1, const point &a2,
               const point &b2) {
  // angle between (a1 and b1) vs angle between (a2 and b2)
  // 1  : bigger
  //-1 : smaller
  // 0  : equal
  point p1(dot(a1, b1), abs(cross(a1, b1)));
  point p2(dot(a2, b2), abs(cross(a2, b2)));
  if (cross(p1, p2) < 0) return 1;
  if (cross(p1, p2) > 0) return -1;
  return 0;
}
ostream &operator<<(ostream &os, const point &p) {
  os << "(" << p.x << "," << p.y << ")";
  return os;
}
