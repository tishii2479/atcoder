#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
    using mint = modint1000000007;
    using ll = long long;
    ll n, k;
    cin >> n >> k;

    ll sqr = floor(sqrt(n));
    map<ll, mint> mp;

    for (ll i = 1; i <= sqr; i++) {
        ll top = n / i, bottom = n / (i + 1) + 1;
        ll cnt = top - bottom + 1;
        if (cnt <= 0) continue;
        mp[i] = cnt;
    }

    for (ll i = 1; mp[n / i] == 0; i++) mp[n / i]++;

    vector<pair<ll, mint>> v;
    for (auto m : mp) v.push_back(m);

    int sz = v.size();
    vector<pair<ll, mint>> dp(sz);
    dp[0] = {n, 1};

    for (int i = 0; i < k; i++) {
        vector<mint> sums(sz);
        for (int i = 0; i < sz; i++) sums[i] = dp[sz - i - 1].second;
        for (int i = 0; i + 1 < sz; i++) sums[i + 1] += sums[i];

        for (int i = 0; i < sz; i++) {
            dp[i] = {v[i].first, sums[i] * v[i].second};
        }
    }

    mint ans = 0;
    for (int i = 0; i < sz; i++) ans += dp[i].first * dp[i].second;
    cout << ans.val() << endl;
}
