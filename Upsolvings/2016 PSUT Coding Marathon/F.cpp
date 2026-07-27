#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> pos(N + 1);
    vector<int> cnt(M + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> pos[i];
        cnt[pos[i]]++;
    }

    int uncovered = 0;
    for (int i = 1; i <= M; i++) {
        if (cnt[i] == 0)
            uncovered++;
    }
    while (Q--) {
        int A, B;
        cin >> A >> B;
        int old = pos[A];
        if (cnt[old] == 1)
            uncovered++;

        cnt[old]--;
        if (cnt[B] == 0)
            uncovered--;

        cnt[B]++;
        pos[A] = B;
        cout << uncovered << endl;
    }

    return 0;
}
