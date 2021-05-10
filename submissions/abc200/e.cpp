#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3100000;
ll dp[4][N];

int main() {
    ll n, k;
    cin >> n >> k;

    dp[0][0] = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j + 1 < N; j++) {
            dp[i + 1][j + 1] += dp[i][j];
            if (j + n + 1 < N)
                dp[i + 1][j + n + 1] -= dp[i][j];
        }
        for (int j = 0; j + 1 < N; j++) {
            dp[i + 1][j + 1] += dp[i + 1][j];
        }
    }

    // for (int i = 0; i < 10; i++) {
    //     cout << dp[3][i] << " ";
    // }
    // cout << endl;

    ll sum = 3;
    for (; k - dp[3][sum] > 0; sum++) {
        // cout << sum << " " << dp[3][sum] << " " << k << endl;
        k -= dp[3][sum];
    }

    // cout << sum << " " << k << endl;

    ll a = 1;
    for (;; a++) {
        ll bc = sum - a;
        ll pat;
        if (n < bc) {
            pat = n - (bc - n) + 1;
        } else {
            pat = bc - 1;
        }
        pat = max(0LL, pat);
        if (pat >= k) break;
        k -= pat;
    }

    ll bc = sum - a;
    ll b = max(1LL, (bc - n)) + k - 1;
    ll c = bc - b;
    cout << a << " " << b << " " << c << endl;
}
