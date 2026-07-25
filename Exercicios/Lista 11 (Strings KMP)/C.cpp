#include <bits/stdc++.h>
using namespace std;

vector<int> zFunction(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

int main(){
    string A, B;
    long long n;

    getline(cin, A);
    getline(cin, B);
    cin >> n;

    int m = B.size(), len = A.size();
    string S = B + "\x01" + A;
    vector<int> Z = zFunction(S);

    vector<long long> freq(m + 2, 0);
    for (int i = 0; i < len; i++) {
        int p = m + 1 + i;
        int l = min(Z[p], m);
        freq[l]++;
    }

    vector<long long> cnt(m + 2, 0);
    for (int k = m; k >= 1; k--)
        cnt[k] = cnt[k + 1] + freq[k];

    int best = -1;
    for (int k = m; k >= 1; k--) {
        if (cnt[k] >= n) { best = k; break; }
    }

    if (best == -1) cout << "IMPOSSIBLE\n";
    else cout << B.substr(0, best) << endl;
}
