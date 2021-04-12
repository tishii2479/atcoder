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
    string s;
    cin >> s;
    ll n = s.length();
    ll ans = 0;
    char now;
    ll last = -1;
    ll cnt = 0;
    for (ll i = 1; i < n - 1; i++) {
        if (s[i] == s[i - 1] and s[i] != s[i + 1]) {
            if (last > 0) {
                if (s[i] == now)
                    ans += i - last - 1 - cnt;
                else
                    ans += max(0LL, n - last - 1 - cnt);
            }
            now = s[i];
            last = i;
            cnt = 0;
        } else if (now == s[i])
            cnt++;
    }
    if (last > 0) {
        if (s[n - 1] == now)
            ans += n - last - 2 - cnt;
        else
            ans += max(0LL, n - last - 1 - cnt);
    }
    cout << ans << endl;
}