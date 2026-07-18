#include <bits/stdc++.h>
using d = double;
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int ans = 1e9;
    string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string top, side1, side2, side3, side4, bot; 
    
    cin >> top >> side1 >> side2 >> side3 >> side4 >> bot;
    
    int dp[16][26];
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 26; ++j) {
            dp[i][j] = 1e9;
        }
    }
    
    for (int j = 0; j < alph.length(); j++) {
        int c = 1e9;
        if (alph[j] == top[0]) c = 0;
        else if (alph[j] == side1[0] || alph[j] == side2[0] || alph[j] == side3[0] || alph[j] == side4[0]) c = 1;
        else if (alph[j] == bot[0]) c = 2;
        dp[0][j] = c;
    }
 
    for (int i = 1; i < top.length(); ++i) {
        for (int j = 0; j < alph.length(); j++) {
            int c = 1e9;
            if (alph[j] == top[i]) c = 0;
            else if (alph[j] == side1[i] || alph[j] == side2[i] || alph[j] == side3[i] || alph[j] == side4[i]) c = 1;
            else if (alph[j] == bot[i]) c = 2;
            
            if (c == 1e9) continue;
 
            for (int k = 0; k < alph.length(); k++) {
                if (dp[i-1][k] == 1e9) continue;
                
                bool test = 0;
                if (alph[k] == 'Q') {
                    if (j >= 20) test = 1;
                } else {
                    if (k <= j) test = 1;
                }
 
                if (test == 1) {
                    if (dp[i-1][k] + c < dp[i][j]) {
                        dp[i][j] = dp[i-1][k] + c;
                    }
                }
            }
        }
    }
 
    for (int j = 0; j < alph.length(); j++) {
        if (dp[top.length()-1][j] < ans) {
            ans = dp[top.length()-1][j];
        }
    }
 
    if (ans == 1e9) {
        cout << "impossible" << "\n";
    } else {
        cout << ans << "\n";
    }
 
    return 0;
}
