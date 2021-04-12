#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const ll INF = 1LL << 60;
const int inf = 1 << 29;
vector<pll> edges[110000];
int color[110000];
int found[110000];
void bfs(int k) {
    queue<int> queue;
    queue.push(k);
    color[k] = 0;
    while (queue.empty() == false) {
        int v = queue.front();
        queue.pop();
        found[v] = true;
        for (pll e : edges[v]) {
            if (found[e.first])
                continue;
            found[e.first] = true;
            if (e.second % 2 == 1) {
                color[e.first] = 1 - color[v];
            } else {
                color[e.first] = color[v];
            }
            queue.push(e.first);
        }
    }
}
int main() {
    int n;
    cin >> n;
    ll u, v;
    ll w;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    bfs(1);
    for (int i = 1; i <= n; i++) {
        cout << color[i] << endl;
    }
}