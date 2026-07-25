#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int LOG = 1;
    while ((1 << LOG) < n) LOG++;
    LOG++;
    vector<vector<int>> up(LOG, vector<int>(n + 1, 0));
    vector<int> depth(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int e;
        cin >> e;
        up[0][i] = e;
        depth[i] = depth[e] + 1;
    }

    for (int j = 1; j < LOG; j++) {
        for (int v = 1; v <= n; v++) {
            int mid = up[j-1][v];
            up[j][v] = (mid == 0) ? 0 : up[j-1][mid];
        }
    }
    auto lca = [&](int a, int b) -> int {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                a = up[j][a];
            }
        }

        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][a] != up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }
        return up[0][a]; 
    };

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }

    return 0;
}
