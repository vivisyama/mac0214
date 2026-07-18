#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> primo(MAX+1,true);
    primo[0] = primo[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (primo[i]) {
            for (int j = i*i; j <= MAX; j += i) {
                primo[j] = false;
            }
        }
    }
    vector<int> prefix(MAX + 1, 0);
    for (int i=1;i<= MAX; i++) {
        prefix[i] = prefix[i - 1] + primo[i];
    }
    int T;
    cin >> T;
    while (T--) {
        int i, j;
        cin >> i >> j;
        cout << prefix[j]-prefix[i - 1] << endl;
    }
}
