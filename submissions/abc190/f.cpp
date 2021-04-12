#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
struct fenwick_tree {
    typedef ll T;
    T n;
    vector<T> bit;
    // 各要素の初期値は 0
    fenwick_tree(T num) : bit(num + 1, 0) { n = num; }
    // a_i += w
    void add(T i, T w) {
        for (T x = i; x <= n; x += x & -x) {
            bit[x] += w;
        }
    }
    // [1, i] の和を計算.
    T sum(T i) {
        T ret = 0;
        for (T x = i; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    T sum(T left, T right) {
        return sum(right) - sum(left);
    }
};
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i]++;
    }
    fenwick_tree f_tree(n);
    ll ans = 0;
    for (ll j = 0; j < n; j++) {
        ans += j - f_tree.sum(a[j]);
        f_tree.add(a[j], 1);
    }
    cout << ans << endl;
    for (ll i = 0; i < n - 1; i++) {
        ans -= a[i] - 1;
        ans += (n - a[i]);
        cout << ans << endl;
    }
}