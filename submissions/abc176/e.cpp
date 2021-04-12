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
int main() {
    ll h, w;
    ll m;
    cin >> h >> w >> m;
    vector<ll> ySum(h, 0);
    vector<ll> xSum(w, 0);
    set<pint> bomb;
    int y, x;
    rep(i, m) {
        cin >> y >> x;
        ySum[y - 1]++;
        xSum[x - 1]++;
        bomb.insert({y - 1, x - 1});
    }
    ll yMax = 0;
    ll xMax = 0;
    vector<int> yMaxInd;
    vector<int> xMaxInd;
    rep(i, h) {
        if (ySum[i] > yMax) {
            yMaxInd.clear();
            yMaxInd.push_back(i);
            yMax = max(yMax, ySum[i]);
        } else if (ySum[i] == yMax) {
            yMaxInd.push_back(i);
        }
    }
    rep(i, w) {
        if (xSum[i] > xMax) {
            xMaxInd.clear();
            xMaxInd.push_back(i);
            xMax = max(xMax, xSum[i]);
        } else if (xSum[i] == xMax) {
            xMaxInd.push_back(i);
        }
    }
    rep(i, yMaxInd.size()) {
        rep(j, xMaxInd.size()) {
            if (bomb.find({yMaxInd[i], xMaxInd[j]}) == bomb.end()) {
                cout << yMax + xMax << endl;
                return 0;
            }
        }
    }
    cout << yMax + xMax - 1 << endl;
}