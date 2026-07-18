#include <bits/stdc++.h>
using namespace std;
static const long long MOD = 1e9 + 7;
static const int MAXN = 1e6 + 5;
long long fact[MAXN], invfact[MAXN];
long long modexp(long long a, long long e) {
    long long res=1;
    while (e) {
        if (e & 1) res=(res * a) % MOD;
        a=(a * a) % MOD;
        e >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>>queries(n);
    int maxA=0;
    for (int i=0; i<n;i++) {
        cin >> queries[i].first >> queries[i].second;
        maxA = max(maxA, queries[i].first);
    }
    fact[0]=1;
    for (int i= 1;i<=maxA;i++) {
        fact[i]=(fact[i - 1]*i) %MOD;
    }
    invfact[maxA] = modexp(fact[maxA], MOD-2);
    for (int i=maxA-1; i >= 0; i--) {
        invfact[i]=(invfact[i + 1] * (i + 1)) % MOD;
    }
    for (auto [a, b] : queries) {
        long long ans=fact[a];
        ans=(ans*invfact[b]) % MOD;
        ans=(ans*invfact[a - b]) % MOD;
        cout << ans << endl;
    }
    return 0;
}
