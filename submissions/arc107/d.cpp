#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using mint = modint998244353;

const int N = 3100;
vector<vector<mint>> dp(N + 1, vector<mint>(N + 1, -1));

mint f(int n, int k) {
    if (n == 0) {
        if (k == 0)
            return 1;
        else
            return 0;
    }
    if (k > n) return 0;
    if (k <= 0) return 0;
    if (n < 0) return 0;
    if (dp[n][k] != mint(-1)) return dp[n][k];
    return dp[n][k] = f(n - 1, k - 1) + f(n, 2 * k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << f(n, k).val() << endl;
}
