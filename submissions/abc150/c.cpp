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
int kaijo(int n) {
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> v;
    rep(i, n) {
        v.push_back(i + 1);
        cin >> p[i];
    }
    rep(i, n) {
        cin >> q[i];
    }
    int a, b;
    int cnt = 1;
    sort(v.begin(), v.end());
    do {
        bool pf = true;
        bool qf = true;
        rep(i, n) {
            if (p[i] != v[i])
                pf = false;
            if (q[i] != v[i])
                qf = false;
        }
        if (pf)
            a = cnt;
        if (qf)
            b = cnt;
        cnt++;
    } while (next_permutation(v.begin(), v.end()));
    cout << abs(a - b) << endl;
}