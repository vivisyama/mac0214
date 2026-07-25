#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int mxW = 0, mxH = 0;
        while (n--) {
            int w, h;
            cin >> w >> h;
            mxW = max(mxW, w);
            mxH = max(mxH, h);
        }
        cout << 2 * (mxW + mxH) << endl;
    }

    return 0;
}
