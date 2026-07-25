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

    for (int i = 2; i <= n; i++) {
        int e;
        cin >> e;
        up[0][i] = e;
    }

    for (int j = 1; j < LOG; j++) {
        for (int v = 1; v <= n; v++) {
            int mid = up[j-1][v];
            up[j][v] = (mid == 0) ? 0 : up[j-1][mid];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        int cur = x;
        for (int j = 0; j < LOG && cur != 0; j++) {
            if (k & (1 << j)) {
                cur = up[j][cur];
            }
        }
        cout << (cur == 0 ? -1 : cur) << endl;
    }
    return 0;
}
