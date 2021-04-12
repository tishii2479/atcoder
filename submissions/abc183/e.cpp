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
char field[2010][2010];
ll sums[2010][2010];
ll leftSum[2010][2010];
ll upSum[2010][2010];
ll upLeftSum[2010][2010];
int main() {
    int h, w;
    cin >> h >> w;
    char c;
    rep(y, h) {
        rep(x, w) {
            cin >> field[y + 1][x + 1];
        }
    }
    sums[1][1] = 1;
    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            if (field[y][x] == '#') {
                sums[y][x] = 0;
                leftSum[y][x] = 0;
                upSum[y][x] = 0;
                upLeftSum[y][x] = 0;
                continue;
            }
            sums[y][x] += leftSum[y][x - 1];
            sums[y][x] %= MOD;
            sums[y][x] += upSum[y - 1][x];
            sums[y][x] %= MOD;
            sums[y][x] += upLeftSum[y - 1][x - 1];
            sums[y][x] %= MOD;
            leftSum[y][x] += sums[y][x] + leftSum[y][x - 1];
            leftSum[y][x] %= MOD;
            upSum[y][x] += sums[y][x] + upSum[y - 1][x];
            upSum[y][x] %= MOD;
            upLeftSum[y][x] += sums[y][x] + upLeftSum[y - 1][x - 1];
            upLeftSum[y][x] %= MOD;
        }
    }
    cout << sums[h][w] << endl;
}