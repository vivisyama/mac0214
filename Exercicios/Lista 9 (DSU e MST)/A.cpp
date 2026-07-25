#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
    vector<int> par, rnk;
    DSU(int n): par(n+1), rnk(n+1,0) { iota(par.begin(), par.end(), 0); }
    int find(int x){ while(par[x]!=x){ par[x]=par[par[x]]; x=par[x]; } return x; }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(rnk[a]<rnk[b]) swap(a,b);
        par[b]=a;
        if(rnk[a]==rnk[b]) rnk[a]++;
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<ll,int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    ll totalCost = 0;
    int usedEdges = 0;

    for (auto& [c, a, b] : edges) {
        if (dsu.unite(a, b)) {
            totalCost += c;
            usedEdges++;
        }
    }

    if (usedEdges == n - 1) {
        cout << totalCost << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
