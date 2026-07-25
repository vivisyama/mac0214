#include <bits/stdc++.h>
using namespace std;

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

    int n;
    cin >> n;

    vector<pair<int,int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    DSU dsu(n);
    vector<pair<int,int>> redundant; 
    for (auto& [a, b] : edges) {
        if (!dsu.unite(a, b)) {
            redundant.push_back({a, b});
        }
    }

    DSU dsu2(n);
    for (auto& [a, b] : edges) {
        dsu2.unite(a, b); 
    }

    vector<pair<int,int>> newEdges;
    int ptr = 0;

    for (int v = 2; v <= n; v++) {
        if (dsu2.find(v) != dsu2.find(1)) {
            newEdges.push_back({redundant[ptr].first, v}); 
            dsu2.unite(1, v);
            ptr++;
        }
    }
    cout << newEdges.size() << endl;
    for (int i = 0; i < (int)newEdges.size(); i++) {
        cout << redundant[i].first << " " << redundant[i].second << " "
             << 1 << " " << newEdges[i].second << endl;
    }

    return 0;
}
