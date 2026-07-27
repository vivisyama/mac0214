#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arrows(1000005, 0);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int H;
        cin >> H;
        if (arrows[H] > 0) {
            arrows[H]--;
            arrows[H - 1]++;
        } else {
            ans++;
            arrows[H - 1]++;
        }
    }
    cout << ans << endl;
    return 0;
}
