#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    cout << endl;
    vector <long long> paired;
    unordered_set <long long> socks;


    for(int i = 0; i<N; i++){
        long long A;
        cin >> A;
        if (socks.size() > 0){
            if (socks.find(A) != socks.end()){
                paired.push_back(A);
                socks.erase(A);
            }
            else{
                socks.insert(A);
            }
        }
        else socks.insert(A);
    }
    int ans = paired.size();
    cout << ans <<endl ;
}

