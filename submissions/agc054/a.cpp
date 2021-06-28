#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    int n = s.length();
    if (s[0] != s[n - 1]) return 1;
    for (int i = 1; i < n - 2; i++) {
        if (s[0] != s[i] and s[i + 1] != s[n - 1]) return 2;
    }

    return -1;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(s) << endl;
}
