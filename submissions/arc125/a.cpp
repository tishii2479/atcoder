#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];

    set<int> st;
    for (int i = 0; i < n; i++) st.insert(s[i]);

    for (int i = 0; i < m; i++) {
        if (st.find(t[i]) == st.end()) {
            cout << -1 << endl;
            return 0;
        }
    }

    int right_nearest = 1 << 30;
    for (int i = 0; i < n; i++) {
        if (s[i] != s[0]) {
            right_nearest = i;
            break;
        }
    }

    int left_nearest = 1 << 30;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != s[0]) {
            left_nearest = n - i;
            break;
        }
    }

    int ans = m;
    bool did = false;
    for (int i = 0; i < m; i++) {
        if (t[i] != s[0] and did == false) {
            did = true;
            ans += min(left_nearest, right_nearest);
            continue;
        }

        if (i > 0) {
            if (t[i - 1] != t[i]) ans++;
        }

        // cout << i << " " << ans << endl;
    }

    cout << ans << endl;
}
