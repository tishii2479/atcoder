#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<set<pair<ll, ll>>> dp(n + 1);
    dp[1].insert({a[0], b[0]});
    for (int i = 1; i < n; i++) {
        for (auto p : dp[i]) {
            dp[i + 1].insert({gcd(p.first, a[i]), gcd(p.second, b[i])});
            dp[i + 1].insert({gcd(p.first, b[i]), gcd(p.second, a[i])});
        }
    }

    ll ans = 0;
    for (auto p : dp[n]) {
        ans = max(ans, lcm(p.first, p.second));
    }
    cout << ans << endl;
}
