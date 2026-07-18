#include <algorithm>
#include <iostream>
#include <numeric>
#include <regex>
#include <vector>
 
 
using namespace std;
typedef long long ll;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n>>q;
		vector<ll> a(n);
 
		for (int i =0; i < n; i++) {
			int x;
			cin >> x;
			a[i] = x;
		}
 
		vector<ll> cumsum(n);
		sort(a.begin(), a.end(), greater<ll>());
		partial_sum(a.begin(),a.end(),cumsum.begin());
 
 
		while(q--){
			int query;
			cin >> query;
			auto it = lower_bound(cumsum.begin(),cumsum.end(),query);
			if(it == cumsum.end()){
				cout << -1 << endl;
			}else{
			cout << it - cumsum.begin() + 1 << "\n";
			}
		}
	}
 
	return 0;
}
