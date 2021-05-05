#include <bits/stdc++.h>
using namespace std;

const int N = 210000;
const int inf = 1 << 25;
int n;
vector<int> x(N), y(N);
vector<char> d(N);

void rotate() {
    for (int i = 0; i < n; i++) {
        int cx = y[i], cy = 200000 - x[i];
        char cd;
        if (d[i] == 'U') cd = 'R';
        if (d[i] == 'R') cd = 'D';
        if (d[i] == 'D') cd = 'L';
        if (d[i] == 'L') cd = 'U';
        x[i] = cx, y[i] = cy, d[i] = cd;
    }
}

vector<pair<int, char>> v[2 * N];

int solve1() {
    int res = inf;

    for (int i = 0; i < 2 * N; i++) v[i].clear();
    for (int i = 0; i < n; i++) {
        if (d[i] == 'R' or d[i] == 'U')
            v[x[i] + y[i]].push_back({x[i], d[i]});
    }

    for (int i = 0; i < 2 * N; i++) {
        sort(v[i].begin(), v[i].end());
        for (int j = 0; j + 1 < v[i].size(); j++) {
            if (v[i][j].second == 'R' and v[i][j + 1].second == 'U')
                res = min(res, v[i][j + 1].first - v[i][j].first);
        }
    }

    return res * 10;
}

int solve2() {
    int res = inf;
    for (int i = 0; i < N; i++) v[i].clear();
    for (int i = 0; i < n; i++) {
        if (d[i] == 'L' || d[i] == 'R')
            v[y[i]].push_back({x[i], d[i]});
    }

    for (int i = 0; i < N; i++) {
        sort(v[i].begin(), v[i].end());
        for (int j = 0; j + 1 < v[i].size(); j++) {
            if (v[i][j].second == 'R' and v[i][j + 1].second == 'L')
                res = min(res, v[i][j + 1].first - v[i][j].first);
        }
    }

    return res * 5;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> d[i];

    int ans = inf;

    for (int t = 0; t < 4; t++) {
        ans = min(ans, solve1());
        ans = min(ans, solve2());
        rotate();
    }

    if (ans == inf)
        cout << "SAFE" << endl;
    else
        cout << ans << endl;
}
