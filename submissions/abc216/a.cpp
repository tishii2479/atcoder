#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int x, y;
    if (s[1] == '.') {
        x = s[0] - '0';
        y = s[2] - '0';
    } else {
        x = (s[0] - '0') * 10 + (s[1] - '0');
        y = s[3] - '0';
    }

    if (0 <= y and y <= 2) {
        cout << x << "-" << endl;
    } else if (3 <= y and y <= 6) {
        cout << x << endl;
    } else {
        cout << x << "+" << endl;
    }
}
