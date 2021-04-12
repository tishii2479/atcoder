#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll a[2];
    ll b[2];
    ll t[2];
    for (int i = 0; i < 2; i++)
        cin >> t[i];
    for (int i = 0; i < 2; i++)
        cin >> a[i];
    for (int i = 0; i < 2; i++)
        cin >> b[i];
    ll s[2] = {
        a[0] * t[0] + a[1] * t[1],
        b[0] * t[0] + b[1] * t[1]};
    if (s[0] == s[1]) {
        cout << "infinity" << endl;
        return 0;
    }
    if (s[0] < s[1]) {
        swap(s[0], s[1]);
        swap(a, b);
    }
    ll ss = (b[0] * t[0] - a[0] * t[0]);
    ll d = (s[0] - s[1]);
    // cout << ss << " " << d << endl;
    if (ss < 0) {
        cout << 0 << endl;
        return 0;
    }
    if (ss % d == 0) {
        cout << ss / d * 2 << endl;
    } else {
        cout << ss / d * 2 + 1 << endl;
    }
}