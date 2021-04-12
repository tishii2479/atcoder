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
    ll n, c;
    cin >> n >> c;
    vector<ll> x(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> v[i];
    vector<ll> right_rev(n + 1, 0);
    vector<ll> right_mx(n + 1, 0);
    vector<ll> left_rev(n + 1, 0);
    vector<ll> left_mx(n + 1, 0);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += v[i];
        cur -= x[i];
        if (i > 0)
            cur += x[i - 1];
        right_mx[i + 1] = max(right_mx[i], cur);
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur += v[i];
        cur -= (c - x[i]);
        if (i < n - 1)
            cur += (c - x[i + 1]);
        left_mx[i] = max(left_mx[i + 1], cur);
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        cur += v[i];
        cur -= x[i] * 2;
        if (i > 0)
            cur += x[i - 1] * 2;
        right_rev[i + 1] = max(right_rev[i], cur);
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur += v[i];
        cur -= (c - x[i]) * 2;
        if (i < n - 1)
            cur += (c - x[i + 1]) * 2;
        left_rev[i] = max(left_rev[i + 1], cur);
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(right_mx[i] + left_rev[i], ans);
        ans = max(right_rev[i] + left_mx[i], ans);
    }
    cout << ans << endl;
}