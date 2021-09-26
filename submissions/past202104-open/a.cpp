#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
    if (s[3] != '-') return false;
    for (int i = 0; i < 8; i++) {
        if (i == 3) continue;
        int v = (s[i] - '0');
        if (v < 0 or v >= 10) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << (solve(s) ? "Yes" : "No") << endl;
}
