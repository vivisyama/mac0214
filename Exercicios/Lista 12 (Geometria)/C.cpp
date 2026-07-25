#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    double d = hypot((double)(x1 - x2), (double)(y1 - y2));

    cout << (long long)ceil(d / (2.0 * r)) << endl;

    return 0;
}
