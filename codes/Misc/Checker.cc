mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
const string NAME = "";
const int NTEST = 100;
ll Rand(ll l, ll r) {
  ll res = 0;
  for(int i = 0; i < 4; i++) res = (res << 15) ^ (rd() & ((1 << 15) - 1));
  return l + res % (r - l + 1)
}
signed main() {
  srand(time(NULL));
  for(int tc = 1; tc <= NTEST; tc++) {
    ofstream inp((NAME + ".txt").c_str());
    // gen code (inp << n << ...)
    inp.close();
    system((NAME + ".exe").c_str());
    system((NAME + "_trau.exe").c_str());
    if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str())) {
      cout << "Test " << tc << ": WRONG\n"; return;
    }
    cout << "Test " << tc << ": CORRECT\n";
  }
}
