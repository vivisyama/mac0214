#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int LOG = 1;
    while ((1 << LOG) < n) LOG++;
    LOG++;
    vector<vector<int>> up(LOG, vector<int>(n + 1, 0));
    vector<int> depth(n + 1, 0);
    vector<char> visited(n + 1, 0);
    vector<int> order;
    order.reserve(n);
    vector<int> edgeChild(n - 1);

    queue<int> bfsq;
    bfsq.push(1);
    visited[1] = 1;

    while (!bfsq.empty()) {
        int u = bfsq.front(); bfsq.pop();
        order.push_back(u);
        for (auto [v, idx] : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                edgeChild[idx] = v;
                bfsq.push(v);
            }
        }
    }

    for (int j = 1; j < LOG; j++)
        for (int v = 1; v <= n; v++) {
            int mid = up[j-1][v];
            up[j][v] = (mid == 0) ? 0 : up[j-1][mid];
        }

    auto lca = [&](int a, int b) -> int {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j)) a = up[j][a];
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; j--)
            if (up[j][a] != up[j][b]) { a = up[j][a]; b = up[j][b]; }
        return up[0][a];
    };

    vector<long long> cnt(n + 1, 0);

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        cnt[a]++; cnt[b]++; cnt[l] -= 2;
    }

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int v = order[i];
        if (v != 1) cnt[up[0][v]] += cnt[v];
    }
    for (int i = 0; i < n - 1; i++)
        cout << cnt[edgeChild[i]] << " \n"[i == n - 2];

    return 0;
}
