#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    ll t;
    cin >> n >> t;
    ll a;
    vector<ll> a1;
    vector<ll> a2;
    for (int i = 0; i < n / 2; i++) {
        cin >> a;
        a1.push_back(a);
    }
    for (int i = n / 2; i < n; i++) {
        cin >> a;
        a2.push_back(a);
    }
    ll ans = 0;
    vector<ll> all1;
    vector<ll> all2;
    for (int bits = 0; bits < (1 << (n / 2)); bits++) {
        ll v = 0;
        for (int i = 0; i < n / 2; i++) {
            if (bits & (1 << i))
                v += a1[i];
        }
        all1.push_back(v);
    }
    for (int bits = 0; bits < (1 << (n - n / 2)); bits++) {
        ll v = 0;
        for (int i = 0; i < (n - n / 2); i++) {
            if (bits & (1 << i)) {
                v += a2[i];
            }
        }
        all2.push_back(v);
    }
    sort(all2.begin(), all2.end(), greater<ll>());
    for (int i = 0; i < all1.size(); i++) {
        ll v = all1[i];
        if (v > t)
            continue;
        v += *(lower_bound(all2.begin(), all2.end(), t - v, greater<ll>()));
        ans = max(v, ans);
    }
    cout << ans << endl;
}