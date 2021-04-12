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
    vector<vector<pll>> path(n, vector<pll>(n, {-1, -1}));
    for (int i = 0; i < m; i++) {
        int s, t;
        ll d, time;
        cin >> s >> t >> d >> time;
        s--, t--;
        path[s][t] = path[t][s] = {d, time};
    }
    vector<vector<ll>> dp(1 << n, vector<ll>(n, INF));
    vector<vector<ll>> cnt(1 << n, vector<ll>(n, 1));
    dp[1 << 0][0] = 0;
    for (int bit = 0; bit < (1 << n); bit++)
        for (int now = 0; now < n; now++)
            if (bit & (1 << now))
                for (int nxt = 0; nxt < n; nxt++)
                    if ((bit & (1 << nxt)) == false) {
                        // cout << now << " " << nxt << " " << path[now][nxt].first << " " << path[now][nxt].second << endl;
                        if (path[now][nxt].first == -1)
                            continue;
                        if (path[now][nxt].second < dp[bit][now] + path[now][nxt].first)
                            continue;
                        if (dp[bit | (1 << nxt)][nxt] > dp[bit][now] + path[now][nxt].first)
                            cnt[bit | (1 << nxt)][nxt] = cnt[bit][now];
                        else if (dp[bit | (1 << nxt)][nxt] == dp[bit][now] + path[now][nxt].first)
                            cnt[bit | (1 << nxt)][nxt] += cnt[bit][now];
                        dp[bit | (1 << nxt)][nxt] = min(dp[bit | (1 << nxt)][nxt], dp[bit][now] + path[now][nxt].first);
                    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 1 << n; j++)
    //         cout << dp[j][i] << " ";
    //     cout << endl;
    // }
    ll ans = INF;
    ll cn = 0;
    for (int i = 0; i < n; i++) {
        // cout << dp[(1 << n) - 1][i] << " " << path[i][0].first << " " << path[i][0].second << " " << cnt[(1 << n) - 1][i] << endl;
        if (path[i][0].first != -1) {
            if (ans > dp[(1 << n) - 1][i] + path[i][0].first and dp[(1 << n) - 1][i] + path[i][0].first <= path[i][0].second) {
                ans = dp[(1 << n) - 1][i] + path[i][0].first;
                cn = cnt[(1 << n) - 1][i];
            } else if (ans == dp[(1 << n) - 1][i] + path[i][0].first and dp[(1 << n) - 1][i] + path[i][0].first <= path[i][0].second)
                cn += cnt[(1 << n) - 1][i];
        }
    }
    if (ans == INF) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << ans << " " << cn << endl;
}