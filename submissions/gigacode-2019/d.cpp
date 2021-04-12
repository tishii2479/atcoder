#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
int main() {
    ll h, w, k, v;
    cin >> h >> w >> k >> v;
    vector<vector<ll>> a(h + 1, vector<ll>(w + 1));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[i + 1][j + 1];
    for (int i = 0; i <= h; i++)
        for (int j = 0; j < w; j++)
            a[i][j + 1] += a[i][j];
    for (int j = 0; j <= w; j++)
        for (int i = 0; i < h; i++)
            a[i + 1][j] += a[i][j];
    ll ans = 0;
    for (int lw = 0; lw < w; lw++)
        for (int rw = lw + 1; rw <= w; rw++)
            for (int lh = 0; lh < h; lh++)
                for (int rh = lh + 1; rh <= h; rh++) {
                    ll land = a[rh][rw] - a[lh][rw] - a[rh][lw] + a[lh][lw];
                    ll s = (rw - lw) * (rh - lh);
                    ll cost = s * k;
                    if (land + cost <= v) {
                        ans = max(ans, s);
                    }
                }
    cout << ans << endl;
}