#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int MOD = 1000000007;
const int inf = 1 << 30;
// const int MOD = 998244353;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> sums;
    ll cur = 0;
    for (ll i = 0; i < n; i++) {
        cur = 0;
        for (ll j = i; j < n; j++) {
            cur += a[j];
            sums.push_back(cur);
        }
    }
    ll ans = 0;
    ll now = 59;
    sort(sums.begin(), sums.end(), greater<ll>());
    while (true) {
        vector<ll> cnt(60, 0);
        for (ll i = 0; i < sums.size(); i++) {
            ll s = sums[i];
            for (ll j = 0; j < 60; j++)
                if (s & (1LL << j))
                    cnt[j]++;
        }
        ll use = -1;
        for (ll i = now; i >= 0; i--) {
            if (cnt[i] >= k) {
                use = i;
                break;
            }
        }
        if (use == -1)
            break;
        ans |= (1LL << use);
        now = use - 1;
        vector<ll> cand;
        for (ll i = 0; i < sums.size(); i++)
            if (sums[i] & (1LL << use))
                cand.push_back(sums[i]);
        sums = cand;
    }
    cout << ans << endl;
}