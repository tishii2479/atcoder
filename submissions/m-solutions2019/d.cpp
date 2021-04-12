#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<int> edges[110000];
    vector<int> c(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c.begin(), c.end(), greater<int>());
    vector<bool> seen(n, false);
    vector<int> res(n);
    queue<int> q;
    q.push(0);
    int cnt = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res[v] = cnt++;
        seen[v] = true;
        for (int u : edges[v]) {
            if (seen[u] == false)
                q.push(u);
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += c[i];
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << c[res[i]] << " ";
    cout << endl;
}