#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int a, b;
        cin >> a >> b;
        if (a >= b)
            cout << "FunkyMonkeys\n";
        else
            cout << "WeWillEatYou\n";
    }
    return 0;
}
