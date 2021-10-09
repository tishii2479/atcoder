#include <bits/stdc++.h>
using namespace std;

const int N = 16;
vector<long double> dp(1 << N);
vector<bool> seen(1 << N, false);

long double rec(int bit) {
    if (seen[bit]) return dp[bit];
    if (bit == 0) return 0;

    seen[bit] = true;
    dp[bit] = 1e20;
    for (int i = 1; i <= 14; i++) {
        long double val = 1;
        int cnt = 0;
        for (int d = -1; d <= 1; d++) {
            int c = i + d;
            if (bit & (1 << c)) {
                val += rec(bit - (1 << c)) / 3;
            } else {
                cnt++;
            }
        }
        if (cnt == 3) continue;
        dp[bit] = min(dp[bit], val * 3.0 / (3 - cnt));
    }
    return dp[bit];
}

int main() {
    int n;
    cin >> n;
    int mask = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mask |= (1 << x);
    }
    cout << fixed << setprecision(15) << rec(mask) << endl;
}
