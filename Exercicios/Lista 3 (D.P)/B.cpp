#include <bits/stdc++.h>
using namespace std;

const int m = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<string> cells(n);
    for (int i = 0; i < n; i++) {
        cin >> cells[i];
    }

    vector<vector<int>> caminhos(n, vector<int>(n, 0));

    if (cells[0][0] == '.') caminhos[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cells[i][j] == '*') {
                caminhos[i][j] = 0;
                continue;
            }
            if (i > 0) caminhos[i][j] = (caminhos[i][j] + caminhos[i-1][j]) % m;
            if (j > 0) caminhos[i][j] = (caminhos[i][j] + caminhos[i][j-1]) % m;
        }
    }
    cout << caminhos[n-1][n-1] << endl;
}
