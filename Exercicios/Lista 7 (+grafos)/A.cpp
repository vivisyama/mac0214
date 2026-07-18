#include <bits/stdc++.h>
using namespace std;

long long dist[505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    long long INF = 1000000000000000LL;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (c < dist[a][b]) {
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (dist[a][b] == INF) {
            cout << -1 << endl;
        }
        else {
            cout << dist[a][b] << endl;
        }
    }
    return 0;
}
