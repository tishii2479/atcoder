#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a + 2);
    vector<ll> t(b + 2);
    for (int i = 0; i < a; i++)
        cin >> s[i];
    for (int i = 0; i < b; i++)
        cin >> t[i];
    s[a] = -INF;
    t[b] = -INF;
    s[a + 1] = INF;
    t[b + 1] = INF;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    vector<ll> res;
    while (q--) {
        ll x;
        cin >> x;
        ll sb = abs(*lower_bound(s.begin(), s.end(), x) - x);
        ll ss = abs(*(lower_bound(s.begin(), s.end(), x) - 1) - x);
        ll tb = abs(*lower_bound(t.begin(), t.end(), x) - x);
        ll ts = abs(*(lower_bound(t.begin(), t.end(), x) - 1) - x);
        // cout << sb << " " << ss << " " << tb << " " << ts << endl;
        res.push_back(min({max(sb, tb), max(ss, ts), min(ss * 2 + tb, ss + tb * 2), min(ts * 2 + sb, ts + sb * 2)}));
    }
    for (ll r : res) {
        cout << r << endl;
    }
}