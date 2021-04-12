#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
pint unit[9] = {
    {0, 0},
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1},
    {1, 1},
    {-1, 1},
    {-1, -1},
    {1, -1},
};
int main() {
    ll w, h, n;
    cin >> h >> w >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i], a[i]--, b[i]--;
    ll total = (h - 2) * (w - 2);
    map<pint, ll> mp;
    for (int i = 0; i < n; i++) {
        ll y = a[i], x = b[i];
        for (int j = 0; j < 9; j++) {
            ll cy = y + unit[j].first, cx = x + unit[j].second;
            if (cx < 1 or cy < 1 or cx > w - 2 or cy > h - 2)
                continue;
            mp[{cx, cy}]++;
        }
    }
    vector<ll> cnt(10, 0);
    ll sum = 0;
    for (auto m : mp) {
        // cout << m.first.first << " " << m.first.second << " " << m.second << endl;
        cnt[m.second]++;
        sum++;
    }
    cnt[0] = total - sum;
    for (int i = 0; i < 10; i++)
        cout << cnt[i] << endl;
}