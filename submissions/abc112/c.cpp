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
    vector<int> vx(n);
    vector<int> vy(n);
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> vx[i] >> vy[i] >> h[i];
    }
    for (int y = 0; y <= 100; y++) {
        for (int x = 0; x <= 100; x++) {
            bool flag = true;
            ll H = -1;
            vector<int> left;
            for (int i = 0; i < n; i++) {
                if (H == -1) {
                    if (h[i] != 0 and abs(x - vx[i]) + abs(y - vy[i]) + h[i] > 0) {
                        H = abs(x - vx[i]) + abs(y - vy[i]) + h[i];
                    } else {
                        left.push_back(i);
                    }
                    continue;
                }
                if (h[i] == max(H - abs(x - vx[i]) - abs(y - vy[i]), 0LL)) {
                    continue;
                }
                flag = false;
                break;
            }
            if (flag) {
                bool ok = true;
                for (int i = 0; i < left.size(); i++) {
                    if (h[i] == max(H - abs(x - vx[i]) - abs(y - vy[i]), 0LL)) {
                        continue;
                    }
                    ok = false;
                    break;
                }
                if (ok == false)
                    continue;
                cout << x << " " << y << " " << H << endl;
                return 0;
            }
        }
    }
}