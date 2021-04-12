#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<char> t(q), d(q);
    for (int i = 0; i < q; i++)
        cin >> t[i] >> d[i];
    // find left border
    int l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int now = m;
        bool ok = true;
        for (int i = 0; i < q; i++) {
            if (t[i] == s[now]) {
                if (d[i] == 'L')
                    now--;
                else
                    now++;
            }
            if (now >= n) {
                ok = true;
                break;
            }
            if (now < 0) {
                ok = false;
                break;
            }
        }
        if (ok)
            r = m;
        else
            l = m;
    }
    int left_border = l;
    // find right border
    l = -1, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int now = m;
        bool ok = true;
        for (int i = 0; i < q; i++) {
            if (t[i] == s[now]) {
                if (d[i] == 'L')
                    now--;
                else
                    now++;
            }
            if (now >= n) {
                ok = false;
                break;
            }
        }
        if (ok)
            l = m;
        else
            r = m;
    }
    int right_border = r;
    cout << max(0, right_border - left_border - 1) << endl;
}