#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        mp[a]++;
        mp[a + b]--;
    }

    vector<ll> ans(n + 1, 0);

    ll cur = 0;
    ll prev = 0;
    for (auto [day, delta] : mp) {
        ans[cur] += day - prev;
        cur += delta;
        prev = day;
    }

    for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}
