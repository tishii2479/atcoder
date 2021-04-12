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
    vector<int> c(n);
    vector<int> s(n);
    vector<int> f(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i] >> s[i] >> f[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int time = s[i];
        for (int j = i; j < n - 1; j++) {
            if (time % f[j] == 0) {
                time = max(s[j], (time / f[j]) * f[j]);
            } else {
                time = max(s[j], (time / f[j] + 1) * f[j]);
            }
            time += c[j];
        }
        cout << time << endl;
    }
    cout << 0 << endl;
}