#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }
int main() {
    ll n;
    cin >> n;
    vector<int> place(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        place[a] = i;
    }
    ll ans = 0;
    set<ll> used = {0, n + 1};
    for (int i = 1; i <= n; i++) {
        int l, r;
        auto itr = used.lower_bound(place[i]);
        r = *itr;
        l = *(--itr);
        ans += (ll)i * (place[i] - l) * (r - place[i]);
        used.insert(place[i]);
    }
    cout << ans << endl;
}