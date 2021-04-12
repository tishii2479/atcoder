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
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<vector<ll>> dist(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    bool ok = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != dist[i][j])
                ok = false;
    if (ok == false) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int k = 0; k < n; k++) {
                if (j == k or i == k)
                    continue;
                if (dist[i][j] >= dist[i][k] + dist[k][j])
                    flag = false;
            }
            if (flag)
                ans += dist[i][j];
        }
    cout << ans / 2 << endl;
}