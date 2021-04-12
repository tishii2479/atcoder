#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    ll diff = a - b;
    ll l = 0;
    ll r = (1 << 30);
    while (r - l > 0) {
        ll m = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            ll remain = h[i] - m * b;
            if (remain < 0)
                continue;
            if (remain % diff == 0)
                cnt += remain / diff;
            else
                cnt += remain / diff + 1;
        }
        if (cnt > m) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l << endl;
}