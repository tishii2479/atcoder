#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<int> edges[210000];
vector<int> counter(210000, 0);
vector<int> res(210000, 0);
vector<bool> seen(210000, false);
ll now = 0;
void dfs(int v) {
    now += counter[v];
    res[v] = now;
    seen[v] = true;
    for (int u : edges[v]) {
        if (seen[u])
            continue;
        dfs(u);
    }
    now -= counter[v];
}
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        counter[p] += x;
    }
    dfs(0);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
}