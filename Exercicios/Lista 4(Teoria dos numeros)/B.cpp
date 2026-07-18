#include <iostream>

using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    if (n ==0) {
        cout << 0 << endl;
        return 0;
    }
    if (n ==1) {
        cout << 1 << endl;
        return 0;
    }

    long long mod = 1000000007;
    long long res[2][2] = {{1, 0}, {0, 1}};
    long long a[2][2] = {{1, 1}, {1, 0}};
    while (n > 0) {
        if (n % 2 == 1) {
            long long t[2][2] = {0};
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        t[i][j] = (t[i][j] + res[i][k] * a[k][j]) % mod;
            
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    res[i][j] = t[i][j];
        }

        long long t[2][2] = {0};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j<2; j++)
                for (int k = 0; k < 2; k++)
                    t[i][j] = (t[i][j] + a[i][k] * a[k][j]) % mod;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a[i][j] = t[i][j];

        n /= 2;
    }

    cout << res[0][1] << endl;

    return 0;
}
