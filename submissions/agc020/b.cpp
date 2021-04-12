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
    int k;
    cin >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    ll mn = 2;
    ll mx = 2;
    for (int i = k - 1; i >= 0; i--) {
        ll na = a[i];
        mx = mx / a[i] * a[i];
        mn = (mn + a[i] - 1) / a[i] * a[i];
        if (mx < mn) {
            cout << -1 << endl;
            return 0;
        }
        mx += a[i] - 1;
    }
    cout << mn << " " << mx << endl;
}