#include <bits/stdc++.h>
using namespace std;

int n, m, k;
char a[505][505];
bool vis[505][505];

int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
int precisa;

void dfs(int linha, int coluna) {
    if (precisa == 0) return;
    vis[linha][coluna] = true;
    precisa--;

    for (int i = 0; i < 4; i++) {
        int coordX = linha + dirx[i];
        int coordY = coluna + diry[i];

        if (coordX >=0 && coordX< n && coordY>=0 && coordY< m && a[coordX][coordY] == '.' && !vis[coordX][coordY])
        {
            dfs(coordX, coordY);
        }
    }
}

int main() {
    cin >> n >> m >> k;

    int quantVazios = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                quantVazios++;
            }
        }
    }
    precisa = quantVazios - k;
    bool achou = false;
    for (int i = 0; i < n && !achou; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                dfs(i, j);
                achou = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                a[i][j] = 'X';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}
