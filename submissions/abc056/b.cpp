#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 11000;
ll dp[N];

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int sum = N - 1; sum >= 0; sum--) {
            if (sum - a[i] >= 0) dp[sum] += dp[sum - a[i]];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        vector<ll> sums(N, 0);
        for (int sum = 0; sum < N; sum++) {
            if (sum - a[i] >= 0) {
                sums[sum] = dp[sum] - sums[sum - a[i]];
            } else {
                sums[sum] = dp[sum];
            }
        }

        bool ok = true;

        for (int sum = max(0LL, k - a[i]); sum < k; sum++) {
            if (sums[sum] != 0) {
                ok = false;
                break;
            }
        }

        if (ok) cnt++;
    }

    cout << cnt << endl;
}
