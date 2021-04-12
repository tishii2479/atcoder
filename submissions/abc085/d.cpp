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
    ll n, h;
    cin >> n >> h;
    vector<pll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        ll _a, _b;
        cin >> _a >> _b;
        a[i] = {_a, i};
        b[i] = {_b, i};
    }
    sort(b.begin(), b.end(), greater<pll>());
    sort(a.begin(), a.end(), greater<pll>());
    ll cnt = 0;
    int i = 0;
    while (h > 0 and i < n and b[i].first > a[0].first) {
        h -= b[i].first;
        i++;
        cnt++;
    }
    if (h > 0)
        cnt += (h + a[0].first - 1) / a[0].first;
    cout << cnt << endl;
}