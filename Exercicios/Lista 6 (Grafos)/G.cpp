#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> nao_visitados;
set<int> sem_aresta[200005];
vector<int> comp;

void dfs(int inicio) {
    int tamanho = 0;
    stack<int> pilha;
    pilha.push(inicio);
    nao_visitados.erase(inicio);
    
    while (!pilha.empty()) {
        int u = pilha.top();
        pilha.pop();
        tamanho++;
        vector<int> adc;
        for (auto it = nao_visitados.begin(); it != nao_visitados.end(); ++it) {
            int v = *it;
            if (sem_aresta[u].find(v) == sem_aresta[u].end()) {
                adc.push_back(v);
            }
        }
        for (int v : adc) {
            nao_visitados.erase(v);
            pilha.push(v);
        }
    }
    comp.push_back(tamanho);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        sem_aresta[x].insert(y);
        sem_aresta[y].insert(x);
    }
    for (int i = 1; i <= n; i++) {
        nao_visitados.insert(i);
    }
    while (!nao_visitados.empty()) {
        int inicio = *nao_visitados.begin();
        dfs(inicio);
    }
    sort(comp.begin(), comp.end());
    cout << comp.size() << endl;

    for (int x : comp) {
        cout << x << endl;
    }
    cout << endl;
    return 0;
}
