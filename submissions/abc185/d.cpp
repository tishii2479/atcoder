#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
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
const int MOD = 1000000007;
// const int MOD = 998244353;
ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> whites;
    ll prev = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        ll w = a[i] - prev - 1;
        prev = a[i];
        if (w == 0)
            continue;
        whites.push_back(w);
    }
    ll w = n - prev;
    if (w != 0)
        whites.push_back(w);
    if (whites.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (m == 0) {
        cout << 1 << endl;
        return 0;
    }
    ll gc = whites[0];
    for (int i = 0; i < whites.size(); i++) {
        gc = min(gc, whites[i]);
    }
    ll ans = 0;
    for (int i = 0; i < whites.size(); i++) {
        if (whites[i] % gc == 0) {
            ans += whites[i] / gc;
        } else {
            ans += whites[i] / gc + 1;
        }
    }
    cout << ans << endl;
}