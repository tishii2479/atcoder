#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    string t = "ZONe";
    for (int i = 0; i + 3 < s.length(); i++) {
        bool ok = true;
        for (int j = 0; j < 4; j++) {
            if (s[i + j] != t[j]) ok = false;
        }
        if (ok) cnt++;
    }
    cout << cnt << endl;
}
