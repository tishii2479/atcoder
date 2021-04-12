#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<pll> v(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());
    priority_queue<ll> pq;
    int now = 0;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        while (now < n and v[now].first <= i) {
            pq.push(v[now].second);
            now++;
        }
        if (pq.size() > 0) {
            ll p = pq.top();
            pq.pop();
            ans += p;
        }
    }
    cout << ans << endl;
}