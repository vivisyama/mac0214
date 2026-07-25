#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    vector<long long> cnt(n + 1, 0);

    for (int i = 0; i < n; i++)
        cnt[pi[i]]++;
    for (int i = n; i > 0; i--)
        cnt[pi[i - 1]] += cnt[i];
    for (int i = 1; i <= n; i++)
        cnt[i]++;

    vector<int> ans;
    int x = n;
    while (x > 0) {
        ans.push_back(x);
        x = pi[x - 1];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int len : ans)
        cout << len << " " << cnt[len] << endl;
}
