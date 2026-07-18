
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <string> s(n);
        unordered_set <string> st;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
            st.insert(s[i]);
        }

        string conc = "";
        for (int i = 0; i<n; i++) {
            bool check = false;

            for (int j = 1; j< s[i].size(); j++) {
                string l= s[i].substr(0, j);
                string r= s[i].substr(j);
                if (st.count(l) && st.count(r)) {
                    check = true;
                    break;
                }
            }
            if (check) conc+= '1';
            else conc+= '0';
        }

        cout << conc <<endl;
    }
}
