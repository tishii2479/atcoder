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
    ll n, p;
    string s;
    cin >> n >> p >> s;
    ll pow10[210000];
    pow10[0] = 1;
    for (int i = 1; i < 210000; i++) {
        pow10[i] = pow10[i - 1] * 10;
        pow10[i] %= p;
    }
    if (p == 2 or p == 5) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int a = s[i] - '0';
            if (a % p == 0)
                ans += i + 1;
        }
        cout << ans << endl;
        return 0;
    }
    map<int, ll> mp;
    ll now = 0;
    mp[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        now += (s[i] - '0') * pow10[n - i - 1];
        now %= p;
        mp[now]++;
    }
    ll ans = 0;
    for (auto m : mp) {
        ll cnt = m.second;
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
}