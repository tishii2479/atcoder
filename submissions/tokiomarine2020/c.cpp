#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (k > 0) {
        vector<ll> rui(n + 1, 0);
        for (ll i = 0; i < n; i++) {
            rui[max(0LL, i - a[i])]++;
            rui[min(n, i + a[i] + 1)]--;
            // cout << i + a[i] + 1 << endl;
        }
        ll now = 0;
        ll mn = INF;
        for (int i = 0; i < n; i++) {
            now += rui[i];
            a[i] = now;
            mn = min(mn, now);
        }
        // cout << mn << n << endl;
        if (mn == n) {
            break;
        }
        k--;
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // cout << k << endl;
    }
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}