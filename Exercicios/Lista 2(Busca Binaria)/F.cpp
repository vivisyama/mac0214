#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAX = 200000; 

    long long n, k, q;
    cin >> n >> k >> q;


    vector<long long> f(MAX+2, 0);

    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        f[l] += 1;
        f[r+1] -= 1;
    }
    for (int i = 1; i <= MAX; i++){
        f[i] += f[i-1];        
    }
    vector<int> tp(MAX+2, 0);

    for (int i = 1; i<= MAX; i++) {
        if (f[i] >= k)
            tp[i] = 1;
    }
    for (int i = 1; i <= MAX; i++){
        tp[i] += tp[i-1];        
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << tp[b] - tp[a-1] << endl;
    }
}
C++
