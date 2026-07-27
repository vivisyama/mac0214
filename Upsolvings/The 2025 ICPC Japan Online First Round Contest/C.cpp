#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;

    while (cin >> n >> m && (n || m)) {
        ll weeks = m / 7;
        ll rem = m % 7;
        ll ans = weeks * 5;
        for (ll i = 1; i <= rem; i++)
            ans++;
        if (rem >= 6) ans--;
        if (rem == 0) {}

        set<ll> holidays;

        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            holidays.insert(x);
        }

        for (ll d : holidays) {
            if (d > m) continue;
            ll r = d % 7;
            if (r == 6 || r == 0)
                continue;

            ans--;
        }
        cout << ans <<endl;
    }

    return 0;
}
