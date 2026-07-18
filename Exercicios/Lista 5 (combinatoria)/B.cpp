#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

void solve() {
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> s(n);
    ll b=0;
    ll a=0;
    ll sum_s = 0;
    
    for (int i=0; i<n; ++i) {
        cin >> s[i];
        if (s[i] % 2 ==0) b++;
        else a++;
        sum_s += s[i];
    }
    ll total = (c+1) * (c+2) / 2;
    ll p1 = 0;
    for (ll val : s) {
        p1 += (val / 2) + 1;
    }
    ll p2 = n * (c+1) - sum_s;
    ll intersection = (b * (b+1) / 2) + (a * (a+1) / 2);
    
    ll result = total - (p1+p2 - intersection);
    cout << result << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
