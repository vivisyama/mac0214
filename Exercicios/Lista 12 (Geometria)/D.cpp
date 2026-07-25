#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point{
    ll x,y;
};
ll cross(Point a, Point b, Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool onSegment(Point a, Point b, Point p){
    return min(a.x,b.x) <=p.x && p.x <=max(a.x,b.x) && min(a.y,b. y) <=p.y && p.y <=max(a.y,b.y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        Point a,b,c,d;
        cin>>a.x>>a.y>>b.x>>b.y;
        cin>>c.x>>c.y>>d.x>>d.y;
        ll o1=cross(a,b,c);
        ll o2=cross(a,b,d);
        ll o3=cross(c,d,a);
        ll o4=cross(c,d,b);

        bool ok = false;

        if((o1>0)!=(o2>0) && (o3>0)!=(o4>0)) ok =true;
        if(o1==0 && onSegment(a,b,c)) ok =true;
        if(o2==0 && onSegment(a,b,d)) ok =true;
        if(o3==0 && onSegment(c,d,a)) ok =true;
        if(o4==0 && onSegment(c,d,b)) ok =true;

        cout << (ok ? "YES" : "NO") << "\n";
    }
}
