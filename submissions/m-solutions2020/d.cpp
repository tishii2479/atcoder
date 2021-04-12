#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
// const int MOD = 1000000007;
const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // 0 = stock max, money
    // 1 = stock, money max
    // 2 = money max
    // stock, money
    pll dp[81][3];
    dp[0][0] = dp[0][1] = dp[0][2] = {0, 1000};
    for (int i = 0; i < n; i++) {
        vector<pll> cand;
        for (int j = 0; j < 3; j++) {
            cand.push_back({0, dp[i][j].second + dp[i][j].first * a[i]});
        }
        sort(cand.begin(), cand.end(), greater<pll>());
        dp[i + 1][2] = cand[0];
        cand.clear();
        for (int j = 0; j < 3; j++) {
            cand.push_back({dp[i][j].first + dp[i][j].second / a[i], dp[i][j].second % a[i]});
        }
        sort(cand.begin(), cand.end(), greater<pll>());
        dp[i + 1][0] = cand[0];
        sort(cand.begin(), cand.end(), [&](pll a, pll b) {
            return a.second > b.second;
        });
        dp[i + 1][1] = cand[0];
    }
    cout << dp[n][2].second << endl;
}