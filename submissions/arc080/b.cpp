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
    int field[110][110];
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    int tmp = 0;
    int now = 0;
    int y = 0, x = 0;
    while (cnt < h * w) {
        if (tmp == 0) {
            tmp = a[now];
            now++;
        }
        field[y][x] = now;
        if (y % 2 == 0) {
            if (x + 1 < w) {
                x++;
            } else {
                y++;
            }
        } else {
            if (x - 1 >= 0) {
                x--;
            } else {
                y++;
            }
        }
        tmp--;
        cnt++;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}