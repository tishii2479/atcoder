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
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    vector<ll> c(n);
    for (ll i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    ll ans = -INF;
    for (ll s = 0; s < n; s++) {
        ll i = s;
        ll loop = 0;
        ll loop_sum = 0;
        while (true) {
            loop++;
            loop_sum += c[i];
            i = p[i];
            if (i == s)
                break;
        }
        ll path = 0;
        ll cnt = 0;
        while (true) {
            cnt++;
            path += c[i];
            if (cnt > k)
                break;
            int num = (k - cnt) / loop;
            ll score = path + max(0LL, loop_sum) * num;
            ans = max(ans, score);
            i = p[i];
            if (s == i)
                break;
        }
    }
    cout << ans << endl;
}