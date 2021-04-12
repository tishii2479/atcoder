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
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> z(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    ll ans = -INF;
    for (int j = 0; j < 1 << 3; j++) {
        vector<pll> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {0, i};
            if (j & (1 << 0))
                vec[i].first += x[i];
            else
                vec[i].first -= x[i];
            if (j & (1 << 1))
                vec[i].first += y[i];
            else
                vec[i].first -= y[i];
            if (j & (1 << 2))
                vec[i].first += z[i];
            else
                vec[i].first -= z[i];
        }
        sort(vec.begin(), vec.end(), greater<pll>());
        ll xsum = 0;
        ll ysum = 0;
        ll zsum = 0;
        for (int i = 0; i < m; i++) {
            int ind = vec[i].second;
            xsum += x[ind];
            ysum += y[ind];
            zsum += z[ind];
        }
        ans = max(abs(xsum) + abs(ysum) + abs(zsum), ans);
    }
    cout << ans << endl;
}