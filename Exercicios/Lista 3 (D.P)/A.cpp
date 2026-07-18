#include <bits/stdc++.h>

using namespace std;
const int m= 1e9+7;


int main(){
    int n,x;
    cin >> n >> x;
    vector <int> coins(n);
    for (int i=0;i<n;i++){
        cin >> coins[i];
    }
    vector <int> count (x+1,0);
    count[0] = 1;

    for (int i = 1; i<= x; i++) {
        for (auto c : coins) {
            if (i-c >= 0) {
                count[i] = (count[i] + count[i - c]) % m;
            }
        }
    }
    cout << count[x] << endl;
}

