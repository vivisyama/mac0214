#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, K;
    cin >> R >> C >> K;

    vector<int> freq(R + 1, 0);

    for (int i = 0; i < C; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<int> v;
    for (int i = 1; i <= R; i++)
        v.push_back(freq[i]);

    sort(v.begin(), v.end(), greater<int>());

    long long ans = 0;
    for (int i = 0; i < K && i < (int)v.size(); i++)
        ans += v[i];
    cout << ans <<endl;
    return 0;
}
