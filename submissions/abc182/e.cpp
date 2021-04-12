#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
const int inf = 1 << 29;
int field[1555][1555];
int lit[1555][1555];
int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    int x, y;
    rep(i, n) {
        cin >> x >> y;
        field[x - 1][y - 1] = 1;
    }
    rep(i, m) {
        cin >> x >> y;
        field[x - 1][y - 1] = 2;
    }
    for (y = 0; y < h; y++) {
        int ok = 0;
        for (x = 0; x < w; x++) {
            if (field[y][x] == 1)
                ok = 1;
            if (field[y][x] == 2)
                ok = 0;
            lit[y][x] |= ok;
        }
        ok = 0;
        for (x = w - 1; x >= 0; x--) {
            if (field[y][x] == 1)
                ok = 1;
            if (field[y][x] == 2)
                ok = 0;
            lit[y][x] |= ok;
        }
    }
    // down
    for (x = 0; x < w; x++) {
        int ok = 0;
        for (y = 0; y < h; y++) {
            if (field[y][x] == 1)
                ok = 1;
            if (field[y][x] == 2)
                ok = 0;
            lit[y][x] |= ok;
        }
        ok = 0;
        for (y = h - 1; y >= 0; y--) {
            if (field[y][x] == 1)
                ok = 1;
            if (field[y][x] == 2)
                ok = 0;
            lit[y][x] |= ok;
        }
    }
    ll cnt = 0;
    // count
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cnt += lit[y][x];
        }
    }
    cout << cnt << endl;
}