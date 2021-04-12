#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
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
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int h, w, k;
    cin >> h >> w >> k;
    string field[330];
    for (int i = 0; i < h; i++) {
        cin >> field[i];
    }
    int data[330][330];
    int now = 0;
    queue<int> yborder;
    for (int y = 0; y < h; y++) {
        bool found = false;
        for (int x = 0; x < w; x++) {
            if (field[y][x] == '#') {
                if (found == false) {
                    yborder.push(y);
                    found = true;
                }
            }
        }
    }
    for (int y = 0; y < h; y++) {
        int nexty;
        now++;
        if (yborder.empty()) {
            nexty = h - 1;
        } else {
            nexty = yborder.front();
            yborder.pop();
            if (yborder.empty())
                nexty = h - 1;
        }
        bool first = false;
        for (int x = 0; x < w; x++) {
            bool found = false;
            for (int ny = y; ny <= nexty; ny++) {
                if (field[ny][x] == '#') {
                    found = true;
                }
            }
            if (first == false and found) {
                first = true;
            } else if (found) {
                now++;
            }
            for (int ny = y; ny <= nexty; ny++) {
                data[ny][x] = now;
            }
        }
        y = nexty;
    }
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cout << data[y][x] << " ";
        }
        cout << endl;
    }
}