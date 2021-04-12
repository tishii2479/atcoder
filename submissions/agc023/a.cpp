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
    map<ll, ll> cnt;
    ll cur = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        cnt[cur]++;
    }
    ll ans = 0;
    for (auto m : cnt) {
        ans += (m.second - 1) * m.second / 2;
    }
    cout << ans << endl;
}