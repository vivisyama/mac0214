#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    int ans = 0;
    while (N--) {
        int A, B;
        cin >> A >> B;
        ans += B - A;
    }

    cout << ans << '\n';
    return 0;
}
