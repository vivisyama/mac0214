#include <bits/stdc++.h>
using namespace std;

bool check(string s, string base) {
    int n = s.size();
    int m = base.size();

    for (int i = 0; i < n; i++) {
        if (s[i] != base[i % m])
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string A, B;
        cin >> A >> B;

        int g = gcd((int)A.size(), (int)B.size());
        string base = A.substr(0, g);
        if (check(A, base) && check(B, base))
            cout << g <<endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
