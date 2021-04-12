#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll n, q;
string s;
ll solve() {
    ll k;
    cin >> k;
    ll ans = 0;
    ll cur = 0;
    ll dcnt = 0;
    vector<ll> dp(n, 0);
    ll cnt = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if (i + k < n)
            cnt -= (s[i + k] == 'M');
        if (s[i] == 'M')
            cnt++;
        else if (s[i] == 'D')
            dp[i] = cnt;
    }
    for (ll i = 0; i < n; i++) {
        if (i - k >= 0) {
            if (s[i - k] == 'D') {
                dcnt--;
                cur -= dp[i - k];
            }
        }
        if (s[i] == 'D') {
            dcnt++;
        } else if (s[i] == 'M') {
            cur += dcnt;
        } else if (s[i] == 'C') {
            ans += cur;
        }
    }
    return ans;
}
int main() {
    cin >> n >> s >> q;
    vector<ll> res;
    while (q--)
        res.push_back(solve());
    for (ll r : res)
        cout << r << endl;
}