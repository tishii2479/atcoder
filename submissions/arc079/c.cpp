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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    bool ok = false;
    while (ok == false) {
        vector<ll> cnts(n, 0);
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            cnts[i] = a[i] / n;
            cnt += cnts[i];
            a[i] -= cnts[i] + cnts[i] * n;
        }
        ok = true;
        for (int i = 0; i < n; i++) {
            a[i] += cnt;
            if (a[i] >= n)
                ok = false;
        }
        ans += cnt;
    }
    cout << ans << endl;
}