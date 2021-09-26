#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); i += 4) {
        if (s[i] == 'o') {
            cout << i / 4 + 1 << endl;
            return 0;
        }
    }
    cout << "none" << endl;
}
