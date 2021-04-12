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
    int n = s.length();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            ans += (n - i - 1) * 1 + i * 2;
        } else {
            ans += (n - i - 1) * 2 + i * 1;
        }
    }
    cout << ans << endl;
}