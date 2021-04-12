#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    string t = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.')
            break;
        t += s[i];
    }
    cout << t << endl;
}