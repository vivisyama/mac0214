#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;

    cin >> N;
    cin >> s;
    int ans = 0;
    int i = 0;
    while (i < N) {
        int j = i;
        while (j < N && s[j] == s[i])
            j++;
        int len = j - i;
        if (s[i] == 'a' && len >= 2)
            ans += len;
        i = j;
    }
    cout << ans << endl;
    return 0;
}
