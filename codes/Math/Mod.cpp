const int MOD = 1e9 + 7;
ll modadd(ll a, const ll &b) {
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}
ll modsubtr(const ll &a, const ll &b) {
    return add(a, MOD - b);
}
ll modmul(ll a, const ll &b) {
    ll ret = a * b - M * ll(1.L / MOD * a * b);
    return ret + MOD * (ret < 0) - MOD * (ret >= (ll)MOD);
}
ll moddiv(const ll &a, const ll &b) {
    return mul(a, fpow(b, MOD - 2, MOD));
}
