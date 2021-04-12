#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
double f(double r1, double r2) {
    return 1 / (1 + pow(10, (r2 - r1) / 400));
}
int main() {
    int k;
    cin >> k;
    vector<double> rate(1 << k);
    for (int i = 0; i < (1 << k); i++)
        cin >> rate[i];
    vector<vector<double>> dp(1 << k, vector<double>(k + 1, 0));
    for (int rnd = 0; rnd <= k; rnd++)
        for (int i = 0; i < (1 << k); i++) {
            if (rnd == 0) {
                dp[i][rnd] = 1;
                continue;
            }
            int l = i / (1 << rnd) * (1 << rnd);
            int r = l + (1 << rnd) - 1;
            if (abs(i - l) < abs(i - r))
                l += (1 << rnd) / 2;
            else
                r -= (1 << rnd) / 2;
            // cout << rnd << " " << i << " " << l << " " << r << endl;
            for (int j = l; j <= r; j++) {
                if (i == j)
                    continue;
                dp[i][rnd] += f(rate[i], rate[j]) * dp[j][rnd - 1];
            }
            dp[i][rnd] *= dp[i][rnd - 1];
        }
    for (int i = 0; i < (1 << k); i++)
        printf("%.15lf\n", dp[i][k]);
}