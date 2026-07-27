#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        bool pos = false;
        bool neg = false;
        for (int i = 0; i < N; i++) {
            long long x;
            cin >> x;
            if (x > 0)
                pos = true;
            else if (x < 0)
                neg = true;
        }

        if (pos && neg)
            cout << 2 << endl;
        else if (pos || neg)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
