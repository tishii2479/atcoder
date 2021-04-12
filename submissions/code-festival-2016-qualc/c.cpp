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
    ll n;
    cin >> n;
    vector<ll> a(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 1;
    if (a[0] != t[n - 1])
        ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (t[i] == t[i - 1] and a[i] == a[i + 1]) {
            ans *= min(t[i], a[i]);
            ans %= MOD;
        } else if (t[i] == t[i - 1] and a[i] > a[i + 1] and t[i] < a[i])
            ans = 0;
        else if (t[i] > t[i - 1] and a[i] == a[i + 1] and a[i] < t[i])
            ans = 0;
        else if (t[i] > t[i - 1] and a[i] > a[i + 1] and a[i] != t[i])
            ans = 0;
    }
    cout << ans << endl;
}