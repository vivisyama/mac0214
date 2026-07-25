#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    vector<ll> a(n), b(w);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < w; i++) cin >> b[i];

    if (w == 1) {
        cout << n << '\n';
        return 0;
    }

    vector<ll> da, db;

    for (int i = 0; i < n - 1; i++)
        da.push_back(a[i + 1] - a[i]);
    for (int i = 0; i < w - 1; i++)
        db.push_back(b[i + 1] - b[i]);

    int m = db.size();

    vector<int> pi(m);

    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && db[i] != db[j])
            j = pi[j - 1];
        if (db[i] == db[j])
            j++;
        pi[i] = j;
    }

    int ans = 0;
    int j = 0;

    for (ll x : da) {
        while (j > 0 && x != db[j])
            j = pi[j - 1];
        if (x == db[j])
            j++;
        if (j == m) {
            ans++;
            j = pi[j - 1];
        }
    }

    cout << ans << endl;
}
