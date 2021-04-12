#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    vector<pint> edges[n];
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        edges[l].push_back({r, d});
        edges[r].push_back({l, -d});
    }
    vector<int> x(n, 1 << 30);
    vector<bool> seen(n, false);
    seen[0] = false;
    for (int i = 0; i < n; i++) {
        if (seen[i])
            continue;
        x[i] = 0;
        queue<int> q;
        q.push(i);
        while (q.empty() == false) {
            int v = q.front();
            q.pop();
            seen[v] = true;
            for (pint e : edges[v]) {
                int u = e.first;
                int c = e.second;
                if (x[u] == (1 << 30)) {
                    x[u] = x[v] + c;
                    q.push(u);
                } else {
                    if (x[u] != x[v] + c) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
}