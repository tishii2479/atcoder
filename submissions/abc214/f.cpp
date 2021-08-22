#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using mint = atcoder::modint1000000007;

int main() {
    string s;
    cin >> s;
    const int n = s.length();
    const int N = 26;
    vector<vector<mint>> sum(n + 1, vector<mint>(N, 0));

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (i == 0) {
            sum[i + 1][c] = 1;
            continue;
        }

        sum[i + 1][c] = sum[i - 1][c] + 1;
        for (int j = 0; j < N; j++) {
            if (c != j) {
                sum[i + 1][c] += sum[i - 1][j];
                sum[i + 1][j] += sum[i][j];
            }
        }

        // cout << i << endl;
        // for (int j = 0; j < N; j++) cout << sum[i + 1][j].val() << " ";
        // cout << endl;
    }

    mint ans = 0;
    for (int i = 0; i < N; i++) ans += sum[n][i];
    cout << ans.val() << endl;
}
