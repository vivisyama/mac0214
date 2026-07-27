#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;
        if (N <= 26)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
