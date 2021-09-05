#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<map<long long, long long>> dp(n + 1);
    dp[0][x] = 1;

    reverse(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        for (auto m : dp[i]) {
            long long val = m.first;
            long long nxt = (val / a[i]) * a[i];
            dp[i + 1][abs(nxt - val)] += m.second;

            long long nxt2 = ((val + a[i] - 1) / a[i]) * a[i];

            if (nxt2 == nxt) continue;
            if (i > 0 and nxt2 >= a[i - 1]) continue;
            dp[i + 1][abs(nxt2 - val)] += m.second;
        }
    }

    cout << dp[n][0] << endl;
}
