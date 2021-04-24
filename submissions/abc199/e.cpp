#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1 << 18];

int main() {
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    // for (int i = 0; i < n; i++) dp[1 << i] = 0;

    vector<pair<int, int>> yz[20];
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        yz[x].push_back({y, z});
    }

    for (int bit = 0; bit < (1 << n); bit++) {
        if (dp[bit] == 0) continue;

        vector<int> all;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) all.push_back(i + 1);
        }
        int cnt = all.size();
        vector<int> sums(20, 0);
        for (int e : all) {
            sums[e]++;
        }
        for (int i = 0; i + 1 < 20; i++) sums[i + 1] += sums[i];

        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) continue;
            bool ok = true;
            for (auto p : yz[cnt + 1]) {
                int y = p.first, z = p.second;
                int val = i + 1;
                int count = sums[y];
                if (val <= y) count++;
                if (count > z) ok = false;
            }
            if (ok) dp[bit | (1 << i)] += dp[bit];
        }
    }

    // for (int i = 0; i < (1 << n); i++) {
    //     for (int j = 0; j < n; j++)
    //         if (i & (1 << j)) cout << j + 1 << " ";
    //     cout << ": " << dp[i] << endl;
    // }

    cout << dp[(1 << n) - 1] << endl;
}
