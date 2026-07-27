#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s.size() == 1 && s[0] == '1')
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
