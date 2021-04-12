#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> edges(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a][b] = edges[b][a] = true;
    }
    vector<bool> ok(1 << n, true);
    for (int bit = 0; bit < (1 << n); bit++) {
        vector<int> v;
        for (int i = 0; i < n; i++)
            if (bit & (1 << i))
                v.push_back(i);
        for (int i = 0; i < v.size() && ok[bit]; i++)
            for (int j = i + 1; j < v.size() && ok[bit]; j++)
                if (edges[v[i]][v[j]] == false)
                    ok[bit] = false;
    }
    const int inf = 1 << 28;
    vector<int> dp(1 << n, inf);
    dp[0] = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        int cbit = (1 << n) - 1 - bit;
        for (int add = cbit;; add = (add - 1) & cbit) {
            if (ok[add])
                dp[bit | add] = min(dp[bit | add], dp[bit] + 1);
            if (!add)
                break;
        }
    }
    // for (int bit = 0; bit < (1 << n); bit++)
    //     cout << bit << " " << ok[bit] << " " << dp[bit] << endl;
    cout << dp[(1 << n) - 1] << endl;
}