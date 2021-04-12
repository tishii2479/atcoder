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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> sums(n + 1, 0);
    map<ll, vector<int>> mp;
    mp[0] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sums[i + 1] = (sums[i] + a[i]) % k;
        mp[((sums[i + 1] - i - 1) % k + k) % k].push_back(i + 1);
    }
    ll ans = 0;
    for (auto m : mp) {
        vector<int> v = m.second;
        int cnt = sums[v[0]];
        for (int i = 0; i < v.size(); i++) {
            int now = v[i];
            int right = lower_bound(v.begin(), v.end(), now + k) - v.begin();
            ans += right - i - 1;
        }
    }
    cout << ans << endl;
}