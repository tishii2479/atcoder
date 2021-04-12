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
    ll n, m, s;
    cin >> n >> m >> s;
    vector<vector<ll>> dp(2600, vector<ll>(n, INF));
    vector<pair<int, pint>> edges[51];
    vector<pair<int, int>> town(n);
    for (int i = 0; i < m; i++) {
        // a = ginka, b = duration
        int u, v, a;
        ll b;
        cin >> u >> v >> a >> b;
        u--, v--;
        edges[u].push_back({v, {a, b}});
        edges[v].push_back({u, {a, b}});
    }
    for (int i = 0; i < n; i++) {
        ll c, d;
        cin >> c >> d;
        town[i] = {c, d};
    }
    stack<int> st;
    st.push(0);
    dp[min(2500LL, s)][0] = 0;
    while (st.empty() == false) {
        int v = st.top();
        st.pop();
        for (int i = 0; i <= 2500; i++) {
            if (i + town[v].first <= 2500)
                dp[i + town[v].first][v] = min(dp[i + town[v].first][v], dp[i][v] + town[v].second);
        }
        for (auto p : edges[v]) {
            int u = p.first;
            ll ginka = p.second.first;
            ll time = p.second.second;
            bool need = false;
            for (int i = 0; i <= 2500; i++) {
                if (i + ginka <= 2500 and dp[i][u] > dp[i + ginka][v] + time) {
                    dp[i][u] = dp[i + ginka][v] + time;
                    need = true;
                }
            }
            if (need)
                st.push(u);
        }
    }
    for (int i = 1; i < n; i++) {
        ll mn = INF;
        // cout << i << endl;a
        for (int j = 0; j < 2500; j++) {
            // if (j < 30)
            //     cout << (dp[j][i] == INF ? "INF" : to_string(dp[j][i])) << " ";
            mn = min(mn, dp[j][i]);
        }
        // cout << endl;
        cout << mn << endl;
    }
}