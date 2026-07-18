#include <iostream>
#include <vector>
using ll= long long;
using namespace std;
const ll MOD = 1000000007;

ll b (ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp >0) {
        if (exp % 2 == 1)res=(res * base) % MOD;
        base=(base * base) % MOD;
        exp /= 2;
    }
    return res;
}
ll mI(ll n) {
    return b(n, MOD - 2);
}
ll nmod(int n, int r) {
    if (r<0 || r>n) return 0;
    if (r==0 || r==n) return 1;
    if (r>n / 2) r = n-r;
    ll ntr = 1;
    for (int i=0; i<r; ++i) {
        ntr=(ntr* (n-i)) % MOD;
    }
    ll dm = 1;
    for (int i=1; i<=r; ++i) {
        dm=(dm* i)% MOD;
    }
    return (ntr * mI(dm)) % MOD;
}
int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    cout << nmod(n+2 * m-1, 2 * m) << endl;
    return 0;
}
