#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c;
    cin >>n >>a >>b >>c;

    vector <long long> max_pieces(n + 1, -1e9);
    max_pieces[0]=0;

    for (int i = 1; i <= n; i++) {
        if(i-a >=0) max_pieces[i] = max(max_pieces[i],max_pieces[i-a] +1);
        if(i-b >= 0) max_pieces[i] = max(max_pieces[i],max_pieces[i-b] +1);
        if (i-c>=0)max_pieces[i] = max(max_pieces[i], max_pieces[i-c] +1);
    }
    cout << max_pieces[n] <<endl;
}
