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
int n, m;
int a[210000];
bool vis[110000];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        a[i] = n - i;
    for (int i = 0; i < m; i++)
        cin >> a[i + n];
    for (int i = n + m - 1; i >= 0; i--) {
        if (vis[a[i]] == false) {
            cout << a[i] << endl;
            vis[a[i]] = true;
        }
    }
}