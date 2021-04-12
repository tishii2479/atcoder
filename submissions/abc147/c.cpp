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
    vector<int> a(n);
    vector<pint> xy[20];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < a[i]; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            xy[i].push_back({x, y});
        }
    }
    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        vector<bool> isHonest(n);
        bool ok = true;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                // honest
                isHonest[j] = true;
                cnt++;
            } else {
                // unkind
                isHonest[j] = false;
            }
        }
        for (int j = 0; j < n; j++) {
            int l = a[j];
            for (int k = 0; k < l; k++) {
                int x = xy[j][k].first;
                int y = xy[j][k].second;
                if (isHonest[j] == false)
                    continue;
                if (y == 1) {
                    if (isHonest[x] == false) {
                        ok = false;
                        break;
                    }
                }
                if (y == 0) {
                    if (isHonest[x]) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) {
            res = max(res, cnt);
        }
    }
    cout << res << endl;
}