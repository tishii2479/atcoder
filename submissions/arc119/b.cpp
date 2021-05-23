#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    vector<int> s0, t0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            s0.push_back(i);
        }
        if (t[i] == '0') {
            t0.push_back(i);
        }
    }

    if (s0.size() != t0.size()) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;

    for (int i = 0; i < s0.size(); i++) {
        if (s0[i] != t0[i]) {
            ans++;
        }
    }

    cout << ans << endl;
}
