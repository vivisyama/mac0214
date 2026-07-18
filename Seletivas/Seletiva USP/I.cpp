#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    double w; cin >> n >> w;
    vector<double> p(n, 0), t(n, 0);
    for (int i = 0; i < n; ++i) cin >> p[i] >> t[i];
 
    double left = 0.0, right = 4e9;
 
    for (int i = 0; i < 100; ++i) {
        double mid = left + (right - left) / 2.0;
        double wheat = 0.0;
 
        for (int j = 0; j < n; ++j) {
            double times = mid - (2.0 * t[j]);
            
            if (times > 0.0) wheat += times * p[j];
        }
 
        if (wheat >= w) right = mid;
        else left = mid;
    }
 
    cout << fixed << setprecision(12) << right << "\n";
 
    return 0;
}
