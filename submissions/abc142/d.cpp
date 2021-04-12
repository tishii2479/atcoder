#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const ll INF = 1LL << 60;
const int inf = 1 << 29;
ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
int main() {
    ll a, b;
    cin >> a >> b;
    ll gc = gcd(a, b);
    int cnt = 0;
    vector<ll> div;
    if (gc == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (ll i = 1; i * i <= gc; i++) {
        if (gc % i == 0) {
            div.push_back(i);
            if (gc / i != i)
                div.push_back(gc / i);
        }
    }
    sort(div.begin(), div.end());
    vector<bool> ok(div.size(), true);
    for (int i = 1; i < div.size(); i++) {
        for (int j = 1; j < div.size(); j++) {
            if (i == j)
                continue;
            if (div[j] % div[i] == 0)
                ok[j] = false;
        }
    }
    for (int i = 0; i < div.size(); i++) {
        if (ok[i])
            cnt++;
    }
    cout << cnt << endl;
}