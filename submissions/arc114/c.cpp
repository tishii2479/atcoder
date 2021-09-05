#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

const int N = 5100;
using mint = atcoder::modint998244353;
mint pw[N][N];

int main() {
    int n, m;
    cin >> n >> m;

    mint ans = 0;
    for (int i = 0; i < N; i++) {
        pw[i][0] = 1;
        for (int j = 0; j + 1 < N; j++) {
            pw[i][j + 1] = pw[i][j] * i;
        }
    }

    // 1-indexed
    for (int x = 1; x <= m; x++) {
        for (int k = 1; k <= n; k++) {
            if (k > 1) {
                ans += pw[m][n - k] * (x - 1) * pw[m - x][k - 2] * (n - k + 1);
            }
            ans += pw[m][n - k] * pw[m - x][k - 1];
        }
    }

    cout << ans.val() << endl;
}
