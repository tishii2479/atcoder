#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll modfac(ll x) {
    return (x * (x - 1) / 2) % MOD;
}
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> cnt(n, 0);
    vector<ll> sum(n, 0);
    k %= MOD;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j] and j > i)
                cnt[i]++;
            if (a[i] > a[j])
                sum[i]++;
        }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ((k * cnt[i]) % MOD + modfac(k) * (sum[i]) % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}