#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using mint = modint998244353;

mint factorial(int n) {
    mint res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}

const int N = 11000;
mint dp[110][N];

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    vector<int> cnt(110, 0);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cnt[w[i]]++;
        sum += w[i];
    }

    if (sum % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            for (int k = 0; k < N; k++) {
                dp[j + 1][k + w[i]] += dp[j][k];
            }
        }
    }

    int half = sum / 2;

    mint ans = 0;

    for (int i = 1; i < n; i++) {
        ans += dp[i][half] * factorial(i) * factorial(n - i);
    }

    cout << ans.val() << endl;
}
