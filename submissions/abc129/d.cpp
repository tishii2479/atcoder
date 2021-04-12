#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
string field[2100];
int upsum[2100][2100];
int downsum[2100][2100];
int rightsum[2100][2100];
int leftsum[2100][2100];
int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> field[i];
    }
    // sita
    for (int x = 0; x < w; x++) {
        int now = 0;
        for (int y = 0; y < h; y++) {
            if (field[y][x] == '#') {
                now = 0;
            } else {
                now++;
            }
            downsum[y][x] = now;
        }
    }
    // ue
    for (int x = 0; x < w; x++) {
        int now = 0;
        for (int y = h - 1; y >= 0; y--) {
            if (field[y][x] == '#') {
                now = 0;
            } else {
                now++;
            }
            upsum[y][x] = now;
        }
    }
    // migi
    for (int y = 0; y < h; y++) {
        int now = 0;
        for (int x = 0; x < w; x++) {
            if (field[y][x] == '#') {
                now = 0;
            } else {
                now++;
            }
            rightsum[y][x] = now;
        }
    }
    // left
    for (int y = 0; y < h; y++) {
        int now = 0;
        for (int x = w - 1; x >= 0; x--) {
            if (field[y][x] == '#') {
                now = 0;
            } else {
                now++;
            }
            leftsum[y][x] = now;
        }
    }
    int ans = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int sum = upsum[y][x] + downsum[y][x] + leftsum[y][x] + rightsum[y][x];
            sum -= 3;
            ans = max(ans, sum);
            // cout << upsum[y][x] << " ";
        }
        // cout << endl;
    }
    cout << ans << endl;
}