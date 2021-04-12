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
    vector<pll> p(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        p[i] = {a, i};
    }
    sort(p.begin(), p.end(), greater<pll>());
    multiset<int> st = {-1, -1, n, n};
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int ind = p[i].second;
        st.insert(ind);
        auto it = st.lower_bound(ind);
        auto l1 = prev(it);
        auto l2 = prev(l1);
        auto r1 = next(it);
        auto r2 = next(r1);
        int num = (*r2 - *r1) * (*it - *l1) + (*r1 - *it) * (*l1 - *l2);
        ans += num * p[i].first;
    }
    cout << ans << endl;
}