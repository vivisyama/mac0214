#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int j = pi[i-1];
        while (j > 0 && t[i] != t[j]) j = pi[j-1];
        if (t[i] == t[j]) j++;
        pi[i] = j;
    }
    vector<array<int,26>> aut(m+1);
    for (int c = 0; c < 26; c++) {
        aut[0][c] = (t[0]-'a' == c) ? 1 : 0;
    }
    for (int state = 1; state <= m; state++) {
        for (int c = 0; c < 26; c++) {
            if (state < m && (t[state]-'a') == c)
                aut[state][c] = state + 1;
            else
                aut[state][c] = aut[pi[state-1]][c];
        }
    }

    const int NEG = -1;
    vector<int> dp(m+1, NEG), ndp(m+1, NEG);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        fill(ndp.begin(), ndp.end(), NEG);
        char ch = s[i];
        if (ch != '?') {
            int c = ch - 'a';
            for (int state = 0; state <= m; state++) {
                if (dp[state] == NEG) continue;
                int ns = aut[state][c];
                int val = dp[state] + (ns == m ? 1 : 0);
                if (val > ndp[ns]) ndp[ns] = val;
            }
        } else {
            for (int state = 0; state <= m; state++) {
                if (dp[state] == NEG) continue;
                int base = dp[state];
                for (int c = 0; c < 26; c++) {
                    int ns = aut[state][c];
                    int val = base + (ns == m ? 1 : 0);
                    if (val > ndp[ns]) ndp[ns] = val;
                }
            }
        }
        swap(dp, ndp);
    }
    int ans = 0;
    for (int state = 0; state <= m; state++)
        ans = max(ans, dp[state]);

    cout << ans << endl;
    return 0;
}
