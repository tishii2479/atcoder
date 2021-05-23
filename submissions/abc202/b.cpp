#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            cout << '0';
        else if (s[i] == '1')
            cout << '1';
        else if (s[i] == '6')
            cout << '9';
        else if (s[i] == '8')
            cout << '8';
        else if (s[i] == '9')
            cout << '6';
    }
    cout << endl;
}
