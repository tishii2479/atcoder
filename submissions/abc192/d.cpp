#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 62;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll m;
ll n;
vector<ll> num;
bool ok(ll x) {
    ll now = 0;
    ll cur = 1;
    for (int i = 0; i < n; i++) {
        if (m - now < cur * num[i])
            return false;
        now += cur * num[i];
        if ((m + x - 1) / x < cur and i < n - 1)
            return false;
        cur *= x;
    }
    return true;
}
int main() {
    string x;
    cin >> x >> m;
    int d = 0;
    n = x.length();
    if (n == 1) {
        if (x[0] - '0' > m)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < x.length(); i++) {
        d = max(d, x[i] - '0');
        num.push_back(x[i] - '0');
    }
    reverse(num.begin(), num.end());
    ll r = INF;
    ll l = 0;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        if (ok(m))
            l = m;
        else
            r = m;
    }
    cout << max(0LL, l - d) << endl;
}