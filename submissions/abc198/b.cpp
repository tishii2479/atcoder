#include <bits/stdc++.h>
using namespace std;
bool isOk(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}
int main() {
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 0; i < 12; i++) {
        string str = string(i, '0') + s;
        if (isOk(str)) ok = true;
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}