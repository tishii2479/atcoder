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
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}
int main() {
    map<int, int> sum1;
    map<int, int> sum2;
    int n;
    cin >> n;
    rep(i, n) {
        int v;
        cin >> v;
        if (i % 2 == 0) {
            sum1[v]++;
        } else {
            sum2[v]++;
        }
    }
    vector<pint> v1;
    vector<pint> v2;
    each(i, sum1) {
        v1.push_back(pint(i.second, i.first));
    }
    each(i, sum2) {
        v2.push_back(pint(i.second, i.first));
    }
    sort(v1.begin(), v1.end(), greater<pint>());
    sort(v2.begin(), v2.end(), greater<pint>());
    if (v1[0].second != v2[0].second) {
        cout << n - v1[0].first - v2[0].first << endl;
    } else {
        cout << n - max(v1[1].first + v2[0].first, v1[0].first + v2[1].first) << endl;
    }
}