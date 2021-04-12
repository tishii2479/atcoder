#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll pow10[17];
ll g1(string x) {
    vector<ll> v;
    for (char c : x)
        v.push_back(c - '0');
    sort(v.begin(), v.end(), greater<ll>());
    string nw = "";
    for (ll e : v)
        nw += e + '0';
    return stoll(nw);
}
ll g2(string x) {
    vector<ll> v;
    for (char c : x)
        v.push_back(c - '0');
    sort(v.begin(), v.end());
    string nw = "";
    for (ll e : v)
        nw += e + '0';
    return stoll(nw);
}
ll f(ll x) {
    return g1(to_string(x)) - g2(to_string(x));
}
int main() {
    ll n, k;
    cin >> n >> k;
    ll now = n;
    pow10[0] = 1;
    for (int i = 0; i < 16; i++) {
        pow10[i + 1] = pow10[i] * 10;
    }
    for (int i = 0; i < k; i++) {
        now = f(now);
    }
    cout << now << endl;
}