#include <iostream>
using namespace std;

int main() {
    long long n;
    while (cin >> n && n != 0) {
        long long s = n * (n + 1) / 2;
        cout << s * s << '\n';
    }
    return 0;
}
