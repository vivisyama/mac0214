#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> x(n + 1), y(n + 1), c(n + 1), k(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> k[i];
    int N = n + 1;
    vector<ll> dist(N, LLONG_MAX);
    vector<int> parent(N, -1);
    vector<char> inMST(N, 0);

    dist[0] = 0;

    auto edgeWeight = [&](int a, int b) -> ll {
        if (a == 0) return c[b];
        if (b == 0) return c[a];
        return (k[a] + k[b]) * (llabs(x[a]-x[b]) + llabs(y[a]-y[b]));
    };

    ll totalCost = 0;

    for (int iter = 0; iter < N; iter++) {
        int u = -1;
        for (int v = 0; v < N; v++) {
            if (!inMST[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }

        inMST[u] = 1;
        totalCost += dist[u];

        for (int v = 0; v < N; v++) {
            if (!inMST[v]) {
                ll w = edgeWeight(u, v);
                if (w < dist[v]) {
                    dist[v] = w;
                    parent[v] = u;
                }
            }
        }
    }

    vector<int> stations;
    vector<pair<int,int>> connections;

    for (int i = 1; i <= n; i++) {
        if (parent[i] == 0) {
            stations.push_back(i);
        } else {
            connections.push_back({i, parent[i]});
        }
    }

    cout << totalCost << endl;
    cout << stations.size() <<endl;
    for (int i = 0; i < (int)stations.size(); i++) {
        cout << stations[i] << " \n"[i == (int)stations.size()-1];
    }
    if (stations.empty()) cout << endl;
    cout << connections.size() << endl;
    for (auto& [a, b] : connections) {
        cout << a << " " << b << endl;
    }
    return 0;
}
