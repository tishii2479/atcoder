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
    int n, m;
    cin >> n >> m;
    vector<int> point(110000, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        point[a]++;
        point[b]++;
    }
    for (int i = 0; i < n; i++) {
        if (point[i] % 2 != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}