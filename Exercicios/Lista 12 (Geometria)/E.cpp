#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll,ll>> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    ll area2 = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area2 += p[i].first * p[j].second
               - p[i].second * p[j].first;
    }

    cout << abs(area2) << endl;
}
