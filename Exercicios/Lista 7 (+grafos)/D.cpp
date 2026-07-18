#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const long long INF = 1e18;

vector<pair<int,int>> grafo[MAX];

long long dist[MAX];
int pai[MAX];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {

        int a, b, w;
        cin >> a >> b >> w;
        grafo[a].push_back({b, w});
        grafo[b].push_back({a, w});
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        pai[i] = -1;
    }

    priority_queue<pair<long long,int>,
                   vector<pair<long long,int>>,
                   greater<pair<long long,int>>> fila;

    dist[1] = 0;
    fila.push({0,1});

    while (!fila.empty()) {
        long long distancia = fila.top().first;
        int atual = fila.top().second;
        fila.pop();

        if (distancia > dist[atual])
            continue;

        for (auto vizinho : grafo[atual]) {
            int prox = vizinho.first;
            int peso = vizinho.second;

            if (dist[atual] + peso < dist[prox]) {
                dist[prox] = dist[atual] + peso;
                pai[prox] = atual;
                fila.push({dist[prox], prox});
            }
        }
    }
    if (dist[n] == INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> caminho;
    int atual = n;
    while (atual != -1) {
        caminho.push_back(atual);
        atual = pai[atual];
    }

    reverse(caminho.begin(), caminho.end());
    for (int x : caminho)
        cout << x << " ";

    cout << endl;
    return 0;
}
