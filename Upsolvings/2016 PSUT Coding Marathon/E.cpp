#include <bits/stdc++.h>
using namespace std;

bool oneRemoved(string a, string b) {
    if (a.size() != b.size() + 1)
        return false;
    int i = 0, j = 0;
    bool removed = false;
    while (i < a.size() && j < b.size()) {
        if (a[i] != b[j]) {
            if (removed)
                return false;
            removed = true;
            i++; // pula o caractere removido
        } else {
            i++;
            j++;
        }
    }

    return true;
}

int main() {
    string password, entered;
    cin >> password;
    cin >> entered;
    if (password == entered) {
        cout << "yes\n";
        return 0;
    }
    if (password.size() < 8) {
        cout << "no\n";
        return 0;
    }
    if (password.size() == entered.size()) {
        int diff = 0;
        for (int i = 0; i < password.size(); i++) {
            if (password[i] != entered[i])
                diff++;
        }

        if (diff == 1) {
            cout << "yes\n";
            return 0;
        }
    }
    if (oneRemoved(password, entered)) {
        cout << "yes\n";
        return 0;
    }
    cout << "no\n";
    return 0;
}
