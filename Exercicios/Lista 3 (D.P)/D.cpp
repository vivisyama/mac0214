#include <bits/stdc++.h>
using namespace std;
const int m= 1e9 + 7;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int max_n = 1e6;

    vector<vector<ll>> towers(max_n +1,vector<ll>(2));
    towers[1][0]=1;
    towers[1][1]=1;
    for (int i =2; i<= max_n; i++) {
        towers[i][0]= (2*towers[i-1][0]+towers[i-1][1])%m ;
        towers[i][1]= (towers[i-1][0]+ 4*towers[i-1][1])%m;
    }
    while (t--) {
        int n;
        cin >> n;
        cout << (towers[n][0] + towers[n][1]) %m <<endl;
    }
}
