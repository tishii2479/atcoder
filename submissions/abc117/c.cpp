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
    int n, m;
    cin >> n >> m;
    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> x(m);
    for (int i = 0; i < m; i++)
        cin >> x[i];
    sort(x.begin(), x.end());
    int ans = x[m - 1] - x[0];
    vector<int> diff;
    for (int i = 0; i < m - 1; i++) {
        diff.push_back(x[i + 1] - x[i]);
    }
    sort(diff.begin(), diff.end(), greater<int>());
    for (int i = 0; i < n - 1; i++) {
        ans -= diff[i];
    }
    cout << max(0, ans) << endl;
}