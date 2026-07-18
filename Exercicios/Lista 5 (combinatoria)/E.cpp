#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll MOD = 998244353;

ll modexp(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r *a% MOD;
        a=a*a% MOD;
        e >>=1;
    }
    return r;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    if (k > n - 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> fact(n + 1), invfact(n + 1);
    fact[0] = 1;
    for (int i=1;i<= n; i++)
        fact[i]=fact[i-1] * i % MOD;
    invfact[n] = modexp(fact[n], MOD-2);

    for (int i=n-1; i >= 0; i--)
        invfact[i]=invfact[i+1] * (i+1) % MOD;
    auto C=[&](int n, int k) {
        if (k < 0 || k > n) return 0LL;
        return fact[n] * invfact[k]% MOD *invfact[n-k] %MOD;
    };
    ll answer=C(n-1, k);
    answer=answer * m % MOD;
    answer=answer * modexp(m-1, k) % MOD;
    cout << answer << endl;
}
