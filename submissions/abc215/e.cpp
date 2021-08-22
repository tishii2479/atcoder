#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using mint = atcoder::modint998244353;

const int N = 10;
mint dp[1 << N][N];

int main() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        mint nxt[1 << N][N];

        for (int bit = 0; bit < (1 << N); bit++)
            for (int j = 0; j < N; j++) nxt[bit][j] = dp[bit][j];

        int idx = s[i] - 'A';

        for (int bit = 0; bit < (1 << N); bit++) {
            nxt[bit][idx] += dp[bit][idx];

            for (int j = 0; j < N; j++) {
                if (idx != j) {
                    // when change current head
                    if (bit & (1 << j)) continue;
                    if (bit & (1 << idx)) continue;

                    nxt[bit | (1 << j)][idx] += dp[bit][j];
                }
            }
        }

        nxt[0][idx] += 1;
        swap(nxt, dp);

        // cout << endl
        //      << i << endl
        //      << endl;

        // for (int bit = 0; bit < (1 << N); bit++) {
        //     for (int j = 0; j < N; j++) {
        //         if (dp[bit][j].val() > 0) {
        //             for (int i = 0; i < N; i++)
        //                 if (bit & (1 << i)) cout << ((char)('A' + i)) << " ";
        //             cout << ": " << ((char)('A' + j)) << " " << dp[bit][j].val() << endl;
        //         }
        //     }
        // }
    }

    mint ans = 0;

    for (int bit = 0; bit < (1 << N); bit++) {
        for (int j = 0; j < N; j++) {
            ans += dp[bit][j];
        }
    }

    cout << ans.val() << endl;
}
