#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<bool> used(2 * n, false);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] != -1) {
            a[i]--;
            if (used[a[i]]) ok = false;
            used[a[i]] = true;
        }
        if (b[i] != -1) {
            b[i]--;
            if (used[b[i]]) ok = false;
            used[b[i]] = true;
        }
        if (a[i] != -1 and b[i] != -1 and a[i] >= b[i]) ok = false;
    }

    if (!ok) {
        cout << "No" << endl;
        return 0;
    }

    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        if (!dp[i]) continue;
        for (int j = 1; i + j <= n; j++) {
            if (dp[i + j]) continue;

            bool ok = true;
            for (int k = 0; k < n and ok; k++) {
                bool is_used_a = (i * 2 <= a[k] and a[k] < i * 2 + j);
                bool is_used_b = (i * 2 + j <= b[k] and b[k] < i * 2 + j * 2);

                if (a[k] != -1 and b[k] != -1) {
                    if (is_used_a ^ is_used_b) ok = false;
                    if (is_used_a and is_used_b and b[k] - a[k] != j) ok = false;
                }
                if (a[k] != -1) {
                    if (i * 2 + j <= a[k] and a[k] < i * 2 + j * 2) ok = false;
                    if (is_used_a and b[k] != a[k] + j and used[a[k] + j]) ok = false;
                }
                if (b[k] != -1) {
                    if (i * 2 <= b[k] and b[k] < i * 2 + j) ok = false;
                    if (is_used_b and a[k] != b[k] - j and used[b[k] - j]) ok = false;
                }
            }

            dp[i + j] = ok;
        }
    }

    cout << (dp[n] ? "Yes" : "No") << endl;
}
