#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text, pat;
    cin >> text >> pat;
    int n = text.size();
    int m = pat.size();
    vector<int> pi(m);
  
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j > 0 && pat[i] != pat[j])
            j = pi[j - 1];
        if (pat[i] == pat[j])
            j++;
        pi[i] = j;
    }
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pat[j])
            j = pi[j - 1];
        if (text[i] == pat[j])
            j++;
        if (j == m) {
            ans++;
            j = pi[j - 1];
        }
    }
    cout << ans << endl;
}
