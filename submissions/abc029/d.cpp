#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    ll ans = 0;
    ll cur = 1;
    for (int i = 0; i < s.length(); i++) {
        ll a = n / (cur * 10);
        ll b = n % cur;
        if (s[i] == '0') {
            ans += a * cur;
        } else if (s[i] == '1') {
            ans += a * cur + (b + 1);
        } else {
            ans += (a + 1) * cur;
        }
        cur *= 10;
    }
    cout << ans << endl;
}