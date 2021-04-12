#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(ll x, ll y) {
    if (x >= y)
        return x - y;
    ll ans = y - x;
    queue<pair<ll, int>> q;
    unordered_map<ll, int> mp;
    q.push({y, 0});
    while (q.size()) {
        auto p = q.front();
        q.pop();
        ll cur = p.first;
        ll cnt = p.second;
        ans = min(ans, cnt + abs(x - cur));
        if (cur <= x)
            continue;
        if (mp[cur] != 0)
            continue;
        mp[cur] = cnt;
        if (cur % 2 == 0) {
            q.push({cur / 2, cnt + 1});
        } else {
            q.push({cur + 1, cnt + 1});
            q.push({cur - 1, cnt + 1});
        }
    }
    return ans;
}
int main() {
    ll x, y;
    cin >> x >> y;
    cout << solve(x, y) << endl;
}
// x > y
// -> x - y
// x <= y
// -> + or - -> x -> + or -
// 3 20
// 3 4 5 10 20
// 4 30
// 4 5 6 7 14 28 29 30
// 4 5 6 7  8 16 32 31 30
// 5 16
// 5 6 7 14 15 16
// 5 4 8 16
// 5 6 7  8 16