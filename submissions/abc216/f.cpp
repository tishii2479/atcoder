#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    using mint = atcoder::modint998244353;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    const int N = 5100;
    vector<mint> dp(N, 0);
    dp[0] = 1;

    mint ans = 0;

    for (int i : idx) {
        int upper = a[i] - b[i];
        for (int j = 0; j <= upper; j++) {
            ans += dp[j];
        }

        for (int j = N - 1; j >= 0; j--) {
            if (j + b[i] >= N) continue;
            dp[j + b[i]] += dp[j];
        }
    }

    cout << ans.val() << endl;
}
