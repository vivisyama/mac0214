#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;

    vector<int> tread(n);

    for (int i = 0; i < n; i++) {
        cin >> tread[i];
    }

    int ans= 0;
    int l = 0;
    long long soma= 0;

    for (int j = 0; j < n;j++) {
        soma+= tread[j];

        while (soma > t) {
            soma -= tread[l];
            l++;
        }
        ans= max(ans, j - l + 1);
    }

    cout << ans << endl;
}
