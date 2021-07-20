#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
    using mint = modint1000000007;
    const int N = 61;
    long long n;
    int b, k;
    cin >> n >> b >> k;
    vector<int> c(k);

    for (int i = 0; i < k; i++) cin >> c[i];

    mint dp[N][1000];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 1000; j++) dp[i][j] = 0;
    for (int i = 0; i < k; i++) dp[0][c[i] % b] += 1;

    int pow10[N];
    pow10[0] = 1;
    for (int i = 0; i + 1 < N; i++) pow10[i + 1] = pow_mod(10, 1LL << i, b);

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < b; j++) {
            for (int l = 0; l < b; l++) {
                dp[i + 1][(j * pow10[i + 1] + l) % b] += dp[i][j] * dp[i][l];
            }
        }
    }

    mint dp2[1000];
    bool did = false;
    for (int i = N - 1; i >= 0; i--) {
        if ((1LL << i) <= n) {
            mint nxt[1000];
            for (int i = 0; i < 1000; i++) nxt[i] = 0;
            if (did == false) {
                for (int j = 0; j < 1000; j++) nxt[j] = dp[i][j];
                did = true;
            } else {
                for (int j = 0; j < b; j++) {
                    for (int l = 0; l < b; l++) {
                        nxt[(j + l * pow10[i + 1]) % b] += dp[i][j] * dp2[l];
                    }
                }
            }
            n -= (1LL << i);
            swap(nxt, dp2);
        }
    }

    cout << dp2[0].val() << endl;
}
