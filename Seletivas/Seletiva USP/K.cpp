#include <bits/stdc++.h>
using ll = long long;
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
   
    int h, m; cin >> h >> m;
    if ((h % 30) * 12 != m) cout << "no" << "\n";
    else cout << "yes" << "\n";
 
    return 0;
}
