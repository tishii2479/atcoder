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
void f(int x1, int y1, int x2, int y2) {
    cout << y1 + 1 << " " << x1 + 1 << " " << y2 + 1 << " " << x2 + 1 << endl;
}
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> sx;
    vector<int> sy;
    for (int y = 0; y < h; y++) {
        bool flag = false;
        for (int x = 0; x + 1 < w; x++) {
            if (a[y][x] % 2 == 0) {
                flag = false;
            } else if (a[y][x] % 2 == 1 and flag == false) {
                flag = true;
            }
            if (flag) {
                a[y][x + 1] += a[y][x];
                sx.push_back(x);
                sx.push_back(x + 1);
                sy.push_back(y);
                sy.push_back(y);
            }
        }
    }
    bool flag = false;
    int x = w - 1;
    for (int y = 0; y + 1 < h; y++) {
        if (a[y][x] % 2 == 0) {
            flag = false;
        } else if (a[y][x] % 2 == 1 and flag == false) {
            flag = true;
        }
        if (flag) {
            a[y + 1][x] += a[y][x];
            sx.push_back(x);
            sx.push_back(x);
            sy.push_back(y);
            sy.push_back(y + 1);
        }
    }
    cout << sx.size() / 2 << endl;
    for (int i = 0; i < sx.size(); i += 2) {
        f(sx[i], sy[i], sx[i + 1], sy[i + 1]);
    }
}