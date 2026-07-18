#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector <int> prices;
    for (int i = 0; i< n; i++){
        int x; 
        cin >> x;
        prices.push_back(x);
    }
    sort(prices.begin(), prices.end());
    int q;
    cin >> q;
    while (q--){
        long long m;
        cin >> m;
        auto it = upper_bound(prices.begin(), prices.end(), m);
        cout << it - prices.begin() <<endl;
    }

}
C++
