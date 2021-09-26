#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
vector<int> a(N);
vector<vector<int>> edges(N);
vector<int> dp(N);

struct MedianSet {
    multiset<int> lower, upper;
    void eval() {
        if (lower.size()) {
            auto itr = lower.end();
            itr--;
            upper.insert(*itr);
            lower.erase(itr);
        }
        while (lower.size() < upper.size()) {
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }
    }

    void insert(int val) {
        lower.insert(val);
        eval();
    }

    int median() {
        assert(lower.size());
        auto itr = lower.end();
        itr--;
        if (lower.size() == upper.size() + 1) return *itr;
        return (*itr + *upper.begin()) / 2;
    }

    void erase(int x) {
        assert(lower.size());
        auto itr = lower.end();
        itr--;
        if (*itr < x)
            upper.erase(upper.lower_bound(x));
        else
            lower.erase(lower.lower_bound(x));
        eval();
    }
};

MedianSet ms;

void dfs(int cur = 0, int par = -1, int depth = 0) {
    ms.insert(a[cur]);
    int mn = 1 << 30, mx = 0;
    for (int u : edges[cur]) {
        if (u == par) continue;
        dfs(u, cur, depth + 1);
        mn = min(mn, dp[u]), mx = max(mx, dp[u]);
    }
    if (mx == 0)
        dp[cur] = ms.median();
    else if (depth % 2 == 1)
        dp[cur] = mn;
    else
        dp[cur] = mx;

    ms.erase(a[cur]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs();

    cout << dp[0] << endl;
}
