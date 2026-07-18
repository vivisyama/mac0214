#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

vector<int> grafo[MAX];
int gato[MAX];
int resposta = 0;
int m;

void dfs(int atual, int pai, int consecutivos) {

    if (gato[atual] == 1)
        consecutivos++;
    else
        consecutivos = 0;
    if (consecutivos > m)
        return;
    bool folha = true;

    for (int vizinho : grafo[atual]) {

        if (vizinho != pai) {
            folha = false;
            dfs(vizinho, atual, consecutivos);
        }
    }
    if (folha)
        resposta++;
}

int main() {

    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> gato[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dfs(1, 0, 0);
    cout << resposta << endl;
    return 0;
}
