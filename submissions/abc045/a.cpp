#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s;
    cin >> s;
    ll ans = 0;
    int n = s.length() - 1;
    for (int bits = 0; bits < (1 << n); bits++) {
        ll now = 0;
        int l = 0;
        string ns = "";
        for (int i = 0; i < n; i++) {
            ns += s[i];
            if (bits & (1 << i)) {
                l = i + 1;
                now += stoll(ns);
                ns = "";
            }
        }
        ns += s[n];
        now += stoll(ns);
        ans += now;
    }
    cout << ans << endl;
}