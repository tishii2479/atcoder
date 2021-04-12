#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
string s[10];
int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> s[i];
    int ans = 0;
    for (int y = 1; y < h; y++) {
        int now = -1;
        for (int x = 0; x < w; x++) {
            if (s[y - 1][x] == '.' and s[y][x] == '#') {
                if (now == -1) {
                    now = x;
                    ans++;
                    continue;
                }
                if (now == x - 1)
                    now = x;
                else
                    ans++, now = x;
            }
        }
    }
    for (int y = 0; y < h - 1; y++) {
        int now = -1;
        for (int x = 0; x < w; x++) {
            if (s[y + 1][x] == '.' and s[y][x] == '#') {
                if (now == -1) {
                    now = x;
                    ans++;
                    continue;
                }
                if (now == x - 1)
                    now = x;
                else
                    ans++, now = x;
            }
        }
    }
    for (int x = 1; x < w; x++) {
        int now = -1;
        for (int y = 0; y < h; y++) {
            if (s[y][x - 1] == '.' and s[y][x] == '#') {
                if (now == -1) {
                    now = y;
                    ans++;
                    continue;
                }
                if (now == y - 1)
                    now = y;
                else
                    ans++, now = y;
            }
        }
    }
    for (int x = 0; x < w - 1; x++) {
        int now = -1;
        for (int y = 0; y < h; y++) {
            if (s[y][x + 1] == '.' and s[y][x] == '#') {
                if (now == -1) {
                    now = y;
                    ans++;
                    continue;
                }
                if (now == y - 1)
                    now = y;
                else
                    ans++, now = y;
            }
        }
    }
    cout << ans << endl;
}