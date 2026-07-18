
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> gold(n);
    for (int i = 0; i < n; i++) {
        cin >> gold[i];
    }
    vector<vector<int>> vizinhos(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        vizinhos[x].push_back(y);
        vizinhos[y].push_back(x);
    }
    vector<bool> visited(n, false);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            long long minGold = gold[i];
            stack<int> pilha;
            pilha.push(i);
            visited[i] = true;
            while (!pilha.empty()) {
                int u = pilha.top();
                pilha.pop();
                minGold = min(minGold, gold[u]);
                for (int v : vizinhos[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        pilha.push(v);
                    }
                }
            }
            ans += minGold;
        }
    }
    cout << ans << endl;
    return 0;
}
