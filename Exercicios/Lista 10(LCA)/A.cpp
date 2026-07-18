#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 31;
int up[MAXN][LOG];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> up[i][0];
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int x;
        long long k;
        cin >> x >> k;
        for (int j = 0; j < LOG; j++) {
            if (k & (1LL << j))
                x = up[x][j];
        }
        cout << x << endl;
    }
    return 0;
}
