#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    bool flip = false;
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        if (t == 1) {
            if (flip) {
                swap(s[(a + n) % (2 * n)], s[(b + n) % (2 * n)]);
            } else {
                swap(s[a], s[b]);
            }
        } else {
            flip = !flip;
        }
    }
    if (flip) {
        for (int i = 0; i < n; i++)
            cout << s[i + n];
        for (int i = 0; i < n; i++)
            cout << s[i];
        cout << endl;
    } else {
        cout << s << endl;
    }
}
