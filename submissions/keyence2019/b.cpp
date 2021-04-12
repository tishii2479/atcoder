#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    string s;
    cin >> s;
    const string t = "keyence";
    for (int l = 0; l < s.length(); l++) {
        int r = l + (s.length() - t.length());
        string test = "";
        for (int i = 0; i < l; i++)
            test += s[i];
        for (int i = r; i < s.length(); i++)
            test += s[i];
        if (test.length() != t.length())
            break;
        if (test == t) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}