#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        ll sum = 0;
        ll g = 0;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            sum += x;
            if (i == 0)
                g = x;
            else
                g = gcd(g, x);
        }

        cout << sum << " " << g << endl;
    }

    return 0;
}
