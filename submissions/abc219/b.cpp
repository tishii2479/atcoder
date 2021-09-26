#include <bits/stdc++.h>
using namespace std;

int main() {
    string s[3];
    for (int i = 0; i < 3; i++) cin >> s[i];

    string t;
    cin >> t;
    for (char c : t) {
        int v = c - '1';
        cout << s[v];
    }
    cout << endl;
}
