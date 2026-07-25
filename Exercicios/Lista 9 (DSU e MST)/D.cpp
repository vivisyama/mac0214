#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll power(ll base, ll exp, ll mod) {
    base %= mod;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> redAdj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        if (x == 0) { 
            redAdj[u].push_back(v);
            redAdj[v].push_back(u);
        }
    }

    vector<char> visited(n + 1, 0);
    ll badSum = 0;
    for (int start = 1; start <= n; start++) {
        if (!visited[start]) {
            int compSize = 0;
            queue<int> bfsq;
            bfsq.push(start);
            visited[start] = 1;
            while (!bfsq.empty()) {
                int u = bfsq.front(); bfsq.pop();
                compSize++;
                for (int v : redAdj[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        bfsq.push(v);
                    }
                }
            }

            badSum = (badSum + power(compSize, k, MOD)) % MOD;
        }
    }

    ll total = power(n, k, MOD);
    ll ans = ((total - badSum) % MOD + MOD) % MOD;

    cout << ans << endl;
    return 0;
}
