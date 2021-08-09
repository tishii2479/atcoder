#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
    bool all_same = true;
    for (int i = 0; i < 4; i++)
        if (s[i] != s[0]) all_same = false;
    if (all_same) return false;

    bool ng = true;

    for (int i = 0; i < 3; i++) {
        int val1 = s[i] - '0';
        int val2 = s[i + 1] - '0';
        if ((val1 + 1) % 10 != val2) ng = false;
    }

    if (ng) return false;

    return true;
}

int main() {
    string s;
    cin >> s;
    cout << (solve(s) ? "Strong" : "Weak") << endl;
}
