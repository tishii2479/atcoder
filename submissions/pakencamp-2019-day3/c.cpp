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
    ll ans = 0;
    ll a[110][110];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            ll sum = 0;
            for (int k = 0; k < n; k++) {
                sum += max(a[k][i], a[k][j]);
            }
            ans = max(sum, ans);
        }
    }
    cout << ans << endl;
}