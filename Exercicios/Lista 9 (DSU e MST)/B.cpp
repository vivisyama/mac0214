#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> par, rnk, sz;
    DSU(int n): par(n+1), rnk(n+1,0), sz(n+1,1) { iota(par.begin(), par.end(), 0); }
    int find(int x){ while(par[x]!=x){ par[x]=par[par[x]]; x=par[x]; } return x; }

    int unite(int a,int b){

        a=find(a); b=find(b);
        if(a==b) return 0;
        if(rnk[a]<rnk[b]) swap(a,b);
        par[b]=a;
        sz[a] += sz[b];
        if(rnk[a]==rnk[b]) rnk[a]++;
        return sz[a];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    int components = n;
    int maxSize = (n >= 1) ? 1 : 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        int newSize = dsu.unite(a, b);
        if (newSize > 0) {
            components--;
            maxSize = max(maxSize, newSize);
        }
        cout << components << " " << maxSize << endl;
    }

    return 0;
}
