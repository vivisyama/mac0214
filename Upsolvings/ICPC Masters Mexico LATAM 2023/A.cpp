#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

bool ok(int64 m, int64 N) {
    if (m & 1) {
        int64 k = (m + 1) / 2;
        return (__int128)k * k >= N;
    } else {
        int64 k = m / 2;
        return (__int128)k * (k + 1) >= N;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64 N;
    cin >> N;

    int64 lo = 1, hi = 2000000;

    while (lo < hi) {
        int64 mid = (lo + hi) / 2;
        if (ok(mid, N))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
    return 0;
}
