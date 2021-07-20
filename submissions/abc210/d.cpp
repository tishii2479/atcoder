#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll h, w, c;
    cin >> h >> w >> c;
    vector<vector<ll>> a(h, vector<ll>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> a[i][j];
    }

    const ll INF = 1LL << 60;
    vector<vector<ll>> cum(h + 1, vector<ll>(w + 1, INF));

    ll ans = INF;

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                ll val = c * (i + j);
                val += a[i][j] + min(cum[i + 1][j], cum[i][j + 1]);

                cum[i + 1][j + 1] = min({cum[i + 1][j], cum[i][j + 1], a[i][j] - c * (i + j)});

                ans = min(ans, val);
            }
        }

        vector<vector<ll>> t(h, vector<ll>(w));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                t[i][j] = a[i][w - j - 1];
            }
        }
        swap(a, t);
    }
    cout << ans << endl;
}
