#include <bits/stdc++.h>
using d = double;
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
   
    string n; cin >> n;
    int l = n.length();
    d res = 0.0, chance = 1.0;
 
    for (int i = 1; i <= l; ++i) {
        d number = n[i-1] - '0';
        d dec = 0.9 * (l - i) + 1.0;
        res += number * chance * dec;
        chance *= 0.1;
        if (chance < 1e-12) break;
    }
 
    cout << fixed << setprecision(12) << res << "\n";
 
    return 0;
}
