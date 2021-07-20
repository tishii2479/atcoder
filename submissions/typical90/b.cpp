#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s;
    for (int bit = 0; bit < (1 << n); bit++) {
        string str = "";
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i))
                str += '(';
            else
                str += ')';
        }

        bool ok = true;
        int cur = 0;

        for (int i = 0; i < n; i++) {
            if (str[i] == '(') {
                cur++;
            } else {
                cur--;
                if (cur < 0) ok = false;
            }
        }

        if (cur != 0) ok = false;
        if (ok) s.push_back(str);
    }

    sort(s.begin(), s.end());
    for (auto e : s) cout << e << endl;
}
