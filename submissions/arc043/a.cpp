#include <bits/stdc++.h>
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
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll max = 0, min = INF;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll s;
        cin >> s;
        sum += s;
        chmax(max, s);
        chmin(min, s);
    }
    if (min == max) {
        cout << -1 << endl;
        return 0;
    }
    double p = (double)b / (double)(max - min);
    double q = a - p * (double)sum / n;
    printf("%.15lf %.15lf\n", p, q);
}