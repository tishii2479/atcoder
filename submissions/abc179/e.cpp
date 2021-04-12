#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
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
ll f(ll x, ll m) {
    return x % m;
}
int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> ord(m, -1);
    vector<ll> rireki, syu;
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        if (ord[x] != -1) {
            int p = ord[x];
            for (ll j = p; j < i; j++) {
                syu.push_back(rireki[j]);
            }
            break;
        }
        ord[x] = i;
        rireki.push_back(x);
        res += x;
        x = f(x * x, m);
    }
    n -= rireki.size();
    if (n == 0) {
        cout << res << endl;
        return 0;
    }
    vector<ll> sum(syu.size() + 1, 0);
    rep(i, syu.size()) sum[i + 1] = sum[i] + syu[i];
    ll q = n / syu.size();
    ll r = n % syu.size();
    res += sum[syu.size()] * q + sum[r];
    cout << res << endl;
}