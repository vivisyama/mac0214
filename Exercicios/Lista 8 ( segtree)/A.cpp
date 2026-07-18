#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 200000;

int n, q;
int arr[MAXN + 5];
int seg[4 * MAXN + 5];
void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        update(node * 2, l, mid, idx, val);
    else
        update(node * 2 + 1, mid + 1, r, idx, val);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
        return INT_MAX;
    if (ql <= l && r <= qr)
        return seg[node];

    int mid = (l + r) / 2;
    return min(
        query(node * 2, l, mid, ql, qr),
        query(node * 2 + 1, mid + 1, r, ql, qr)
    );
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, u;
            cin >> k >> u;
            update(1, 1, n, k, u);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << '\n';
        }
    }
}

