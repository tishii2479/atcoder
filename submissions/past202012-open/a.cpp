#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if ((s[0] == 'o' and s[1] == 'o' and s[2] == 'o') or (s[1] == 'o' and s[2] == 'o' and s[3] == 'o') or (s[2] == 'o' and s[3] == 'o' and s[4] == 'o')) {
        cout << "o" << endl;
    } else if ((s[0] == 'x' and s[1] == 'x' and s[2] == 'x') or (s[1] == 'x' and s[2] == 'x' and s[3] == 'x') or (s[2] == 'x' and s[3] == 'x' and s[4] == 'x')) {
        cout << "x" << endl;
    } else {
        cout << "draw" << endl;
    }
}
