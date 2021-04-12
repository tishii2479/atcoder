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
bool used[20];
ll f(ll n) {
    ll res = 1;
    for (int i = 1; i <= 11; i++) {
        res *= n - i + 1;
        for (int i = 1; i <= 11; i++) {
            if (res % i == 0 and used[i] == false) {
                used[i] = true;
                res /= i;
            }
        }
    }
    return res;
}
int main() {
    ll l;
    cin >> l;
    cout << f(l - 1) << endl;
}