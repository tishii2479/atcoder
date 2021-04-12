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
    ll n;
    cin >> n;
    vector<pll> xy(n);
    for (ll i = 0; i < n; i++)
        cin >> xy[i].first >> xy[i].second;
    map<pll, ll> cnt;
    for (ll i = 0; i < n; i++)
        for (ll j = i + 1; j < n; j++) {
            ll dx = xy[i].first - xy[j].first;
            ll dy = xy[i].second - xy[j].second;
            if (dx < 0) {
                dx *= -1;
                dy *= -1;
            }
            if (dx == 0)
                dy = abs(dy);
            // dx > 0
            cnt[{dx, dy}]++;
        }
    ll mx = 0;
    for (auto m : cnt) {
        if (m.first.first == 0 and m.first.second == 0)
            continue;
        mx = max(mx, m.second);
    }
    cout << max(0LL, n - mx) << endl;
}