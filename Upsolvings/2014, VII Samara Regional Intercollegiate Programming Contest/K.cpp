#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int n, m;
int a[MAX], b[MAX];
int segA[4 * MAX], segB[4 * MAX];

void buildA(int no, int l, int r) {
    if (l == r) {
        segA[no] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    buildA(no * 2, l, mid);
    buildA(no * 2 + 1, mid + 1, r);
    segA[no] = max(segA[no * 2], segA[no * 2 + 1]);
}

void buildB(int no, int l, int r) {
    if (l == r) {
        segB[no] = b[l];
        return;
    }
    int mid = (l + r) / 2;
    buildB(no * 2, l, mid);
    buildB(no * 2 + 1, mid + 1, r);
    segB[no] = max(segB[no * 2], segB[no * 2 + 1]);
}

int firstGreaterA(int no, int l, int r, int x) {
    if (segA[no] <= x) return -1;
    if (l == r) return l;

    int mid = (l + r) / 2;

    if (segA[no * 2] > x)
        return firstGreaterA(no * 2, l, mid, x);

    return firstGreaterA(no * 2 + 1, mid + 1, r, x);
}

int firstGreaterB(int no, int l, int r, int x) {
    if (segB[no] <= x) return -1;
    if (l == r) return l;

    int mid = (l + r) / 2;

    if (segB[no * 2] > x)
        return firstGreaterB(no * 2, l, mid, x);

    return firstGreaterB(no * 2 + 1, mid + 1, r, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    buildA(1, 1, n);
    buildB(1, 1, n);

    cin >> m;

    vector<int> d(m), t(m);
    for (int i = 0; i < m; i++)
        cin >> d[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];
    for (int i = 0; i < m; i++) {
        int x = firstGreaterA(1, 1, n, d[i]);
        int y = firstGreaterB(1, 1, n, t[i]);
        if (x == -1 && y == -1)
            cout << "Draw\n";
        else if (x == -1)
            cout << "Constantine\n";
        else if (y == -1)
            cout << "Mike\n";
        else if (x == y)
            cout << "Draw\n";
        else if (x < y)
            cout << "Mike\n";
        else
            cout << "Constantine\n";
    }
    return 0;
}
