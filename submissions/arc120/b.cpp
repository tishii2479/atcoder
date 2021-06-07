#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

vector<string> s;
int h, w;
int solve(int x, int y) {
    int r_cnt = 0, b_cnt = 0;
    while (x >= 0 and y < h) {
        if (s[y][x] == 'R')
            r_cnt++;
        else if (s[y][x] == 'B')
            b_cnt++;
        x--;
        y++;
    }
    if (r_cnt > 0 and b_cnt > 0) {
        return 0;
    }

    if (r_cnt > 0 or b_cnt > 0) {
        return 1;
    }
    return 2;
}

int main() {
    using mint = modint998244353;
    cin >> h >> w;
    s.resize(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    mint ans = 1;

    for (int i = 0; i < w; i++) {
        int x = i, y = 0;
        ans *= solve(x, y);
    }

    for (int i = 1; i < h; i++) {
        int y = i, x = w - 1;
        ans *= solve(x, y);
    }

    cout << ans.val() << endl;
}
