#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int h, w;
    cin >> h >> w;
    string field[1100];
    int cnt = 0;
    for (int i = 0; i < h; i++) {
        cin >> field[i];
    }
    vector<pint> v;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (field[y][x] == '#') {
                cnt++;
                v.push_back({y, x});
            }
        }
    }
    int ans = 0;
    vector<pint> nv;
    while (cnt < h * w) {
        ans++;
        for (pint p : v) {
            int y = p.first;
            int x = p.second;
            if (y - 1 >= 0 and field[y - 1][x] == '.') {
                cnt++;
                field[y - 1][x] = '#';
                nv.push_back({y - 1, x});
            }
            if (x - 1 >= 0 and field[y][x - 1] == '.') {
                cnt++;
                field[y][x - 1] = '#';
                nv.push_back({y, x - 1});
            }
            if (y + 1 < h and field[y + 1][x] == '.') {
                cnt++;
                field[y + 1][x] = '#';
                nv.push_back({y + 1, x});
            }
            if (x + 1 < w and field[y][x + 1] == '.') {
                cnt++;
                field[y][x + 1] = '#';
                nv.push_back({y, x + 1});
            }
        }
        v = nv;
        nv.clear();
    }
    cout << ans << endl;
}