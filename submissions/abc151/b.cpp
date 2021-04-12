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
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    int sum = 0;
    int a;
    for (int i = 0; i < n - 1; i++) {
        cin >> a;
        sum += a;
    }
    int goal = m * n;
    int next = goal - sum;
    if (next <= k) {
        cout << max(0, next) << endl;
    } else {
        cout << -1 << endl;
    }
}