#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 200;
    }

    n = min(n, 10);

    vector<vector<int>> dp(200);

    for (int bit = 0; bit < (1 << n); bit++) {
        vector<int> v;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                sum += a[i];
                v.push_back(i);
            }
        }

        sum %= 200;
        if (dp[sum].size() != 0) {
            cout << "Yes" << endl;
            cout << dp[sum].size() << " ";
            for (int e : dp[sum]) cout << e + 1 << " ";
            cout << endl;
            cout << v.size() << " ";
            for (int e : v) cout << e + 1 << " ";
            cout << endl;
            return 0;
        } else {
            dp[sum] = v;
        }
    }
    cout << "No" << endl;
}
