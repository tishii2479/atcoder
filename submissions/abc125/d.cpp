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
int main() {
    int n;
    cin >> n;
    ll a;
    int odd = 0;
    ll sum = 0;
    ll min = INF;
    for (int i = 0; i < n; i++) {
        cin >> a;
        chmin(min, abs(a));
        if (a < 0)
            odd++;
        sum += abs(a);
    }
    if (odd % 2 == 1) {
        cout << sum - min * 2 << endl;
    } else {
        cout << sum << endl;
    }
}