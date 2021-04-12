#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++)
        cnt[a[i]]++;
    vector<vector<int>> dp(1 << m, vector<int>(m, inf));
    vector<vector<int>> sums(m, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            sums[i][j + 1] = sums[i][j] + (a[j] != i);
    for (int i = 0; i < m; i++)
        dp[1 << i][i] = sums[i][cnt[i]] - sums[i][0];
    for (int bit = 0; bit < (1 << m); bit++) {
        for (int now = 0; now < m; now++)
            if (bit & (1 << now))
                for (int nxt = 0; nxt < m; nxt++)
                    if (!(bit & (1 << nxt))) {
                        int l = 0;
                        for (int i = 0; i < m; i++)
                            if (bit & (1 << i))
                                l += cnt[i];
                        int cur = sums[nxt][l + cnt[nxt]] - sums[nxt][l];
                        dp[bit | (1 << nxt)][nxt] = min(dp[bit | (1 << nxt)][nxt], dp[bit][now] + cur);
                    }
    }
    int ans = inf;
    for (int i = 0; i < m; i++)
        ans = min(ans, dp[(1 << m) - 1][i]);
    cout << ans << endl;
}