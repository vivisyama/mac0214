#include <bits/stdc++.h>
using namespace std;

int n, m;

char mapa[1005][1005];
bool visitado[1005][1005];
char veio[1005][1005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char movimento[4] = {'D', 'U', 'R', 'L'};

int main() {

    cin >> n >> m;
    int ax, ay, bx, by;
    for (int i = 0; i < n; i++) {
        cin >> mapa[i];
        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == 'A') {
                ax = i;
                ay = j;
            }
            if (mapa[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    queue<pair<int,int>> fila;
    fila.push({ax, ay});
    visitado[ax][ay] = true;
    while (!fila.empty()) {
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();
        for (int i = 0; i < 4; i++) {
            int coordX = x + dx[i];
            int coordY = y + dy[i];

            if (coordX >= 0 && coordX < n &&
                coordY >= 0 && coordY < m &&
                !visitado[coordX][coordY] &&
                mapa[coordX][coordY] != '#') {
                visitado[coordX][coordY] = true;
                veio[coordX][coordY] = movimento[i];
                fila.push({coordX, coordY});
            }
        }
    }
    if (!visitado[bx][by]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    string resposta = "";
    int x = bx;
    int y = by;

    while (x != ax || y != ay) {
        char mov = veio[x][y];
        resposta += mov;
        if (mov == 'D')
            x--;
        else if (mov == 'U')
            x++;
        else if (mov == 'R')
            y--;
        else
            y++;
    }
    reverse(resposta.begin(), resposta.end());
    cout << resposta.size() << endl;
    cout << resposta << endl;
    return 0;
}
