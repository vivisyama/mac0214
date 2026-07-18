#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int a = 0; a < n; a++) {
        vector<bool> visited(n, false);
        int atual = a;
        while (!visited[atual]) {
            visited[atual] = true;
            atual = p[atual];
        }
        cout << atual + 1 << endl;
    }
    return 0;
}
