#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
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
vector<int> edges[110000];
int memo[110000];
int found[110000];
int dp(int v) {
    if (found[v])
        return memo[v];
    int ans = 0;
    for (int to : edges[v]) {
        ans = max(ans, dp(to) + 1);
    }
    memo[v] = ans;
    found[v] = true;
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp(i));
    }
    cout << ans << endl;
}