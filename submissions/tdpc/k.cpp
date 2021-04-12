#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int dp[51][11000];
int dp2[51][11000];
int main() {
    int n, w, c;
    cin >> n >> w >> c;
    vector<pint> items[51];
    for (int i = 0; i < n; i++) {
        int w, v, c;
        cin >> w >> v >> c;
        c--;
        items[c].push_back({w, v});
    }
    for (int i = 0; i < 50; i++) {
        if (items[i].size() == 0)
            continue;
        memcpy(dp2, dp, sizeof(dp));
        for (int l = c - 1; l >= 0; l--)
            for (int j = 0; j < items[i].size(); j++)
                for (int k = w; k - items[i][j].first >= 0; k--)
                    dp2[l][k] = max(dp2[l][k], dp2[l][k - items[i][j].first] + items[i][j].second);
        for (int l = c - 1; l >= 0; l--)
            for (int k = w; k >= 0; k--)
                dp[l + 1][k] = max(dp[l + 1][k], dp2[l][k]);
    }
    cout << dp[c][w] << endl;
}