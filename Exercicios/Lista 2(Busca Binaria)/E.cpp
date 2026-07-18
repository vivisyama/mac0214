include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> arr(n+1);

    for (int i = 1; i <= n; i++){
        cin >> arr[i];        
    }

    vector<int> l(m+1), r(m+1), d(m+1);

    for (int i = 1; i<= m; i++){
        cin >> l[i] >> r[i] >> d[i];        
    }
    vector<long long> operations(m+2, 0);
    for (int i = 0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        operations[x] += 1;
        operations[y+1] -= 1;
    }
    for (int i = 1; i<= m;i++){
        operations[i] +=operations[i-1];        
    }
    vector<long long> f(n+2, 0);
    for (int i = 1;i<= m; i++) {
        long long t = operations[i];
        if (t == 0) continue;
        f[l[i]] += t * d[i];
        f[r[i]+1] -= t * d[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i] += f[i-1];
        arr[i] += f[i];
    }
    for (int i =1;i<= n; i++)
    {
        cout << arr[i] << " ";        
    }

}
