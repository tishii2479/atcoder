#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p;
    vector<ll> q;
    vector<ll> v;
    ll n;
    for (int i = 0; i < a; i++) {
        cin >> n;
        p.push_back(n);
    }
    for (int i = 0; i < b; i++) {
        cin >> n;
        q.push_back(n);
    }
    for (int i = 0; i < c; i++) {
        cin >> n;
        v.push_back(n);
    }
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    for (int i = 0; i < x; i++) {
        v.push_back(p[i]);
    }
    for (int i = 0; i < y; i++) {
        v.push_back(q[i]);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll ans = 0;
    for (int i = 0; i < x + y; i++) {
        // cout << v[i] << endl;
        ans += v[i];
    }
    cout << ans << endl;
}