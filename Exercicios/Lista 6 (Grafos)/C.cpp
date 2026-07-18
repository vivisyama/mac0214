#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[100005];
bool vis[100005];
void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v])
            dfs(v);
    }
}

bool conectado(int inicio) {
    for (int i = 0; i <= n; i++) {
        vis[i] = false;
    }
    dfs(inicio);
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (m != n) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (conectado(i)) {
            cout << "FHTAGN!\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
