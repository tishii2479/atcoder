#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    const int n = s.length();
    if (s == t) {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 0; i + 1 < n; i++) {
        swap(s[i], s[i + 1]);
        if (s == t) {
            cout << "Yes" << endl;
            return 0;
        }
        swap(s[i], s[i + 1]);
    }
    cout << "No" << endl;
}
