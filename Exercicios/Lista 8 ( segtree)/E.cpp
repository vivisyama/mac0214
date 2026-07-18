
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node{
    ll sum, pref, suff, best;
};

const int MAXN = 200000;
int n,q;
ll a[MAXN+5];
Node seg[4*MAXN+5];

Node merge(Node L, Node R){

    Node n;
    n.sum = L.sum + R.sum;
    n.pref = max(L.pref, L.sum + R.pref);
    n.suff = max(R.suff, R.sum + L.suff);
    n.best = max({L.best, R.best, L.suff + R.pref});
    return n;
}

void build(int node,int l,int r){

    if(l==r){
        seg[node].sum = a[l];
        seg[node].pref = max(0LL,a[l]);
        seg[node].suff = max(0LL,a[l]);
        seg[node].best = max(0LL,a[l]);
        return;
    }

    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node]=merge(seg[node*2],seg[node*2+1]);
}

Node query(int node,int l,int r,int ql,int qr){
    if(qr<l || r<ql){
        return {0,0,0,0};
    }
    if(ql<=l && r<=qr)
        return seg[node];
    int mid=(l+r)/2;
    if(qr<=mid)
        return query(node*2,l,mid,ql,qr);
    if(ql>mid)
        return query(node*2+1,mid+1,r,ql,qr);
    return merge(
        query(node*2,l,mid,ql,qr),
        query(node*2+1,mid+1,r,ql,qr)
    );
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l,r).best<<endl;
    }
}
