#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);

    for (int i = 0; i< n; i++){
        cin >> a[i];
    }
    for (int j= 0; j <m;j++){
        cin >>b[j];
    }
    vector<vector<ll>> length(n+1, vector<ll>(m+1,0));

    for (int i = 1; i<= n; i++) {
        for (int j=1; j<= m;j++) {
            if (a[i-1] == b[j-1]) {
                length[i][j] = length[i-1][j-1] + 1;
            } else {
                length[i][j] = max(length[i-1][j], length[i][j-1]);
            }
        }
    }
    cout << length[n][m] << endl;
    vector<ll> ans;
    int i =n, j = m;
    while (i>0 && j > 0) {
        if (a[i-1]== b[j-1]) {
            ans.push_back(a[i-1]);
            i-=1;
            j-=1;
        } 
        else if (length[i-1][j] > length[i][j-1]) i-=1;
        else j-=1;
    }
    reverse(ans.begin(), ans.end());

    for (ll x : ans) cout << x << " ";
}
