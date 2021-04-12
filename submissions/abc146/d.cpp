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
int n;
vector<int> res(110000, -1);
vector<pint> edges[110000];
void dfs(int v, int p, int c) {
    int color = 1;
    if (color == c)
        color++;
    for (pint e : edges[v]) {
        if (e.first == p)
            continue;
        res[e.second] = color;
        dfs(e.first, v, color);
        color++;
        if (color == c)
            color++;
    }
}
int main() {
    cin >> n;
    vector<int> cnt(n, 0);
    int maxv;
    int k = -1;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back({b, i});
        edges[b].push_back({a, i});
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] > k) {
            maxv = i;
            k = cnt[i];
        }
    }
    dfs(0, -1, -1);
    cout << k << endl;
    for (int i = 0; i < n - 1; i++)
        cout << res[i] << endl;
}