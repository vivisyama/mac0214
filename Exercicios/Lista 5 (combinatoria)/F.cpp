#include <bits/stdc++.h>
using namespace std;
using ll= long long;
static const long long MOD = 1e9 + 7;

bool is_good(ll x, int a, int b) {
    if (x == 0) return false;
    while(x) {
        int d=x % 10;
        if (d != a && d != b) return false;
        x /= 10;
    }
    return true;
}

ll modexp(ll base, ll exp) {
    ll res=1;
    while (exp) {
        if (exp & 1) res =res*base % MOD;
        base =base* base % MOD;
        exp >>= 1;
    }
    return res;
}

ll C (int n, int k, vector<ll>& fact, vector<ll>& invfact) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD*invfact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;
    vector<ll> fact(n + 1), invfact(n + 1);
    fact[0] = 1;
    for (int i=1; i <= n; i++) {
        fact[i]=fact[i-1] * i % MOD;
    }
    invfact[n]=modexp(fact[n], MOD-2);
    for (int i=n-1; i >= 0; i--) {
        invfact[i]=invfact[i+1]* (i+1)%MOD;
    }
    ll resposta = 0;
    for (int i=0; i<=n; i++) {
        ll sum=1LL*i* a + 1LL * (n-i) * b;
        if (is_good(sum, a, b)) {
            resposta=(resposta + C(n, i, fact, invfact))%MOD;
        }
    }
    cout << resposta << endl;
}
C++
