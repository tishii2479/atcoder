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
    vector<int> pos;
    vector<int> neg;
    int a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a >= 0) {
            pos.push_back(a);
        } else {
            neg.push_back(a);
        }
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    if (pos.empty()) pos.push_back(neg.back()), neg.pop_back();
    if (neg.empty()) neg.push_back(pos.back()), pos.pop_back();
    vector<pint> res;
    int cur = neg[0];
    for (int i = 0; i + 1 < pos.size(); i++) {
        res.push_back({cur, pos[i]});
        cur -= pos[i];
    }
    res.push_back({pos.back(), cur});
    cur = pos.back() - cur;
    for (int i = 1; i < neg.size(); i++) {
        res.push_back({cur, neg[i]});
        cur -= neg[i];
    }
    cout << cur << endl;
    for (pint p : res) {
        cout << p.first << " " << p.second << endl;
    }
}